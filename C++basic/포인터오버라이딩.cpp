#include <iostream>

using namespace std;

class A {
public:
    // virtual void show() { cout << "A 클래스 입니다." << endl; }
    virtual void show() = 0;   // '=0' 순수 가상 함수.
};

class B : public A {
public:
    // 순수 가상 함수는 자식 클래스에서 반드시 재정의 해주어야 함.
    virtual void show() { cout << "B 클래스 입니다." << endl; }
};

int main(void) {
    A* p;
    // A a;
    B b;
    // p = &a; p->show();
    p = &b; p->show();  // 여전히 A 클래스의 show() 함수를 호출한다.
                        // p 포인터가 A 타입이므로 A 함수를 호출한다.
                        // virtual 함수를 사용하여 해결 가능.(동적 바인딩)
}