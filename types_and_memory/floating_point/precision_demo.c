#include <stdio.h>

/*
  실험 목적:
  - float, double, long double의 정밀도 차이를
    '반복적인 누적 연산'을 통해 관찰한다.

  관찰 포인트:
  1) float는 소수점 6~7자리 정확도 → 누적 오차가 가장 크게 나타남
  2) double은 약 15자리 → float보다 오차가 덜 누적됨
  3) ARM64(macOS)의 long double은 double과 동일하게 동작함
     (즉, x86-64에서처럼 확장정밀도가 아님)

  실행 후 출력값의 차이를 비교해보는 것이 핵심이다.
*/

int main(void) {
    float f = 0.0f;
    double d = 0.0;
    long double ld = 0.0L;  // ARM64에서는 double과 동일한 8바이트

    for (int i = 0; i < 100; i++) {
        f  += 0.01f;
        d  += 0.01;
        ld += 0.01L;
    }

    printf("float       : %.20f\n", f);
    printf("double      : %.20lf\n", d);
    printf("long double : %.20Lf\n", ld);

    return 0;
}