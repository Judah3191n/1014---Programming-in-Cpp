#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include <algorithm> // Required for std::reverse
#include <regex>
#include <fstream>  // Required for file operations
#include <iostream> // Required for console output

using namespace std;

int main() {
    // ----------------------------------------
    // Part 1: Basic I/O
    // Task 1: Greeting Program
    // Prompt the user to enter their first and last name.
    // Then print a greeting like: "Hello, John Doe!"
    // ----------------------------------------
    cout << "-----------Part 1-----------"<<endl;
    string fullName;
    cout << "Enter your full name: ";
    getline(cin,fullName);
    cout << "Hello, "+fullName+" nice to meet you!\n"<<endl;


    // ----------------------------------------
    // Part 2: Loops
    // Task 1: Factorial Calculator
    // Ask the user for a number.
    // Calculate its factorial using a for loop.
    // Example: 4! = 4 × 3 × 2 × 1 = 24
    // ----------------------------------------
    cout << "----------Part 2.1----------"<<endl;
    long factorialNum;
    long factorialSum = 1;
    cout << "Enter a factoral number: ";
    cin >> factorialNum;
    for (int i = 0; i<factorialNum; i++){//iterates the inputed number of time 
        factorialSum*=factorialNum-i;//multiplies total by 1 less the previous value
    }
    cout << "factorail sum is: " << factorialSum << "\n"<<endl;


    // Task 2: Number Guessing Game
    // Generate a random number between 1 and 100.
    // Ask the user to guess the number.
    // Keep prompting until the correct number is guessed.
    // ----------------------------------------
    cout << "----------Part 2.2----------"<<endl;
    srand(time(0));
    int randomNum = rand() % 101;
    int userGuess;
    cout << "Guess a number between 1 and 100"<<endl;
    bool isGuessed = false;
    do{//does it once and forever until number is correct
        cout << "Guess: ";
        cin >> userGuess;

        if(userGuess == randomNum){
            cout << "Congrats, you have guessed the number: "<< randomNum<< endl;
            isGuessed = true;
        } else if(userGuess>randomNum){
            cout << "To high"<<endl;
        } else {
            cout << "To low"<<endl;
        }
    }while(!isGuessed);
    string a;
    getline(cin,a); //clear the input same thing with java
    cout <<a<< endl;
    // ----------------------------------------
    // Part 3: Random Numbers
    // Task: Dice Roller
    // Simulate rolling two six-sided dice 5 times.
    // Display the result of each roll and the sum.
    // ----------------------------------------
    cout << "-----------Part 3-----------"<<endl;
    srand(time(0));
    int die1, die2;
    for(int i = 1; i<=5;i++){
        die1 = (rand() % 6)+1;//random numbers
        die2 = (rand() % 6)+1;

        cout << "Dice Roll "<<i<<":"<<die1<<", "<<die2<<endl;
        cout << "Sum: "<<die1+die2<<"\n"<<endl;
    }

    // ----------------------------------------
    // Part 4: String Validation
    // Task: Palindrome Checker
    // Ask the user to enter a word.
    // Check if the word is a palindrome (reads the same forwards and backwards).
    // ----------------------------------------
    cout << "-----------Part 4-----------"<<endl;
    string palindrom;
    string reversePalindrom;

    cout << "enter a word to check if it is a palindrome"<<endl;
    cout << "word: ";

    getline(cin, palindrom);
    
    //converts input to lowercase to compare later
    for (char& c : palindrom) { // Iterate through each character by reference
        // Check if the character is an uppercase letter (ASCII 'A' to 'Z')
        if (c >= 'A' && c <= 'Z') {
            // 'a' - 'A' gives the difference, which is 32.
            c = c + ('a' - 'A'); 
        }
    }

    reversePalindrom = palindrom;
    //reverses the input
    reverse(reversePalindrom.begin(), reversePalindrom.end());

    if(palindrom == reversePalindrom){
        cout << "the word '"<<palindrom<<"' is a palindrom\n"<<endl;
    } else {
        cout << "the word '"<<palindrom<<"' is not a palindrom: "<<reversePalindrom<<"\n"<<endl;
    }
    


    // ----------------------------------------
    // Part 5: Regex (Easy)
    // Task: Phone Number Validator
    // Ask the user to enter a phone number.
    // Validate the format using regex: 123-456-7890
    // Use this pattern: ^\d{3}-\d{3}-\d{4}$
    // ----------------------------------------
    cout << "-----------Part 5-----------"<<endl;
    regex r("^\\d{3}-\\d{3}-\\d{4}$");//regex pattern detemins if vaild phone number

    string phoneNumber;
    cout << "Enter your phone number: ";
    getline(cin,phoneNumber);

    if (regex_match(phoneNumber, r)) {//if input matches the regex patern it is valid
    cout << "Valid Phone Number\n" << endl;
    } else {
        cout << "Invalid Phone Number\n" << endl;
    }


    // ----------------------------------------
    // Part 6: Pointers
    // Task: Swap Function
    // Write a function that swaps two integers using pointers and a temp pointer.
    // Print the swapped values using pointers.
    // ----------------------------------------
    cout << "-----------Part 6-----------"<<endl;
    int number1 = 10;
    int number2 = 41;
    cout << "Number 1: "<< number1<<endl;
    cout << "Number 2: "<< number2<<endl;

    int* ptr1 = &number1;
    int* ptr2 = &number2;
    int* ptrTemp = new int;

    *ptrTemp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = *ptrTemp;

    cout << "\nNumber 1: "<< number1<<endl;
    cout << "Number 2: "<< number2<<"\n"<<endl;


    // ----------------------------------------
    // Part 7: File I/O
    // Task 1: Write to File
    // Ask the user to enter 5 names.
    // Write them to a file called "names.txt".
    // ----------------------------------------
    cout << "----------Part 7.1----------"<<endl;
    ofstream outputFile("names.txt", ios::app);//can run the program multiple times and append the file

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1; // Indicate an error
    }
    
    string name;
    for(int i = 0;i<5;i++){
        cout << "Enter a name to save to file: ";
        getline(cin,name);
        outputFile << name<<endl;
    }

    outputFile.close();


    // Task 2: Read and Count Lines
    // Read from "names.txt".
    // Count how many lines (names) are in the file and display the count.
    // ----------------------------------------
    cout << "----------Part 7.2----------"<<endl;
    ifstream inFile("names.txt");
    if(!inFile){
        cerr << "File could not be opened!" << endl;
        return 1; //close program
    }

    string line;
    int lineNum =0;
    while(getline(inFile, line)){
        lineNum++;
    }
    cout<<"There are "<<lineNum<<" lines in the file\n"<<endl;


    // ----------------------------------------
    // Part 8: Exceptions
    // Task 1: Safe Division
    // Write a function that divides two numbers.
    // Throw and catch an exception if the denominator is zero.
    // ----------------------------------------
    cout << "----------Part 8.1----------"<<endl;
    double numerator;
    double denominator;
    double divisor =0;

    cout << "Enter the numerator: ";
    cin >> numerator;

    cout << "Enter the denominator: ";
    cin >> denominator;

    try{
        if(denominator==0){
            throw runtime_error("Cannot divide by 0");
        } else {
            divisor = numerator/denominator;
            cout << "\nAnswer: "<<divisor;
            cout << "\nGood job!\n"<<endl;
        }
    }catch(runtime_error& e){
        cout << "runtime error: " << e.what() << endl;
    }

    

    // ----------------------------------------
    // Task 2: File Open Error Handling
    // Attempt to open a file.
    // If the file doesn’t exist, catch the error and display a message.
    // ----------------------------------------
    cout << "----------Part 8.2----------"<<endl;
    try{
        ifstream inFile("jobs.txt");
        if(!inFile){
            throw invalid_argument("File could not be opened");
        }
    }catch(invalid_argument& e){
        cout << "invalid argument: "<<e.what()<<endl;
    }

    // ----------------------------------------
    //Part 9: Full Program Exercise
    //Student Records
    // ----------------------------------------
    cout << "\n-----------Part 9-----------"<<endl;
    srand(time(0)); //generate random id

    string name2, email;
    int age,id;

    regex name_pattern(R"(^[A-Za-z\s]+$)");
    regex email_pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");

    ofstream outputFile2("students.txt");
    if (!outputFile2.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1; // Indicate an error
    }



    for (int i = 0; i < 1; i++) {
        cout << "Enter details for student " << (i + 1) << endl;


        //check if name is valid
        bool validName = false;
        while (!validName) {
            cout << "Full name: ";
            getline(cin, name2);
            if (regex_match(name2, name_pattern)){
                validName = true;
            } else {
                cout << "Invalid name2! Use only letters and spaces."<<endl;
            }
        }

        //check for valid are 16 - 100
        int* agePtr = &age;
        bool validAge = false;
        while (!validAge) {
            try {
                cout << "Enter age: ";
                cin >> *agePtr;


                //if user doesn't enter a number
                if (cin.fail()) {
                    
                    throw invalid_argument("Age must be a number!");
                }

                //if age isn't within range
                if (*agePtr < 16 || *agePtr > 100) {
                    throw out_of_range("Age must be between 16 and 100!");
                }

                validAge = true;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << " Please try again.\n";
            }
        }

        //email is valid
        bool validEmail = false;
        while (!validEmail) {
            cout << "Email: ";
            cin >> email;
            if (regex_match(email, email_pattern)){
                validEmail = true;
                cout << endl;
            } else {
                cout << "Invalid email format! Try again.\n";
            }
        }

        //create the id (random 6 digit number)
        id = rand() % 900000 + 100000;

        //save to file
        outputFile2 << id << "," << name2<< "," << age << "," << email<< "\n";
        string b;
        getline(cin,b);
    }
    outputFile2.close();
    cout << "Student records save successfuly\n"<<endl;

    ifstream inputFile("students.txt");
    if (!inputFile) {
        cerr << "Error: Could not open students.txt for reading.\n";
        return 1;
    }

    string line2;
    while (getline(inputFile, line2)) {
        cout << line2 << endl;
    }

    inputFile.close();
    cout<<"\nAll records displayed successfully\n"<<endl;

    return 0;

}