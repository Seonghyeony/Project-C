#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    stack<int> s;
    s.push(7); s.push(5); s.push(4);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}