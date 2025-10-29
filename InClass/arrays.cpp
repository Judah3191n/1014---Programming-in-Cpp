#include <iostream>
using namespace std;
int main(){

    int *arr = new int[3];

    for (int i = 0; i<3; i++){
        cout << "enter a number: ";
        cin >> arr[i];
    }

    int* newArr = new int[4];
    for(int i = 0; i< 3;i++){
        newArr[i] = arr[i];
    }
    delete[] arr;

    cout << "enter a 4th value for the new array: ";
    cin >> newArr[3];

    for(int i = 0; i < 4; i++){
        cout <<newArr[i];
    }


    delete[] newArr;
    newArr = nullptr;
    return 0;
}