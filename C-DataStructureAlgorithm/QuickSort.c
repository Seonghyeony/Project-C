#include <stdio.h>
#define SIZE 1000

int a[SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end) {
    if (start >= end) return;
    int pivot = start, i = start + 1, j = end, temp;
    while (i <= j) {    // 엇갈릴 때까지 반복합니다.
        while (i <= end && a[i] <= a[pivot]) i++;   // pivot 보다 큰 값이 i에 담긴다.
        while (j > start && a[j] >= a[pivot]) j--;
        if (i > j) swap(&a[pivot], &a[j]);
        else swap(&a[i], &a[j]);
    }
    quickSort(start, j - 1);
    quickSort(j + 1, end);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}