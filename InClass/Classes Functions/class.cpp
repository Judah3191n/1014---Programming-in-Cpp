#include <iostream>
#include <vector>
using namespace std;

class Student {   
    public:
        string firstName;
        string lastName;
        string email;

        void changeGrade(double newGrade){
            grades.push_back(newGrade);
        }

        void introduction(){
            cout << "Hi I am "<<firstName<<" "<<lastName<<", nice to meet you"<<endl;
        }

        void displayEmail(){
            cout << email<<endl;
        }

        Student(string firstName, string lastName, string email, string studentID){
            this->firstName = firstName;
            this->lastName = lastName;
            this->email = email;
            this->studentID = studentID;
        }
        //Student(string firstName, string lastName, string email, string studentID) : firstName(firstName), lastName(lastName), email(email), studentID(studentID){}

        ~Student(){
            cout <<firstName<<" has been permanently removed from this world"<< endl;
        }

    private:
        string studentID;
        vector<double> grades;
};
class BankAccount{
    public:
        //two members
        int accountNumber;
        double balance;

        //3 constructors
        void deposit(double amount){
            balance+= amount;
        }

        // BankAccount(double userBalance, int userAccountNumber) : balance(userBalance), accountNumber(userAccountNumber){}

        BankAccount(int userAccountNumber){
            balance=0;
            accountNumber=userAccountNumber;
        }

        ~BankAccount(){
            balance = 0;
            cout << "Account ID "<<accountNumber<<" was deleted"<<endl;
        }
    
    
    private:

    
};

class Item{
    protected:
        string title;
        void display(){
            cout << "title Name: "<<title<<endl;
        }
        ~Item(){
            cout<<title<< " was destroyed"<<endl;
        }
        
};

class Book : public Item {
    public:
        string author;

        void display(){
            cout <<"Title: "<<title<<
            "\nAuthor: "<<author<<endl<<endl;
        }

        Book(string title, string author){
            this -> title = title;
            this->author = author;
        }
};

class DVD : public Item {
    public:
        int duration;

        void display(){
            cout << "Title: "<< title <<
            "\nDuration: "<< duration<<" minutes"<<endl<<endl;
        }

        DVD(string title, int duration){
            this->title = title;
            this->duration = duration;
        }
};
//main function
int main(){

    Book book1 = Book("Harry Potter", "JK Rowling");
    book1.display();

    DVD dvd1 = DVD("The Good The Bad and The Ugly", 143);
    dvd1.display();
    // BankAccount tempAccount(123);
    // tempAccount.balance = 0;
    // tempAccount.deposit(5);

    // vector<Student> students;
    // students.push_back(Student("Judah", "Csanyi", "Judah@Csanyi.ca", "1"));
    // students.push_back(Student("Billy","Bob","BillBoy@Bob.com", "2"));

    // students[0].introduction();
    // students[1].introduction();
}