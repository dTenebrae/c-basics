#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 50

void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}

int partition(int *arr, int low, int high)
{
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i + 1], &arr[high]);

        return (i + 1);
}

void quicksort(int *arr, int low, int high)
{
        if (low < high) {
                int pivot = partition(arr, low, high);
                quicksort(arr, low, pivot - 1);
                quicksort(arr, pivot + 1, high);
        }

}

void print_array(int *arr, char* header)
{
        printf("%s: \n", header);
        for (int i = 0; i < ARRAY_LEN; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void check_array(int *arr, int len)
{
        int prev = arr[0];
        for (int i = 1; i < len; i++) {
                if (arr[i] < prev) {
                        printf("Incorrect sorting\n");
                        return;
                }
        }
        printf("Correct sorting\n");
}

int main (int argc, char *argv[])
{
        // seed 
        srand(time(NULL));

        int rand_arr[ARRAY_LEN];

        for (int i = 0; i < ARRAY_LEN; ++i) {
                rand_arr[i] = rand()%20;
        }

        print_array(rand_arr, "Unsorted array");
        check_array(rand_arr, ARRAY_LEN);
        quicksort(rand_arr, 0, ARRAY_LEN - 1);
        print_array(rand_arr, "Sorted array");
        check_array(rand_arr, ARRAY_LEN);

        return 0;
}
