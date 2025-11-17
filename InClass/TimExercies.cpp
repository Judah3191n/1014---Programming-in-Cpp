#include <iostream>
#include <vector>
using namespace std;


class Time{
    public:
        int hours,minutes;
        Time(int h, int m): hours(h), minutes(m) {};

        Time operator+(const Time& time){
            int newHour = hours+time.hours;
            int newMinute = minutes+time.minutes;
            return Time(newHour,newMinute);
        }

        void print(){
            cout << "Hour: "<<hours<<", Minute: "<<minutes<<endl;
        }
};

int main(){
    Time a(10,21);
    Time b(8,30);
    Time c = a+b;

    c.print();

    return 1;
}