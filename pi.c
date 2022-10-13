#include <stdio.h>
#include <math.h>
#define MAX_ITER 1000000000
#define N 1E-9

int main (int argc, char *argv[])
{
        int i = 0;
        int denom = 1;
        double pi = 4.0;
        double prev_pi = 5.0;

        double error;

        do {
                denom += 2;
                pi += (i % 2) ? (4.0 / denom) : (-1.0) * (4.0 / denom);
                error = fabs(prev_pi - pi);
                i++;
                prev_pi = pi;
                
        } while(i < MAX_ITER && error > N);

        printf("Iterations: %d\n", i);
        printf("pi: %.17g\n", pi);
        
        return 0;
}
