#include <iostream>
#include <string>

using namespace std;

template <typename T>
// 자료형에 구애받지 않고 함수의 기능적인 동작을 정의 가능.
void change(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 명시적 특수화
template <>
void change<int>(int& a, int& b) {
    cout << "정수형 데이터를 교체합니다." << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int a = 5;
    int b = 7;
    change(a, b);   // string 변수를 넣으면 자동적으로 typename이 string으로 됨.
                    // 전체 변수가 string으로 됨.
    cout << a << ":" << b << endl;
}