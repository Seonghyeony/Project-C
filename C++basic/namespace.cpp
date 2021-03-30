#include <iostream>

using namespace std;

namespace A {
    void function() {
        cout << "A Namespace" << endl;
    }
}

namespace B
{
    void function() {
        cout << "B Namespace" << endl;
    }
} // namespace B

int main(void) {
    A::function();
    B::function();
}