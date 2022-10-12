#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000000000

double x_2(double x)
{
        return x * x;
}

double derive(double (*f)(double), double x, double eps)
{
        double error, prev, current, delta, alpha;
        int i = 0;

        delta = 1.0;
        alpha = 0.00001;

        prev = ((*f)(x + delta) - (*f)(x)) / delta;

        do {
                delta -= alpha;
                current = ((*f)(x + delta) - (*f)(x)) / delta;
                error = fabs(current - prev);
                prev = current;
                i++;
        
        } while (error > eps && i <= MAX_ITER && delta > 0);

        printf("Number of iteration: %d\n", i);
        printf("Epsilon: %.17g\n", eps);

        return current;
}

int main (int argc, char *argv[])
{
        if (argc > 1){
                double num = atof(argv[1]);
                printf("%.10g\n", derive(x_2, num, 1E-9));
        }
        return 0;
}
