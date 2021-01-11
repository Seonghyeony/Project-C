/**
프로그램이 꺼진 이후에도
데이터를 저장하기 위해서는 파일 입출력이 필요하다.

fopen(), fclose()
- r: 읽기
  w: 쓰기(파일이 이미 존재하면 덮어쓰기)
  a: 쓰기(데이터 뒤에서부터 쓰기)

fprintf(파일 포인터, 서식, 형식지정자);
fscanf(파일 포인터, 서식, 형식지정자);

파일 입출력은 열고, 읽고/쓰고, 닫기의 과정을 철저히 따라야 한다.
파일을 열 때는 파일 포인터가 사용되며, 이는 동적으로 할당된 것이다.
따라서 파일 처리 이후에 파일을 닫아주지 않으면 메모리 누수가 발생한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int score;
} Student;

int main(void) {
	/*char s[20] = "Hello World!";
	FILE* fp;
	fp = fopen("temp.txt", "w");
	fprintf(fp, "%s\n", s);
	fclose(fp);*/

	int n, sum = 0;
	FILE* fp;
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("input.txt 파일 오픈 불가\n");    //화면에 오류 표시
		system("pause");
		return 0;
	}
	fscanf(fp, "%d", &n);
	printf("%d\n", n);
	Student* students = (Student*)malloc(sizeof(Student) * n);
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%s %d", &(students + i)->name, &(students + i)->score);
	}
	for (int i = 0; i < n; i++) {
		sum += (students + i)->score;
	}
	free(students);
	fclose(fp);
	printf("점수 평균: %.2f\n", (double)sum / n);
	system("pause");
	return 0;
}