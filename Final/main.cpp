#include <iostream>
#include "blackJack.h"

using namespace std;


int main(){
    Deck deck;
    Player player,dealer;

    //starting deal
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());


    //Players turn
    char choice;
    while(player.getHandValue() < 21){
        displayTable(dealer,player);

        cout << "\nHit or Stand? (h/s):";
        cin >> choice;

        //if hit add card to player
        if(choice == 'h'){
            player.addCard(deck.dealCard());
        } else {
            break;
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