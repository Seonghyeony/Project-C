#include <stdio.h>
#define MAX_VALUE 10001     // 상당히 많은 메모리를 낭비하므로 크기 제한이 있어야 한다.
                            // 하지만 퀵 정렬이나 다른 것들 보다 빠르다.
int n, m;
int a[MAX_VALUE];

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        a[m]++;
    }
    for (int i = 0; i < MAX_VALUE; i++) {
        while (a[i] != 0) {
            printf("%d ", i);
            a[i]--;
        }
    }
    return 0;
}