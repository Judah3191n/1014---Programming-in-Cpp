#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
string blankCard[4] = {
    "p---q",
    "|\\ /|",
    "|/ \\|",
    "b---d"
};

void clearScreen() {
    cout << "\033[2J\033[1;1H";  // Clear screen and move cursor to top-left
}

class Card{
    int value;//value of card in blackjack 1-11
    string suit;//suit of card
    string rank;//what each card is ace - king


    /* eventuall display of cards
    * p---q p---q
    * | 1 | |\ /|
    * | H | |/ \|
    * b---d b---d
    */

    public:
        Card(string r, string s, int v) : rank(r), suit(s), value(v){}

        int getValue(){
            return value;
        }

        void display(){
            cout << rank << " of "<<suit<<endl;
        }

        char getSuit(){
            return suit[0];
        }
        
        string getRank(){
            return rank;
        }
};

class Deck{
    vector<Card> cards;
    int position = 0;

    public:
    //when deck object is made, it creates a deck then shuffles it
        Deck(){
            buildDeck();
            shuffleDeck();
        }
        
        void buildDeck() {
            string suits[] = {"Hearts", "Dimonds", "Clubs", "Spades"}; //possible suits
            int values[] = {2,3,4,5,6,7,8,9,10,10,10,10,11}; //values 10 - K are = 10   a = 1 or 11(compared when player hits)  eveything else is their value
            string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; //possible card ranks

            // for each suit create a card of each rank and value
            for(string suit : suits){
                for (int i = 0; i<13; i++){
                    cards.push_back(Card(ranks[i], suit, values[i]));
                }
            }
        }

        void shuffleDeck(){
            srand(time(0));
            //?pointers:  randomizes vector, include algorithm
            random_shuffle(cards.begin(), cards.end());
        }

        Card dealCard(){
            //adds position after passed through
            return cards[position++];
        }
};

class Player{
    vector<Card> hand;
    string printableHand[6];

    public:
        void addCard(Card card){
            hand.push_back(card);


            printableHand[0] += "p---q ";
            if(card.getRank() == "10"){
                printableHand[1] += "| "+card.getRank()+"| ";
            } else { 
                printableHand[1] += "| "+card.getRank()+" | ";
            }
            printableHand[2] += "| "+string(1,card.getSuit())+" | ";
            printableHand[3] += "b---d ";
        }

        int getHandValue(){
            int total = 0;
            int numOfAces = 0;

            for(Card card : hand){
                total += card.getValue();

                //counts number of aces
                if(card.getValue() == 11) numOfAces++;
            }

            //change ace value from 11 to 1 if total value higher then 21
            if(total>21 && numOfAces > 0){
                total-= 10;
                numOfAces--;
            }

            return total;
        }

        void displayHand(bool hideHand = false) const{
            for(int i = 0; i<5; i++){
                if(hideHand){
                    cout << printableHand[i].substr(0,6)<< blankCard[i]<<endl;
                } else {
                    cout << printableHand[i]<<endl;
                }   
            }
        }        
};

int main(){
    Deck deck;
    Player player,dealer;

    //starting deal
    clearScreen();
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    
    cout << "Dealers hand: " <<endl;
    dealer.displayHand(true);

    cout << "\nPlayers hand: " <<endl;
    player.displayHand();
    cout << "Total: " << player.getHandValue()<<endl;

    //Players turn
    cout << "Player's turn:"<<endl;
    char choice;
    while(player.getHandValue() < 21){
        cout << "\nHit or Stand? (h/s):";
        cin >> choice;
        clearScreen();

        //if hit add card to player
        if(choice == 'h'){
            player.addCard(deck.dealCard());

            //display both hands
            cout << "Dealers hand: " <<endl;
            dealer.displayHand(true);
            cout << "\nPlayers hand: " <<endl;
            player.displayHand();
            cout << "Player Total: " << player.getHandValue()<<endl;
        } else {
            break;
        }
    }

    //player/dealer wins if total 21
    if (player.getHandValue() > 21){
        cout << "Dealer wins."<<endl;
        return 0;
    } else if (player.getHandValue() == 21){
        cout << "You win.";
        return 0;
    }


    //dealers turn
    cout << "\nDealer's Turn:"<<endl;

    //display both hands
    cout << "Dealers hand: " <<endl;
    dealer.displayHand();
    cout << "\nPlayers hand: " <<endl;
    player.displayHand();
    cout << "Dealer Total: " << dealer.getHandValue()<<endl;

    //add dealer card if less the 17
    while (dealer.getHandValue() < 17){
        clearScreen();
        cout << "Dealers hand: " <<endl;
        dealer.addCard(deck.dealCard());

        dealer.displayHand();
        cout << "\nPlayers hand: " <<endl;
        player.displayHand();
        cout << "Dealer Total: " << dealer.getHandValue()<<endl;
    }
    cout << "\nDealer stands";

    cout << "\np-------------------q"<<endl;
    cout << "|     Game Over     |"<<endl;
    cout << "b-------------------d"<<endl;


    //find winner
    int p = player.getHandValue();
    int d = dealer.getHandValue();

    cout << "\nFinal Results:"<<endl;
    cout << "\nYour total: "<< p <<endl;
    cout << "Dealer total: " << d << "\n"<<endl;


    //dealer goes above 21 or player greater then dealer 
    if(d>21 || p>d){
        cout << "You win!"<<endl;
    } else if (p<d){ //player less then dealer 
        cout << "Dealer wins!"<<endl;
    } else{
        cout << "Draw!"<<endl;
    }

    return 0;
}
