#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int englishScore;
    int mathScore;
    int getSum() {
        return englishScore + mathScore;    // 정보 은닉
    }
public:
    // 생성자.
    Student(string name, int englishScore, int mathScore) {
        this->name = name;  // 자기 자신의 멤버 변수에 접근
        this->englishScore = englishScore;
        this->mathScore = mathScore;
    }
    void show() {
        cout << name << " : [합계 " << getSum() << "점]\n";
    }
};

int main(void) {
    Student a = Student("임성현", 100, 98);
    a.show();
    // a.getSum(); 외부에서 접근 불가.
}