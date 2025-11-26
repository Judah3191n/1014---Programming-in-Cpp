#include <iostream>
#include <stdexcept>


using namespace std;
int main(){
    double numerator;
    double denominator;
    double divisor =0;

    cout << "Enter the numerator: ";
    cin >> numerator;

    cout << "Enter the denominator: ";
    cin >> denominator;

    try{
        if(denominator==0){
            throw runtime_error("Cannot devide by 0");
        } else {
            divisor = numerator/denominator;
            cout << "\nAnswer: "<<divisor;
        }
    }catch(runtime_error& e){
        cout << "runtime error: " << e.what() << endl;
    }

    
    cout << "\nGood job!: ";

}