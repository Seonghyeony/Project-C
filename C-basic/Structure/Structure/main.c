#include <stdio.h>

//struct Student {
//	char studentId[10];
//	char name[10];
//	int grade;
//	char major[100];
//};	//s;	// 오직 하나의 구조체 변수만 사용이 될 때, 전역변수로 사용할 때,
//		// 이렇게 정의를 한 뒤 선언을 바로 할 수 있다.

// typedef 키워드를 사용하면 간결하게 사용가능
typedef struct {
	char studentId[10];
	char name[10];
	int grade;
	char major[100];
} Student;

int main(void) {
	// 이렇게 한번에 초기화 가능.(꼭 순서대로 해야함!)
	// struct Student s = {"201512789", "임성현", 5, "컴퓨터공학과"}
	// struct Student s;
	Student *s = malloc(sizeof(Student));
	strcpy(s->studentId, "201512789");
	strcpy(s->name, "임성현");
	s->grade = 4;
	strcpy(s->major, "컴퓨터공학과");
	printf("학번: %s\n", s->studentId);
	printf("이름: %s\n", s->name);
	printf("학년: %d\n", s->grade);
	printf("학과: %s\n", s->major);

	return 0;
}