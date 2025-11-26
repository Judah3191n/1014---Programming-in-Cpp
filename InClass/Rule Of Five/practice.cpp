#include <iostream>

using namespace std;


class Practice5{
    int* a;
    int* b;

    public:
        Practice5(int c, int d) : a(new int(c)), b(new int(d)){}

        ~Practice5(){
            delete a,b;
        }

        Practice5(const Practice5& other){
            //deep copy
            a = new int(*other.a);
            b = new int(*other.b);
        }

        Practice5& operator=(const Practice5& other){
            //if left object not equal to right object [a] != b
            if(this != &other){
                //remove left side data [a]=b
                delete a,b;

                //deep copy of data [a].data = b.data
                a = new int(*other.a);
                b = new int(*other.b);
            }

            return *this;
        }

        Practice5(Practice5&& other) noexcept{
            a = other.a;
            b = other.b;
            other.a = nullptr;
            other.b = nullptr;
        }


        Practice5& operator=(Practice5&& other) noexcept{
            if(this != &other){
                delete a,b;
                a = other.a;
                b = other.b;

                other.a = nullptr;
                other.b = nullptr;
            }
            return *this;
        }

        void print(){
            cout << "Value a: "<<*a<<", Value b: "<<*b<<endl;
        }





};

int main(){
    Practice5 test1(4,2);
    cout << "test1 -> ";
    test1.print();




    //function 2 - copy constructor
    Practice5 test2(test1);
    cout << "test2 -> ";
    test2.print();

    //Function 3 - Overloading = operator
    Practice5 test3(0,0);
    test3 = test1;
    cout << "test3 -> ";
    test3.print();

    //function 4 - move constructor
    Practice5 test4 = move(test1);
    cout << "test4 -> ";
    test4.print();

    //function 5 - move assignment
    Practice5 test5(0,0);
    test5 = (Practice5&&)test1;
    cout << "test5 -> ";
    test4.print();


    return 0;
}
