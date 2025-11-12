#include <iostream>
#include <regex>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string buffer = " =========== ";
    
    //4
    int score;
    int* ptrScore = &score;
    *ptrScore = 0;
    
    //1
    cout << buffer << "Part 1" << buffer << endl;
    string fullName;
    cout << "enter your name: ";
    getline(cin, fullName);
    cout << fullName << "\n" << endl;
    
    //2
    cout << buffer << "Part 2" << buffer << endl;
    string email;
    bool isValidEmail = false;
    cout << "enter your email: ";
    getline(cin, email);
    regex pattern("((\\w+)(\\.|\\_)?(\\w*)@(\\w+)\\.(\\w+))");
    if(regex_match(email, pattern)){
        isValidEmail = true;
        cout << "valid email!\n" << endl;
    } else {
        cout << "invalid email!\n" << endl;
    }
    
    //3
    cout << buffer << "Part 3 & 4" << buffer << endl;
    int randomNum1, randomNum2;
    string guess;
    srand(time(0));
    
    for (int i =0; i<3; i++){
        randomNum1 = rand() % 100 + 1;
        randomNum2 = rand() % 100 + 1;
        cout << "score: " << *ptrScore << endl;
        cout << "what is " << randomNum1 << " + " << randomNum2 << ": ";
        getline(cin, guess);
        /*does not convert the userinput to int istead convert sum of randomNums
        to string incase they add letters saving me from doing a try catch*/
        if (to_string(randomNum1 + randomNum2) == guess){ 
            cout << "correct!\n\n";
            *ptrScore = *ptrScore + 1;
        } else {
            cout << "incorrect!\n\n";
        }
    }
    
    //5
    cout << buffer << "Part 5" << buffer << endl;
    cout << "Name: " << fullName << endl;
    if (isValidEmail){
        cout << "Valid Email: " << email << endl;
    } else {
        cout << "Invalid Email: " << email << endl;
    }
    cout << "Score: " << *ptrScore << endl;
    

    
    return 0;
}