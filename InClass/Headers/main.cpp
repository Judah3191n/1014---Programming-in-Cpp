#include <iostream>
#include "geometry.h"
using namespace std;

int main(){
    double width,height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter Height: ";
    cin >> height;

    cout << "\n-------Results-------" <<endl;
    cout << "Area: "<< area(width,height) << endl;
    cout << "Perimeter: " << perimeter(width,height) <<endl;
    return 1;
}