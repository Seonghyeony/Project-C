#include <stdio.h>

//struct Student {
//	char studentId[10];
//	char name[10];
//	int grade;
//	char major[100];
//};	//s;	// ���� �ϳ��� ����ü ������ ����� �� ��, ���������� ����� ��,
//		// �̷��� ���Ǹ� �� �� ������ �ٷ� �� �� �ִ�.

// typedef Ű���带 ����ϸ� �����ϰ� ��밡��
typedef struct {
	char studentId[10];
	char name[10];
	int grade;
	char major[100];
} Student;

int main(void) {
	// �̷��� �ѹ��� �ʱ�ȭ ����.(�� ������� �ؾ���!)
	// struct Student s = {"201512789", "�Ӽ���", 5, "��ǻ�Ͱ��а�"}
	// struct Student s;
	Student *s = malloc(sizeof(Student));
	strcpy(s->studentId, "201512789");
	strcpy(s->name, "�Ӽ���");
	s->grade = 4;
	strcpy(s->major, "��ǻ�Ͱ��а�");
	printf("�й�: %s\n", s->studentId);
	printf("�̸�: %s\n", s->name);
	printf("�г�: %d\n", s->grade);
	printf("�а�: %s\n", s->major);

	return 0;
}