#include <stdio.h>

int main(void) {
	int a[2][5] = { { 1, 2, 3, 4, 5 },
					{ 6, 7, 8, 9, 10 } };
	// int *b = &a[0];
	// int* b = a;
	// printf("%d\n", b[2]);
	/*int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", *(a + i));
	}  */
	/*int *p = a;
	printf("%d\n", *(p++));
	printf("%d\n", *(++p));
	printf("%d\n", *(p + 2));
	system("pause");*/

	int(*p)[5] = a[1];
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", p[0][i]);
	}

	return 0;
}