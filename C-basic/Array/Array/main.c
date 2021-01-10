#include <stdio.h>
#include <limits.h>	// 다양한 자료값들의 최댓값이나 최솟값들을 알 수 있다.

int main(void) {
	int a[10] = { 6, 5, 4, 3, 9, 8, 0, 1, 2, 7 };
	int i, maxValue = INT_MIN;
	for (i = 0; i < 10; i++) {
		if (maxValue < a[i]) maxValue = a[i];
	}
	printf("maxValue: %d\n", maxValue);
	system("pause");
	return 0;
}

