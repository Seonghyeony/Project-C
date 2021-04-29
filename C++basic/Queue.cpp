#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    queue<int> q;
    q.push(7); q.push(5); q.push(4);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}