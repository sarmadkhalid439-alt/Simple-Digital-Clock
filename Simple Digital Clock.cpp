#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Clock {
private:
    int hour, minute, second;

public:
    // Constructor
    Clock(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    // دالة لعرض الوقت
    void showTime() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }

    // دالة لزيادة الوقت بثانية واحدة
    void tick() {
        second++;
        if (second == 60) {
            second = 0;
            minute++;
        }
        if (minute == 60) {
            minute = 0;
            hour++;
        }
        if (hour == 24)
            hour = 0;
    }
};

int main() {
    Clock c(12, 59, 55); // يبدأ الوقت من 12:59:55

    cout << "🕒 Simple Digital Clock\n" << endl;

    for (int i = 0; i < 10; i++) { // عرض 10 ثواني فقط
        c.showTime();
        this_thread::sleep_for(chrono::seconds(1));
        c.tick();
    }

    return 0;
}