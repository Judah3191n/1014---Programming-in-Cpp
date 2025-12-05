#include <iostream>
#include "BONUS_Point.h"

using namespace std;

int main(){
    //Part 5
    cout << "============Part 5============"<<endl;
    LabeledPoint p(1,2,"Red","Judah");
    LabeledPoint p1(1,3,"Green","Judah");

    //points are equal tho label and colour are not
    //because ==operator is in the point class
    cout << (p1==p) <<endl;
    p.displayLabeledPoint();
    p1.displayLabeledPoint();

    return 0;
}
