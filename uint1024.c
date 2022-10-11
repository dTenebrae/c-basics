#include <stdio.h>
#define B_SIZE 309 // number of buffered digits

struct buffer {
        size_t index;
        char data[B_SIZE];
};

void init_buffer(struct buffer *buffer, int n) {
        for (buffer->index = B_SIZE; n; buffer->data[--buffer->index] = (char) (n % 10), n /= 10);
}

void print_buffer(const struct buffer *buffer) {
        for (size_t i = buffer->index; i < B_SIZE; ++i) putchar('0' + buffer->data[i]);
}

void natural_mul_buffer(struct buffer *buffer, const int n) {
        int a, b = 0;
        for (size_t i = (B_SIZE - 1); i >= buffer->index; --i) {
                a = n * buffer->data[i] + b;
                buffer->data[i] = (char) (a % 10);
                b = a / 10;
        }
        for (; b; buffer->data[--buffer->index] = (char) (b % 10), b /= 10);
}

int main() {
        struct buffer number_1 = {0};
        init_buffer(&number_1, 1);
        for (int i = 2; i <= 100; ++i)
                natural_mul_buffer(&number_1, i);
        print_buffer(&number_1);
}
