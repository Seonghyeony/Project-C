#include <iostream>
#include <string>

using namespace std;

class Character {
private:
    string name;
    int ragePoint;
    int hp;
    int damage;
public:
    // 생성자를 간략히 표현하는 방법
    Character(string name, int hp, int damage) : name(name), ragePoint(0), hp(hp), damage(damage) { }
    // 복사 생성자 (깊은 복사)
    Character(const Character& other) {
        name = other.name;
        ragePoint = other.ragePoint;
        hp = other.hp;
        damage = other.damage;
    }
    // 소멸자 '~' 이용.
    ~Character() {
        cout << "[객체가 소멸됩니다.]\n";
    }
    void pointUp() { ragePoint++; }
    void show() {
        cout << name << "[" << ragePoint << "]" << hp << " " << damage << endl;
    }
};

int main(void) {
    Character* character1 = new Character("슬라임", 10, 20);
    character1->pointUp();
    Character character2(*character1);
    character2.pointUp();
    character1->show();
    character2.show();

    delete character1;  // 동적 할당을 이용했으므로 성공적으로 소멸됨.
    delete &character2; // 동적 할당을 이용하지 않았으므로 오류가 발생.
    return 0;
}
