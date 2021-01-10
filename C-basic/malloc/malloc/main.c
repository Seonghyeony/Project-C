#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	/*int *a = malloc(sizeof(int));
	printf("%d\n", a);
	free(a);
	a = malloc(sizeof(int));
	printf("%d\n", a);
	free(a);*/
	/*char* a = malloc(100);
	memset(a, 'A', 100);
	for (int i = 0; i < 100; i++) {
		printf("%c ", a[i]);
	}*/
	int** p = (int**)malloc(sizeof(int*) * 3);	// 총 3개의 행을 가리키는 포인터
	for (int i = 0; i < 3; i++) {
		*(p + i) = (int*)malloc(sizeof(int) * 3);	// 각각의 행은 3개의 열로 구정
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// *(p + i) + j: 특정 행에서 몇 번째 열인지.
			// *(*(p + i) + j): 그 위치에 있는 값
			*(*(p + i) + j) = i * 3 + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// *(p + i) + j: 특정 행에서 몇 번째 열인지.
			// *(*(p + i) + j): 그 위치에 있는 값
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
	return 0;
}