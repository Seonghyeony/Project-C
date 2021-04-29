#include <iostream>
#include <string>

using namespace std;

template <typename T = int> // T = int ; 디폴트 템플릿 인수
class Data {
private:
    T data;
public:
    Data(T data) : data(data) { }
    void setData(T data) { this->data = data; }
    T getData() { return data; }
};

int main(void) {
    Data<> data1(1);
    Data<string> data2("임성현");
    cout << data1.getData() << ":" << data2.getData() << endl;
}