#include <iostream>
#include <string>

using namespace std;

class Temp {
public:
    void showTemp() {
        cout << "임시 부모 클래스입니다." << endl;
    }
};

class Person {
private:
    string name;
public:
    Person(string name) : name(name) { }
    string getName() {
        return name;
    }
    void showName() {
        cout << "이름: " << getName() << endl;
    }
};

class Student : Person, public Temp {   // public 클래스를 꼭 사용해야함.
private:
    int studentID;
    // 멤버 변수 name은 Person으로부터 물려 받음.
public:
    Student(int studentID, string name) : Person(name) {
        this->studentID = studentID;
    }
    void show() {
        cout << "학생 번호: " << studentID << endl;
        cout << "학생 이름: " << getName() << endl;
    }

    // 오버라이딩. 동일한 이름. 동일한 매개변수를 가짐.
    void showName() {
        cout << "학생 이름: " << getName() << endl;
    }
};

int main(void) {
    Student student(1, "임성현");
    student.showName();
    student.showTemp();
}