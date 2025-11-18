#include <stdio.h>
#include <stdlib.h>

double_native_sum(const double *a, size_t n) {
    double sum = 0.0;
    for(size_t i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}


int main() {

}