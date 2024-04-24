#include <stdio.h>

// x^n을 계산하는 함수
double power(double x, int n) {
    printf("호출됨: %lf %d\n", x, n);
    if (n == 0) {
        return 1; // 기저 조건: 어떤 수의 0제곱은 1
    } else if (n % 2 == 0) {
        return power(x * x, n / 2); // n이 짝수일 때
    } else {
        return x * power(x * x, (n - 1) / 2); // n이 홀수일 때
    }
}

int main(void) {
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    printf("결과: %lf\n", power(x, n));
    return 0;
}
 