#include <stdio.h>
#include <math.h>
#define MAX_ITER 1000000000
#define PRECISION 1E-5
#define PI_CONST 3.14159265358979323846264338327950288419716939937510

void winter_pi(void)
{
        int a = 10000;
        int b,d,e,g;
        int c=2800;
        int f[2801];
        for(;b-c;)
                f[b++]=a/5;
        for(;d=0,g=c*2;c-=14, printf("%.4d",e+d/a),e=d%a)
                for(b=c;d+=f[b]*a, f[b]=d%--g,d/=g--,--b;d*=b);

}

double series_pi(void)
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
                
        } while(i < MAX_ITER && error > PRECISION);

        return pi;

}

int main (int argc, char *argv[])
{

        printf("pi: %.17g\n", series_pi());
        winter_pi();
        
        return 0;
}
