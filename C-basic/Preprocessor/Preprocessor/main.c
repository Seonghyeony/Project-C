/*
#include <stdio.h>
1) �̿� ���� �����ϸ� �ý��� ���丮���� ������ �˻�.
2) �ü������ �ý��� ���丮�� �����ϴ� ��ΰ� �ٸ� �� �ִ�.
3) ��ǥ������ stdio.h�� ���� ������� ���� �ý��� ���丮�� �����Ѵ�.

#include "�����̸�"
1) �̿� ���� �����ϸ� ���� �������� ������ ���� �˻��Ѵ�.
2) ���� ���� ������ ������ ���ٸ� �ý��� ���丮���� ������ �˻��Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "temp.h"
#include "temp.h"	// ���Ǻ� ������ ����� ����߱� ������ ������ ����ش�.


#define PI 3.1415926535
#define POW(x) (x * x)

#define ll long long
#define ld long double

int main(void) {
	printf("%d\n", add(10, 3));
	int r = 10;
	printf("���� �ѷ�: %.2f\n", 2 * PI * r);

	int x = 10;
	printf("x�� ����: %d\n", POW(x));

	ll a = 98654321000;
	ld b = 100.5054;
	printf("%.1f\n", a * b);
	system("pause");
	return 0;
}