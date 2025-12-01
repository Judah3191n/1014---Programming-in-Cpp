#ifndef blackJack_util
#define blackJack_util

#include <string>
#include <vector>

using namespace std;

class Card{
    int value;
    string suit;
    string rank;

    public:
        Card(string r, string s, int v);
        int getValue();
        void display();
        char getSuit();
        string getRank();
};

class Deck{
    vector<Card> cards;
    int position = 0;

    public:
        Deck();  

        void buildDeck();
        void shuffleDeck();
        Card dealCard();
};

//both the player and dealer
class Player{
    vector<Card> hand;
    string printableHand[4];
    string blankCard[4] = {
        "p---q",
        "|\\ /|",
        "|/ \\|",
        "b---d"
    };

    public:
        void addCard(Card card);
        int getHandValue();
        void displayHand(bool hideHand = false) const; 
};

void clearScreen();

#endif