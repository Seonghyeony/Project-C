#include <iostream>
#include <string>
#include <map>

using namespace std;

// set은 원소들 자체가 key로 쓰이고, 정렬된 상태로 있음.
int main(void) {
    map<string, int> m;
    m["임성현"] = 1; m["홍길동"] = 2; m["이순신"] = 3;
    map<string, int>::iterator iter = m.begin();
    for (; iter != m.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl;
    }
    m["이순근"] = 4;
    cout << m["없는 사람"] << endl;
    iter = m.begin();
    for (; iter != m.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl;
    }
}