/*
#include <stdio.h>
1) 이와 같이 선언하면 시스템 디렉토리에서 파일을 검색.
2) 운영체제마다 시스템 디렉토리가 존재하는 경로가 다를 수 있다.
3) 대표적으로 stdio.h와 같은 헤더파일 등이 시스템 디렉토리에 존재한다.

#include "파일이름"
1) 이와 같이 선언하면 현재 폴더에서 파일을 먼저 검색한다.
2) 만약 현재 폴더에 파일이 없다면 시스템 디렉토리에서 파일을 검색한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "temp.h"
#include "temp.h"	// 조건부 컴파일 기법을 사용했기 때문에 오류를 잡아준다.


#define PI 3.1415926535
#define POW(x) (x * x)

#define ll long long
#define ld long double

int main(void) {
	printf("%d\n", add(10, 3));
	int r = 10;
	printf("원의 둘레: %.2f\n", 2 * PI * r);

	int x = 10;
	printf("x의 제곱: %d\n", POW(x));

	ll a = 98654321000;
	ld b = 100.5054;
	printf("%.1f\n", a * b);
	system("pause");
	return 0;
}