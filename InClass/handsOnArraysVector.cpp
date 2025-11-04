#include <iostream>
#include <vector>
using namespace std;

const int numOfStudents = 5;

string staticNames[3];
int staticGrades[3];
string *dynamicNames = new string[numOfStudents];
int *dynamicGrades = new int[numOfStudents];
vector<int> vectorGrades;
vector<string> vectorNames;


void inputData();//inputs to vector and dynamic array
void inputStaticData();//inputs to static
void displayStaticArrayData();//displays static data
void displayDynamicArrayData();//displays dynamic data
void displayVectorData();//displays vector data
double averageArray(int z[numOfStudents]);
double averageVector(vector<int> z);

const int staticSize = sizeof(staticNames) / sizeof(staticNames[0]);

int main(){
    inputData();//same for all
    displayDynamicArrayData();
    displayVectorData();
    displayStaticArrayData();

    cout << "\nAverage Grade: "<<averageArray(dynamicGrades);

    delete[] dynamicNames, dynamicGrades, staticNames, staticGrades;
    staticNames, staticGrades, dynamicNames,dynamicGrades = nullptr;
    return 0;
}


void inputStaticData(){
    string tempName;
    int tempGrade;
    for (int i = 0; i<staticSize; i++){
        cout << "enter a name: ";
        getline(cin, tempName);
        cout << "enter a grade: ";
        cin >> tempGrade;
        getline(cin, tempName);

        staticNames[i] = tempName;
        staticGrades[i] = tempGrade;
    }
}

void inputData(){
    string tempName;
    int tempGrade;
    if(numOfStudents >= staticSize){
        for (int i = 0; i<numOfStudents; i++){
            cout << "enter a name: ";
            getline(cin, tempName);
            cout << "enter a grade: ";
            cin >> tempGrade;
            getline(cin, tempName);

            if(i<staticSize){
                staticNames[i] = tempName;
                staticGrades[i] = tempGrade;
            }
            dynamicNames[i] = tempName;
            dynamicGrades[i] = tempGrade;
            vectorNames.push_back(tempName);
            vectorGrades.push_back(tempGrade);
        } 
    } else {
        for (int i = 0; i<staticSize; i++){
            cout << "enter a name: ";
            getline(cin, tempName);
            cout << "enter a grade: ";
            cin >> tempGrade;
            getline(cin, tempName);


            staticNames[i] = tempName;
            staticGrades[i] = tempGrade;

            if(i<numOfStudents){
                dynamicNames[i] = tempName;
                dynamicGrades[i] = tempGrade;
                vectorNames.push_back(tempName);
                vectorGrades.push_back(tempGrade);
            }
        } 
    }
}

void displayDynamicArrayData(){
    cout<<"\n----------Student Dynamic Array Data----------"<<endl;
    for(int i = 0; i<numOfStudents; i++){
        cout << "Student "<<(i+1)<<":"<<endl;
        cout << "\tName: "<<dynamicNames[i]<<endl;
        cout << "\tGrades: "<< dynamicGrades[i]<<endl;
    }
}

void displayStaticArrayData(){
    cout<<"\n----------Student Static Array Data----------"<<endl;
    for(int i = 0; i<staticSize; i++){
        cout << "Student "<<(i+1)<<":"<<endl;
        cout << "\tName: "<<staticNames[i]<<endl;
        cout << "\tGrades: "<< staticGrades[i]<<endl;
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