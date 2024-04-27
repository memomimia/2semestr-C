#include <stdio.h>
#include <math.h>
#define E 0.001
double recursion(int n, double x) {
    if (fabs(x) < 1) {
        double result = pow(-1, n-1) * pow(x, n) / n;
        if (fabs(result) <= E) {
            return 0;
        }
        return result + recursion(n+1, x);
    }
    return 0;
}

int main() {
    double x = 0.4; 
    
    double result = recursion(1, x);
    printf("Результат‚: %.6f\n", result);

    return 0;
}
