#ifndef math_util
#define math_util

#include <string>
using namespace std;

class Label{
    protected:
        string label;

    public:
        Label(string label);
        void displayLabel();
};

class Colour{
    protected:
        string colour;
    public:
        Colour(string colour);
        void displayColour();    
};

class Point{
    protected: 
        double x,y;
    public:
        Point(double x, double y);
        void displayPoint();
        bool operator==(const Point& other);
};

class LabeledPoint : public Label, public Colour, public Point{

    public:
        LabeledPoint(double x, double y, string colour, string label);
        void displayLabeledPoint();
};

#endif