#include <stdio.h>

int main() {
    double a = 1.000E-20;
    double b = 1.23E-4;
    double c = 1.23E-5;

    printf("%E\n%g\n%g\n", a, b, c);
}