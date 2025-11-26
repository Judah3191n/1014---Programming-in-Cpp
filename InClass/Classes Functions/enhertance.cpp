#include <iostream>
#include <vector>
using namespace std;

////enheriting same attrubute from 2 sides error
// class Animal {
//     protected:
//         int numberOfLegs =3;
//     public:
//         void fly(){
//             cout << "Flying with "<<numberOfLegs<<" legs."<<endl;
//         }
// };

// class Eagle: virtual public Animal{
//     public: 
//         void setEagleLegs(){
//             numberOfLegs = 2;
//         }
// };
// class Lion: virtual public Animal{
//     public: 
//     void setLionLegs(){
//         numberOfLegs = 4;
//     }
// };
// class Griffin : public Eagle, public Lion{
//     void work(){
//         cout << "Working"<<endl;
//     }
// };


class Box{
    public:
        double width,height,depth;
        Box (double w, double h, double d): width(w), height(h), depth(d){}

        //Overload + operator
        Box operator+(const Box& other){
            double newWidth = width + other.width;
            double newHeight = height + other.height;
            double newDepth = depth + other.depth;
            return Box (newWidth,newHeight, newDepth);
        }
        Box operator-(const Box& other){
            double newWidth = width - other.width;
            double newHeight = height - other.height;
            double newDepth = depth - other.depth;
            return Box (newWidth,newHeight, newDepth);
        }
        
        bool operator== (const Box& other){
            return (width==other.width)&&(height==other.height)&&(depth==other.depth);
        }

        void displayBox(){
            cout << "Width: "<<width<<", Height: "<<height<< ", Depth: "<<depth<<endl;
        }
        ~Box(){}
    
};

ostream operator<< (ostream& os, const Box& box){
    cout << "Width: "<<box.width<<", Height: "<<box.height<< ", Depth: "<<box.depth<<endl;
};

int main(){
    Box A(2,3,4);
    Box B(3,2,1);
    Box C = A+B;
    C.displayBox();

    Box a = C-B;
    a.displayBox();
    cout <<"equal?: "<< (A==B) << endl;
    cout << A;
    return 1;
}