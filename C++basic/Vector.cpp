#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v;
    v.push_back(3); v.push_back(7); v.push_back(4);
    for (int i = 0; i < v.size(); i++) { cout << v[i] << ' '; }
    cout << endl;
    vector<int>::iterator iter;  // 시퀀스 컨테이너는 iterator로 각 원소 접근 가능.
    iter = v.begin();
    v.insert(iter+1, 3, 5);
    iter = v.begin();
    v.insert(iter+1, 1, 9);
    for (int i = 0; i < v.size(); i++) { cout << v[i] << ' '; }
    cout << endl;
    v.clear();
    cout << v.empty() << endl;
}