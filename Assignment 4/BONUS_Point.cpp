#include "BONUS_POINT.h"
#include <string>
#include <iostream>

using namespace std;

Label::Label(string label):label(label){}
void Label::displayLabel(){
    cout << "Label: "<<label<<endl;
}

Colour::Colour(string colour):colour(colour){}
void Colour::displayColour(){
    cout<<"Colour: "<<colour<<endl;
}    



Point::Point(double x, double y):x(x),y(y){}
void Point::displayPoint(){
    cout << "("<<x<<", "<<y<<")"<<endl;
}
bool Point::operator==(const Point& other){
    return (x==other.x)&&(y==other.y);
}



LabeledPoint::LabeledPoint(double x, double y, string colour, string label) : Point(x,y), Label(label), Colour(colour){}

void LabeledPoint::displayLabeledPoint(){
    cout << colour<<" point "<<label<<"("<<x<<", "<<y<<")"<<endl;
}

