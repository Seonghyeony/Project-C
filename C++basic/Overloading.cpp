#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
public:
    Person() { name = "임꺽정"; }
    // 오버로딩. 매개변수가 다름.
    Person(string name) : name(name) { }
    // 연산자 오버로딩
    Person operator+(const Person& other) { return Person(name + " & " + other.name); }
    void showName() { cout << "이름: " << name << endl; }
};

int main(void) {
    Person person1;
    Person person2("임성현");
    Person result = person1 + person2;
    result.showName();
}