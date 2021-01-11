/**
���α׷��� ���� ���Ŀ���
�����͸� �����ϱ� ���ؼ��� ���� ������� �ʿ��ϴ�.

fopen(), fclose()
- r: �б�
  w: ����(������ �̹� �����ϸ� �����)
  a: ����(������ �ڿ������� ����)

fprintf(���� ������, ����, ����������);
fscanf(���� ������, ����, ����������);

���� ������� ����, �а�/����, �ݱ��� ������ ö���� ����� �Ѵ�.
������ �� ���� ���� �����Ͱ� ���Ǹ�, �̴� �������� �Ҵ�� ���̴�.
���� ���� ó�� ���Ŀ� ������ �ݾ����� ������ �޸� ������ �߻��Ѵ�.
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
		printf("input.txt ���� ���� �Ұ�\n");    //ȭ�鿡 ���� ǥ��
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
	printf("���� ���: %.2f\n", (double)sum / n);
	system("pause");
	return 0;
}