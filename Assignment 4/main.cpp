#include <iostream>
#include "Student.h"
using namespace std;

//Part 1
class Rectangle{
    private:
        double length;
        double width;
    public:
        Rectangle(double w, double l):length(l), width(w){};
        double area(){
            return length*width;
        }
        double perimeter(){
            return 2*(length+width);
        }
};

//Part 2
class Shape{
    protected:
        void displayShape(){
            cout << "This is a shape"<<endl;
        }
};

class Colour{
    protected:
        void displayColour(){
            cout << "Colour: Red" <<endl;
        }
};

class ColouredShape : Colour, Shape {
    public:
        void displayDetails(){
            displayColour();
            displayShape();
        }
};

//Part 3
class Point{
    private:
        double x;
        double y;
    public:
        Point(double x, double y): x(x), y(y){}

        Point operator+(const Point& other){
            double newX = x + other.x;
            double newY = y + other.y;

            return Point(newX, newY);
        }

        void displayPoint(){
            cout << "("<<x<<", "<<y<<")"<<endl;
        }

};




int main(){
    //Part 1
    cout << "============Part 1============"<<endl;
    Rectangle r1 = Rectangle(10,12.2);
    cout << r1.area() << endl;
    cout << r1.perimeter() << endl;

    //Part 2
    cout << "============Part 2============"<<endl;
    ColouredShape CS;
    CS.displayDetails();


    //Part 3
    cout << "============Part 3============"<<endl;
    Point p1 = Point(1,2);
    Point p2 = Point(4,5);
    Point p3 = p1+p2;
    p3.displayPoint();


    //Part 4
    cout << "============Part 4============"<<endl;
    Student s1 = Student("Judah", 19);
    s1.displayDetails();

    return 0;
}
