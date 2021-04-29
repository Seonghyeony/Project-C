#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Time {
    friend class Date;  // Date 클래스에서 Time 클래스를 이용할 수 있다.
private:
    int hour, min, sec;
public:
    void setCurrentTime() {
        time_t currentTime = time(NULL);
        struct tm *p = localtime(&currentTime);
        hour = p->tm_hour;
        min = p->tm_min;
        sec = p->tm_sec;
    }
};

class Date {
private:
    int year, month, day;
public:
    Date(int year, int month, int day) : year(year), month(month), day(day) { }
    void show(const Time &t) {
        cout << "지정된 날짜: " << year << "년 " << month << "월 " << day << "일" << endl;
        cout << "현재 시간: " << t.hour << ":" << t.min << ":" << t.sec << endl;    // friend 함수를 사용하면 이렇게 다른 클래스의 private 멤버 함수에 바로 접근 가능.
    }
};

int main(void) {
    Time time;
    time.setCurrentTime();
    Date date = Date(2021, 04, 29);
    date.show(time);
}