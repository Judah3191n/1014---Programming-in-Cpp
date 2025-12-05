// main.cpp

#include <windows.h>
#include <iostream>
//& PROG2100_11 Slide 10
#include "blackJack.h"

using namespace std;

//chcp 65001
int main(){
    SetConsoleOutputCP(CP_UTF8); //set UTF-8 out put to display ♠ ♥ ♦ ♣

    //& PROG2100_08 Slide 16
    Deck deck;
    Player player,dealer;

    //starting deal
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());


    //Players turn
    string choice;

    //& PROG2100_01 Slide 9
    while(player.getHandValue() < 21){
        //& PROG2100_06 Slide 3
        displayTable(dealer,player);

        //& PROG2100_05 Slide 11
        try {
            //& PROG2100_01 Slide 5
            cout << "\nHit or Stand? (h/s):";
            cin >> choice;

            //& PROG2100_02 Slide 9
            choice = tolower(choice[0]);

            //if hit add card to player
            //& PROG2100_01 Slide 7
            if(choice.length()!=1){ //& PROG2100_02 Slide 6
                throw runtime_error("Invalid Input! ");
            } else if (choice == "h"){
                player.addCard(deck.dealCard());
            } else if (choice == "s"){
                break;
            } else {
                throw runtime_error("Invalid Input! ");
            }
        } catch (runtime_error& e){
            cout << e.what() << "Please enter only 'h or 's'.\n";
            pause();
        }
    }
 
    displayTable(dealer, player, true);


    //dealers turn
    while (dealer.getHandValue() < 17){
        dealer.addCard(deck.dealCard());
    }
    displayTable(dealer, player, true);


    results(dealer,player);
    return 0;
}