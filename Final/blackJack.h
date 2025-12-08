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
        void addCard(Card card);
        int getHandValue();
        void displayHand(bool hideHand = false) const; 
        int getTokens();
        void setTokens(int tokens);
        void newGame();
        void displayPlayer();
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
        Table(Player& player);
        void startGame();
        void displayBet();
        void displayTable();
        void results();
        void placeBet();
        void setTableBet(int playerBet);
        int calculateWinner();
};

void pause();
void clearScreen();
vector<string> boxify(string title, string boxed, int buffer = 0);
#endif