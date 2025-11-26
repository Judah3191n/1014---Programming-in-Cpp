#include <iostream>


using namespace std;

class Resource {
    //created int pointer
    int* data;


    public:
    //Regular Constructor
        Resource(int value) : data(new int(value)){}
        // Resource(int value){
        //     data = new int(value);
        // }



    //Deconstructor
        //Rule of 5 - Function 1
        ~Resource(){
            //delete pointer
            delete data;
        }
    
    //Constructor
        //Rule of 5 - Function 2
        Resource(const Resource& other){
            //deep copy
            data = new int(*other.data);
        }

    //Copy Assignment Operator
        //Rule of 5 - Function 3
        Resource& operator=(const Resource& other){
            //if left object not equal to right object [a] != b
            if(this != &other){
                //remove left side data [a]=b
                delete data;

                //deep copy of data [a].data = b.data
                data = new int(*other.data);
            }

            return *this;
        }

    //Copy Constructor
        //Rule of 5 - Function 4
        //Resouce&& other is safe to modify the other object
        Resource(Resource&& other) noexcept{
            data = other.data;
            other.data = nullptr;
        }

    
    //Move Assignment Operator
        //Rule of 5 - Function 5
        Resource& operator=(Resource&& other) noexcept{
            if(this != &other){
                delete data;
                data = other.data;

                other.data = nullptr;
            }
            return *this;
        }
    
    void print(){
        cout << "Value: "<<*data<<endl;
    }
};


int main() {
    Resource cat1(42);
    cout << "Cat1 -> ";
    cat1.print();




    //function 2 - copy constructor
    Resource cat2(cat1);
    cout << "Cat2 -> ";
    cat2.print();

    //Function 3 - Overloading = operator
    Resource cat3(0);
    cat3 = cat1;
    cout << "Cat3 -> ";
    cat3.print();

    //function 4 - move constructor
    Resource cat4 = move(cat1);
    cout << "Cat4 -> ";
    cat4.print();

    //function 5 - move assignment
    Resource cat5(0);
    cat5 = (Resource&&)cat1;
    cout << "Cat5 -> ";
    cat4.print();

    return 0;
}