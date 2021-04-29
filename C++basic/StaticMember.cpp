#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    const int id;   // 변경 불가한 상수 멤버.
    string name;
public:
    static int count;
    Person(int id, string name) : id(id), name(name) {
        count++;
    }
};

int Person::count = 0;

int main(void) {
    Person p1(1, "임성현");
    Person p2(2, "홍길동");
    Person p3(3, "이순신");
    cout << "사람의 수: " << Person::count << endl;
}