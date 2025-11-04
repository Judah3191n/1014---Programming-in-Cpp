#include <iostream>
#include <vector>
using namespace std;

const int numOfStudents = 4;

string staticNames[3];
int staticGrades[3];
string *dynamicNames = new string[numOfStudents];
int *dynamicGrades = new int[numOfStudents];
vector<int> vectorGrades;
vector<string> vectorNames;


void inputData();
void displayArrayData(string y[numOfStudents], int z[numOfStudents]);
void displayVectorData();
double averageArray(int z[numOfStudents]);
double averageVector(vector<int> z);

int main(){
    inputData();//same for all
    displayArrayData(staticNames, staticGrades);
    displayVectorData();
    cout << "\nAverage Grade: "<<averageArray(dynamicGrades);

    delete[] dynamicNames, dynamicGrades, staticNames, staticGrades;
    staticNames, staticGrades, dynamicNames,dynamicGrades = nullptr;
    return 0;
}

void inputData(){
    string tempName;
    int tempGrade;
    for (int i = 0; i<numOfStudents; i++){
        cout << "enter a name: ";
        getline(cin, tempName);
        cout << "enter a grade: ";
        cin >> tempGrade;
        getline(cin, tempName);

        if(i<sizeof(staticNames) / sizeof(staticNames[0])){//only run this if staticNames and grades can hold the values
            staticNames[i] = tempName;
            staticGrades[i] = tempGrade;
        }
        dynamicNames[i] = tempName;
        dynamicGrades[i] = tempGrade;
        vectorNames.push_back(tempName);
        vectorGrades.push_back(tempGrade);
    }
}

void displayArrayData(string y[numOfStudents], int z[numOfStudents]){
    cout<<"\n----------Student Array Data----------"<<endl;
    for(int i = 0; i<numOfStudents; i++){
        if(i<sizeof(staticNames) / sizeof(staticNames[0])){
            cout << "Student "<<(i+1)<<":"<<endl;
            cout << "\tName: "<<y[i]<<endl;
            cout << "\tGrades: "<< z[i]<<endl;
        }
    }
}

void displayVectorData(){
    cout<<"\n----------Student Vector Data----------"<<endl;
    for(int i = 0; i<numOfStudents; i++){
        cout << "Student "<<(i+1)<<":"<<endl;
        cout << "\tName: "<<vectorNames[i]<<endl;
        cout << "\tGrades: "<< vectorGrades[i]<<endl;
    }
}

double averageArray(int z[numOfStudents]){
    double total;
    for(int i = 0; i<numOfStudents; i++){
        total += z[i];
    }
    return total/numOfStudents;
}

double averageVector(vector<int> z){
    double total;
    for(int i:z){
        total += i;
    }
    return total/z.size();
}