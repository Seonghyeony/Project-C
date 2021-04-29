#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    int* arr = new int[10];
    arr[7] = 100;
    shared_ptr<int> p1(arr);
    cout << p1.use_count() << endl; // 1
    shared_ptr<int> p2(p1);
    cout << p1.use_count() << endl; // 2
    shared_ptr<int> p3 = p2;
    cout << p1.use_count() << endl; // 3
    p1.reset();
    p2.reset();
    cout << "arr[7]: " << arr[7] << endl;
    p3.reset();
    cout << p1.use_count() << endl;
    cout << "arr[7]: " << arr[7] << endl;
}