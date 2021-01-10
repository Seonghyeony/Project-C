#include <stdio.h>

// 매개변수 및 반환 자료형이 없는 함수 포인터
void myFunction() {
	printf("It's my function.\n");
}
void yourFunction() {
	printf("It's your function. \n");
}

// 매개변수 및 반환 자료형이 있는 함수 포인터
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}

// 함수 포인터를 반환하여 사용하기
int(*process(char* a))(int, int) {
	printf("%s\n", a);
	return add;
}

int main(void) {
	/*printf("%d\n", function);*/

	/*void(*fp)() = myFunction;
	fp();
	fp = yourFunction;
	fp();*/

	/*int(*fp)(int, int) = add;
	printf("%d\n", fp(10, 3));
	fp = sub;
	printf("%d\n", fp(10, 3));*/

	printf("%d\n", process("10과 20을 더해보겠습니다.\n")(10, 20));
	return 0;
}