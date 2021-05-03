#include <iostream>
#include <set>

using namespace std;

// set은 원소들 자체가 key로 쓰이고, 정렬된 상태로 있음.
int main(void) {
    int array[5] = { 2, 4, 6, 8, 10 };
    set<int> s(array, array + 5);
    set<int>::iterator iter = s.begin();
    for (; iter != s.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    iter = s.begin();
    for (; iter != s.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
}