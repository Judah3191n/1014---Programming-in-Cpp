#include "geometry.h"


double area(double width, double height){
    if (width>0&&height>0){
        return width*height;
    }
    return -1;
}

double perimeter(double width, double height){
    return 2*(width + height);
}
