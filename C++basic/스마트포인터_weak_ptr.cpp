#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    int* arr = new int(1);
    shared_ptr<int> sp1(arr);
    weak_ptr<int> wp = sp1; // wp는 참조 횟수 계산에서 제외.
    cout << sp1.use_count() << endl;        // 1로 동일.
    cout << wp.use_count() << endl;
    if (true) {
        shared_ptr<int> sp2 = wp.lock();    // shared_ptr 포인터 반환
        cout << sp1.use_count() << endl;
        cout << wp.use_count() << endl;
    }
    // Scope를 벗어나므로 sp2가 해제됨.
    cout << sp1.use_count() << endl;        // 1로 동일.
    cout << wp.use_count() << endl;
}