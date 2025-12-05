#ifndef math_util
#define math_util

#include <string>
using namespace std;

class Student{
    private:
        string name;
        int age;
    public:
        Student(string name, int age);
        void displayDetails();
};

#endif