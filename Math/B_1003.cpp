// 피보나치 함수

#include <iostream>
using namespace std;

// 1. 재귀 버전
#define __recursive__
#ifndef __recursive__
int zero, one;
int fib(int n) {
    if (n == 0) {
        zero += 1;
        return 0;
    }
    if (n == 1) {
        one += 1;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        zero = 0, one = 0;
        scanf("%d", &n);
        fib(n);
        printf("%d %d\n", zero, one);
    }
    return 0;
}
#else
// 2. DP 버전
int dp[41][2]; // 0이 나오는 개수, 1이 나오는 개수
int main(){
    int T, n;
    scanf("%d", &T);

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 40; i++){
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }
    return 0;
}
#endif
