#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2;
    cout << *p1 << endl;
    cout << "스마트 포인터 1: " << p1 << endl;
    cout << "스마트 포인터 2: " << p2 << endl;
    cout << "--- 소유권 이전 ---" << endl;
    p2 = move(p1);  // 소유권 이전
    cout << "스마트 포인터 1: " << p1 << endl;
    cout << "스마트 포인터 2: " << p2 << endl;
    cout << "--- 메모리 할당 해제 ---" << endl;
    p2.reset();     // 메모리 할당 해제
    cout << "스마트 포인터 1: " << p1 << endl;
    cout << "스마트 포인터 2: " << p2 << endl;
}