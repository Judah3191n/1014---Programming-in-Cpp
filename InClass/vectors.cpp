#include <iostream>
#include <vector>
using namespace std;

int main(){

    //Empty
    vector<int> intVector;

    bool isLeaving = false;
    int userInput;
    int total = 0;
    cout << "Add to the vector, (-1 to exit)" << endl;
    do{
        cout << "Enter value: ";
        cin >> userInput;
        if(userInput == -1){
            isLeaving = true;
        } else {
            intVector.push_back(userInput);
            total += userInput;
        }
    }while(!isLeaving);

    //if vector has no values and divides by 0
    try{
        if(intVector.size()==0){
            throw runtime_error("Cannot divide by 0");
        } else {
                cout << "Total Average: " << (double)total/intVector.size() << endl;
        }
    }catch(runtime_error& e){
        cout << "runtime error: " << e.what() << endl;
    }

}
