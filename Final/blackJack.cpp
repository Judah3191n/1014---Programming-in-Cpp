// blackJack.cpp

//& PROG2100_01 Slide 11
#include <cstdlib>
#include <ctime>
#include <algorithm>
//& PROG2100_11 Slide 10
#include "blackJack.h"
#include <iostream>


void pause() {
    cout <<"\nPress ENTER to continue...";
    string temp;

    
    //& PROG2100_02 Slide 3
    getline(cin,temp);//clear input
    getline(cin,temp);
}
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // Clear screen and move cursor to top-left
}
void displayTable(Player dealer, Player player, bool dealersTurn){
    clearScreen();
    if(dealersTurn){
        cout << "--------Dealer's turn--------"<<endl;
        cout << "Dealers hand: " <<endl;
        dealer.displayHand();

        cout << "\nPlayers hand: " <<endl;
        player.displayHand();

        cout << "\n\nDealer Total: " << dealer.getHandValue()<<endl;
    } else {
        cout << "--------Player's turn--------"<<endl;

        cout << "Dealers hand: " <<endl;
        dealer.displayHand(true);

        cout << "\nPlayers hand: " <<endl;
        player.displayHand();

        cout << "Player Total: " << player.getHandValue()<<endl;
    }
};
void results(Player dealer, Player player){
    cout << "\np---------------------------q"<<endl;
    cout << "|         Game Over         |"<<endl;
    cout << "b---------------------------d"<<endl;


    //find winner
    int p = player.getHandValue();
    int d = dealer.getHandValue();

    cout << "\nFinal Results:"<<endl;
    cout << "\tDealer total: "<< d <<endl;
    cout << "\tPlayer total: " << p << "\n"<<endl;



    if (p > 21 && d > 21) {
        cout << "Draw!" << endl; // both bust
    } else if (p == 21 && d == 21) {
        cout << "Draw!" << endl; // both hit 21
    } else if (p == 21) {
        cout << "Player wins!" << endl;
    } else if (d == 21) {
        cout << "Dealer wins!" << endl;
    } else if (p > 21) {
        cout << "Dealer wins!" << endl; // player bust
    } else if (d > 21) {
        cout << "Player wins!" << endl; // dealer bust
    } else if (p > d) {
        cout << "Player wins!" << endl;
    } else if (d > p) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "Draw!" << endl; // same number
    }
};
//Card
    Card::Card(string r, string s, int v) : rank(r), suit(s), value(v){}
    int Card::getValue(){
        return value;
    }
    void Card::display(){
        cout << rank << " of "<<suit<<endl;
    }
    string Card::getSuit(){
        return suit;
    }   
    string Card::getRank(){
        return rank;
    }


//Deck
    //when deck object is made, it creates a deck then shuffles it
    Deck::Deck(){
        buildDeck();
        shuffleDeck();
    }
    void Deck::buildDeck() {
        //& PROG2100_07 Slide 5
        string suits[] = {"♠","♥","♦","♣"};//string suits[] = {"Hearts", "Dimonds", "Clubs", "Spades"}; //possible suits
        int values[] = {2,3,4,5,6,7,8,9,10,10,10,10,11}; //values 10 - K are = 10   a = 1 or 11(compared when player hits)  eveything else is their value
        string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; //possible card ranks

        // for each suit create a card of each rank and value
        //& PROG2100_01 Slide 8
        for(string suit : suits){
            for (int i = 0; i<13; i++){ //& PROG2100_07 Slide 7
                cards.push_back(Card(ranks[i], suit, values[i])); //& PROG2100_07 Slide 6
            }
        }
    }
    void Deck::shuffleDeck(){
        srand(time(0));
        //?pointers:  randomizes vector, include algorithm
        random_shuffle(cards.begin(), cards.end());
    }
    Card Deck::dealCard(){
        //adds position after passed through
        return cards[position++];
    }


//Player
    void Player::addCard(Card card){
        hand.push_back(card);

        //make a drawable card and add it to the end of each line of the pritable hand array
        printableHand[0] += blankCard[0];
        if(card.getRank() == "10"){
            printableHand[1] += "| "+card.getRank()+"| ";
        } else { 
            printableHand[1] += "| "+card.getRank()+" | ";
        }
        printableHand[2] += "| "+card.getSuit()+" | ";
        printableHand[3] += blankCard[3];
    }
    //find the value of each hand
    int Player::getHandValue(){
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
    //prints out each line from drawable hand, so it looks like actual cards
    void Player::displayHand(bool hideHand) const{
        for(int i = 0; i<4; i++){
            if(hideHand){
                if(i==2){
                    cout << printableHand[i].substr(0,8) <<blankCard[i]<<endl;
                }else{
                    cout << printableHand[i].substr(0,6)<< blankCard[i]<<endl;
                }
            } else {
                cout << printableHand[i]<<endl;
            }
        }
    }        

