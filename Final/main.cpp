#include <iostream>
#include "blackJack.h"

using namespace std;

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
    cout << "\n\nDealer Total: " << dealer.getHandValue()<<endl;

    //add dealer card if less the 17
    while (dealer.getHandValue() < 17){
        clearScreen();
        cout << "Dealers hand: " <<endl;
        dealer.addCard(deck.dealCard());

        dealer.displayHand();
        cout << "\nPlayers hand: " <<endl;
        player.displayHand();
        cout << "\n\nDealer Total: " << dealer.getHandValue()<<endl;
    }
    cout << "Dealer stands";

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