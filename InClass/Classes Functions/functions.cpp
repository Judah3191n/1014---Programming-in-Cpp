#include <iostream>
#include <stdexcept>


using namespace std;
//global vairalble
string message = "Global Message";

//function declaration
void lokalmesag();
void printMessage();
int square(int z);
double averageArray(int z[5]);
void D2Arr();
void arrayPlay();
void loop2DArr(int z[4][3]);
int add(int a);

int main(){

    D2Arr();
}

//function definition
void D2Arr(){
    int matrix[4][3]{
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };
    cout << matrix[2][1] << endl;
    loop2DArr(matrix);
}

double averageArray(int z[5]){
    double total;
    for(int i = 0; i<5; i++){
        total += z[i];
    }
    return total/5;
}

void lokalmesag(){
    string message = "Local Message";
    cout << "Local Message: "<< message << endl;
    cout << "Gloval Message: "<< ::message << endl;
}

int square(int z){
    return z*z;
}

void printMessage(){
    cout << "Global Message: "<< message << endl;
}

void arrayPlay(){
    int userIntArr[5];
    int highest = 0;
    int lowest = userIntArr[0];

    for(int i = 0; i<5;i++){
        cout << "enter a number: ";
        cin >> userIntArr[i];
        
        if(userIntArr[i]>highest){
            highest = userIntArr[i];
        }
        if(userIntArr[i]<lowest){
            lowest = userIntArr[i];
        }
    }

    double average = averageArray(userIntArr);
    cout << "Average: "<< average<< endl;
    cout << "Highest: "<< highest << endl;
    cout << "Lowest: "<< lowest << endl;
}

void loop2DArr(int z[4][3]){
    for(int row = 0; row < 4; row++){
        for(int column = 0; column<3; column++){
            cout << z[row][column] << endl;
        }
    }
}

int add(int a){
    int sum = 0;
    int value = a;
    sum+=value;
    value--;
    if(a==0){
        return sum;
    } else {
        add(value);
    }
}