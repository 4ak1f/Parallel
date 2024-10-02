#include <stdio.h>
#include <omp.h>

int main() {
    int n, i;
    double pi = 3.0;
    
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    #pragma omp parallel for reduction(+:pi)
    for (i = 1; i <= n; i++) {
        double term = 4.0 / ((2.0 * i) * (2.0 * i + 1) * (2.0 * i + 2));
        if (i % 2 == 0)
            pi -= term;
        else
            pi += term;
    }

    printf("Approximation of Pi: %.15f\n", pi);
    return 0;
}
