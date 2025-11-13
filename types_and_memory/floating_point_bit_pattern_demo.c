#include <stdio.h>

void print_bytes(void *ptr, size_t size) {
    unsigned char *p = ptr;
    for (size_t i = 0; i < size; i++)
        printf("%02X ", p[i]);
    printf("\n");
}

int main() {
    float f = 0.1f;
    double d = 0.1;
    long double ld = 0.1L;

    printf("float bytes: ");
    print_bytes(&f, sizeof(f));

    printf("double bytes: ");
    print_bytes(&d, sizeof(d));

    printf("long double bytes: ");
    print_bytes(&ld, sizeof(ld));
}