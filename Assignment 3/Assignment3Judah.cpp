#include <iostream>
#include <vector>
using namespace std;


int staticArrayTest1[5] = {1,2,3,4,5};
int staticArrayTest2[5];

double average(int z[5], int size);
int findMax(int arr[], int size);
void arrays();
void vectors();
void swapArrays(int arr1[], int arr2[], int size);

int main(){
    //Part 1-4
    cout << "Max value: "<<findMax(staticArrayTest1,5)<<endl;
    cout << "Average: "<<average(staticArrayTest1,5)<<endl;
    arrays();
    vectors();

    int array1[6] = {3,4,5,1,72,3};
    int array2[6] = {5,512,124,5,12,0};

    //display unswapped arrays
    cout <<"Original Arrays:"<<endl;
    cout << "Array 1: ";
    for(int i=0; i<6; i++){
        cout <<array1[i]; 
    }
    cout <<"\nArray 2: ";
    for(int i=0; i<6; i++){
        cout <<array2[i]; 
    }

    //swap arrays
    swapArrays(array1, array2, 6);

    return 1;
}


double average(int z[], int size){
    double total = -1;

    //return -1 if invalid size
    if(size>0){
        total = 0;
        for(int i=0; i<size; i++){
            total += z[i];
        }
        return total/size;
    }

    return total;
}

int findMax(int arr[], int size){
    int largestValue = -1;

    //return -1 if invalid size
    if(size>0){
        int largestValue = arr[0];
        for(int i=0; i<size; i++){
            if(arr[i]>largestValue){
                largestValue = arr[i];
            }
        }
        return largestValue;
    }

    return largestValue;
}

void arrays(){
    cout<<"\nDynamic Arrays"<<endl;
    int numOfElements = 0;

    cout << "Enter number of elements: ";
    cin >> numOfElements;


    //makes sure size isn't 0 or negative
    if (numOfElements>0){
        int *dynamicArray = new int[numOfElements];

        //fill array
        for(int i=0; i<numOfElements; i++){
            cout << "Enter a number: ";
            cin >> dynamicArray[i];
        }

        //print reverse array
        cout << "\nReversed Array Value: (";
        for(int i=numOfElements-1; i>=0; i--){
            if(dynamicArray[0] != dynamicArray[i]){
                cout << dynamicArray[i]<<", ";          
            } else {
                cout << dynamicArray[i]<<")"<<endl;
            }
        }

        delete[] dynamicArray;
        dynamicArray = nullptr;
    }

}

void vectors(){
    cout << "\nVectors"<<endl;
    vector<int> intVector;

    //fill vector
    int userInput;
    for(int i=0; i<5; i++){
        cout << "Enter a number: ";
        cin >> userInput;
        intVector.push_back(userInput);
    }


    //display vector
    cout << "\nVector Value: (";
    for(int intValue: intVector){
        if(intValue != intVector.back()){
            cout << intValue<<", ";          
        } else {
            cout << intValue<<")"<<endl;
        }
    }

    //insert value in 2nd position
    intVector.insert(intVector.begin() + 1, 100);


    //display vector
    cout << "Updated Vector Value: (";
    for(int intValue: intVector){
        if(intValue != intVector.back()){
            cout << intValue<<", ";          
        } else {
            cout << intValue<<")\n"<<endl;
        }
    }
}

void swapArrays(int arr1[], int arr2[], int size){
    //makes sure size is valid
    if(size>0){
        int tempArray[size];

        for(int i=0; i<size; i++){
            //store array1 in tempArray
            tempArray[i] = arr1[i];

            //store array2 in now empty array1 
            arr1[i] = arr2[i];

            //overide array2 with tempArray from array1
            arr2[i] = tempArray[i];
        }

        //display swaped arrays
        cout<<"\n\nUpdated Arrays:"<<endl;
        cout<< "Array 1: ";
        for(int i=0; i<6; i++){
            cout<<arr1[i]; 
        }
        cout << "\nArray 2: ";
        for(int i=0; i<6; i++){
            cout <<arr2[i]; 
        }
    }
}