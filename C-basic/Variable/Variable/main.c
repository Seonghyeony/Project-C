#include <stdio.h>

//void process() {
//	static int a = 5;
//	a = a + 1;
//	printf("%d\n", a);
//}

void add(int* a) {
	(*a) = (*a) + 10;
}

int main(void) {
	/*process();
	process();
	process();
	process();*/
	register int a = 10, i;
	for (i = 0; i < a; i++) {
		printf("%d ", i);
	}
	printf("\n");
	int b = 7;
	add(&b);
	printf("%d\n", b);

	system("pause");
	return 0;
}