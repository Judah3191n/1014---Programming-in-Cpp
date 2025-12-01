#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "blackJack.h"
#include <iostream>



void clearScreen() {
    cout << "\033[2J\033[1;1H";  // Clear screen and move cursor to top-left
}

//Card
    Card::Card(string r, string s, int v) : rank(r), suit(s), value(v){}

    int Card::getValue(){
        return value;
    }

    void Card::display(){
        cout << rank << " of "<<suit<<endl;
    }

    char Card::getSuit(){
        return suit[0];
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
        printableHand[0] += "p---q ";
        if(card.getRank() == "10"){
            printableHand[1] += "| "+card.getRank()+"| ";
        } else { 
            printableHand[1] += "| "+card.getRank()+" | ";
        }
        printableHand[2] += "| "+string(1,card.getSuit())+" | ";
        printableHand[3] += "b---d ";
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
                cout << printableHand[i].substr(0,6)<< blankCard[i]<<endl;
            } else {
                cout << printableHand[i]<<endl;
            }
        }
    }        



