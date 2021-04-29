#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<int> d;
    d.push_front(3); d.push_back(7); d.push_front(4);
    for (int i = 0; i < d.size(); i++) { cout << d[i] << ' '; }
    cout << endl;
    deque<int>::iterator iter;  // 시퀀스 컨테이너는 iterator로 각 원소 접근 가능.
    iter = d.begin();
    d.insert(iter+1, 3, 5);
    iter = d.begin();
    d.insert(iter+1, 1, 9);
    for (int i = 0; i < d.size(); i++) { cout << d[i] << ' '; }
    cout << endl;
    d.clear();
    cout << d.empty() << endl;
}