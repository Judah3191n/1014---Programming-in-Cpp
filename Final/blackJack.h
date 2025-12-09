/*
 * Title: CPP Final: BlackJack
 * Name: Judah Csanyi
 * Date: December 8, 2025
 * Description:
 *      A simple black jack game where the usere can
 *      play aginst the dealer. Displays cards, calculates
 *      game and display score
 */


//& PROG2100_11 Slide 9
// blackJack.h

#ifndef blackJack_util
#define blackJack_util

//&PROG2100_02 Slide 6
#include <string>
#include <vector>

using namespace std;

//& PROG2100_08 Slide 5
class Card{
    //& PROG2100_08 Slide 7
    private:
        int value;
        string suit;
        string rank;

    public:
        //& PROG2100_08 Slide 10
        Card(string r, string s, int v);
        int getValue();      
        void display();
        string getSuit();
        string getRank();
};
class Deck{
    vector<Card> cards;
    int position = 0;

    public:
        Deck();  

        void buildDeck();       //creates deck
        void shuffleDeck();     // resets deck
        Card dealCard();        // returns carrd
};
class Player{
    private:
        long tokens = 100L;
        vector<Card> hand;
        string printableHand[4];
        string blankCard[4] = {
            "p---q ",
            "|\\ /| ",
            "|/ \\| ",
            "b---d "
        };

    public:
        void addCard(Card card);        //add card
        int getHandValue();             // sum of cards
        void displayHand(bool hideHand = false) const; //prints out hand
        int getTokens();               
        void setTokens(int tokens); 
        void newGame();                 // resets hand
        void displayPlayer();           // displays score
};
class Table{
    private:
        //& PROG2100_08 Slide 16
        long tableBet = 0L;
        Player player, dealer;
        Deck deck;
        bool isPlayerWinner,DoubleOrNothing = false;
        bool isPlayerTurn = true;
        int tableBuffer = 10;

    public:
        Table(Player& player);      // takes in the palyer refernce
        void startGame();           // game runs here
        void displayBet();          // uses the boxify funcition to display the bet in the table
        void displayTable();        // dispay the playing table
        void results();             // display the results
        void placeBet();            // gets user betting input
        void setTableBet(int playerBet);    //a setter method for the table
        int calculateWinner();      // find winner
};

void pause();
void clearScreen();
vector<string> boxify(string title, string boxed, int buffer = 0); //returns a box arount a word with a title
#endif