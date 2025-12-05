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

        void buildDeck();
        void shuffleDeck();
        Card dealCard();
};
class Player{
    vector<Card> hand;
    string printableHand[4];
    string blankCard[4] = {
        "p---q ",
        "|\\ /| ",
        "|/ \\| ",
        "b---d "
    };

    public:
        void addCard(Card card);
        int getHandValue();
        void displayHand(bool hideHand = false) const; 
};

void clearScreen();
void pause();
void displayTable(Player dealer, Player player, bool dealersTurn = false);
void results(Player dealer, Player player);
#endif