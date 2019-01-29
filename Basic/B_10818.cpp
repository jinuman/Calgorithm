// 최소, 최대

#include <iostream>
using namespace std;

int main() {
    int n = 0, next = 0;
    int min = 1000000, max = -1000000;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &next);
        min = (next < min) ? next : min;
        max = (next > max) ? next : max;
    }
    printf("%d %d\n", min, max);
    return 0;
}

/*
input
5
20 10 35 30 7

output
7 35
*/