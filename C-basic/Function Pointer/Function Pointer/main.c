#include <stdio.h>

// �Ű����� �� ��ȯ �ڷ����� ���� �Լ� ������
void myFunction() {
	printf("It's my function.\n");
}
void yourFunction() {
	printf("It's your function. \n");
}

// �Ű����� �� ��ȯ �ڷ����� �ִ� �Լ� ������
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}

// �Լ� �����͸� ��ȯ�Ͽ� ����ϱ�
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

	printf("%d\n", process("10�� 20�� ���غ��ڽ��ϴ�.\n")(10, 20));
	return 0;
}