#include "Student.h"
#include <iostream>

Student::Student(string name, int age):name(name), age(age){}

void Student::displayDetails(){
    cout << "Name: "<<name<<"\nAge: "<<age<<endl;
}