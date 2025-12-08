// blackJack.cpp

//& PROG2100_01 Slide 11
#include <cstdlib>
#include <ctime>
#include <algorithm>
//& PROG2100_11 Slide 10
#include "blackJack.h"
#include <iostream>


void pause()
{
    cout << "\nPress ENTER to continue...";
    string temp;

    //& PROG2100_02 Slide 3
    getline(cin, temp); // clear input
    getline(cin, temp);
}
void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // Clear screen and move cursor to top-left
}
vector<string> boxify(string title, string boxed, int buffer){
    vector<string> display;
    string startingBuffer = string(buffer, ' ');
    int lineLength, leftBuffer, rightBuffer;
    
    if(title.length()>boxed.length()){
        lineLength = title.length() + 4;

        leftBuffer = (lineLength - 2 - boxed.length())/2;
        if((lineLength - 2 - boxed.length())%2==0){
            rightBuffer = leftBuffer;
        } else {
            rightBuffer = leftBuffer+1;
        }

    } else {
        leftBuffer = 1;
        rightBuffer = 1;
        lineLength = 2 + leftBuffer + boxed.length() + rightBuffer;
    }

    // Top line: dash + word + dashes
    string line1 = startingBuffer + " -" + title + string((lineLength - 3 - title.length()), '-') + " ";

    // Middle line: | + buffer + tableBet + buffer + |
    string line2 = startingBuffer + "|" + string(leftBuffer, ' ') + boxed + string(rightBuffer, ' ')+ "|";

    // Bottom line: dash + dashes + dashes
    string line3 = startingBuffer +" "+ string((lineLength-2), '-') + " ";

    // Output
    display.push_back(line1);
    display.push_back(line2);
    display.push_back(line3);
    return display;
}
// Card
Card::Card(string r, string s, int v) : rank(r), suit(s), value(v) {}
int Card::getValue()
{
    return value;
}
void Card::display()
{
    cout << rank << " of " << suit << endl;
}
string Card::getSuit()
{
    return suit;
}
string Card::getRank()
{
    return rank;
}

// Deck
// when deck object is made, it creates a deck then shuffles it
Deck::Deck()
{
    buildDeck();
    shuffleDeck();
}
void Deck::buildDeck()
{
    //& PROG2100_07 Slide 5
    string suits[] = {"♠", "♥", "♦", "♣"};                                               // string suits[] = {"Hearts", "Dimonds", "Clubs", "Spades"}; //possible suits
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};                         // values 10 - K are = 10   a = 1 or 11(compared when player hits)  eveything else is their value
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; // possible card ranks

    // for each suit create a card of each rank and value
    //& PROG2100_01 Slide 8
    for (string suit : suits)
    {
        for (int i = 0; i < 13; i++)
        {                                                     //& PROG2100_07 Slide 7
            cards.push_back(Card(ranks[i], suit, values[i])); //& PROG2100_07 Slide 6
        }
    }
}
void Deck::shuffleDeck()
{
    srand(time(0));
    //?pointers:  randomizes vector, include algorithm
    random_shuffle(cards.begin(), cards.end());
    position = 0;
}
Card Deck::dealCard()
{
    // adds position after passed through
    return cards[position++];
}

// Player
void Player::addCard(Card card){
    hand.push_back(card);

    // make a drawable card and add it to the end of each line of the pritable hand array
    printableHand[0] += blankCard[0];
    if (card.getRank() == "10")
    {
        printableHand[1] += "| " + card.getRank() + "| ";
    }
    else
    {
        printableHand[1] += "| " + card.getRank() + " | ";
    }
    printableHand[2] += "| " + card.getSuit() + " | ";
    printableHand[3] += blankCard[3];
}

// find the value of each hand
int Player::getHandValue(){
    int total = 0;
    int numOfAces = 0;

    for (Card card : hand)
    {
        total += card.getValue();

        // counts number of aces
        if (card.getValue() == 11)
            numOfAces++;
    }

    // change ace value from 11 to 1 if total value higher then 21
    if (total > 21 && numOfAces > 0)
    {
        total -= 10;
        numOfAces--;
    }

    return total;
}

// prints out each line from drawable hand, so it looks like actual cards
void Player::displayHand(bool hideHand) const{
    for (int i = 0; i < 4; i++)
    {
        if (hideHand)
        {
            if (i == 2)
            {
                cout << printableHand[i].substr(0, 8) << blankCard[i] << endl;
            }
            else
            {
                cout << printableHand[i].substr(0, 6) << blankCard[i] << endl;
            }
        }
        else
        {
            cout << printableHand[i] << endl;
        }
    }
    cout << endl;
}

// reset hand when new game
void Player::newGame()
{
    hand.clear();
    for (int i = 0; i < 4; i++)
    {
        printableHand[i].clear();
    }
}
int Player::getTokens(){
    return tokens;
}
void Player::setTokens(int tokens){
    this->tokens = tokens;
}
void Player::displayPlayer(){
    clearScreen();
    vector<string> display = boxify("TOKENS",to_string(tokens));
    cout << " " << string(40, '-') << string((display[0].length()), '-') << "---- " << endl;
    cout << "|" << string(40, ' ') << display[0]<<"    |" << endl;
    cout << "|    PLAYER 1:       " << string(20, ' ') << display[1] << "    |" << endl;
    cout << "|" << string(40, ' ') << display[2]<<"    |" << endl;
    cout << " " << string(40, '-') << string((display[0].length()), '-') << "---- "<<endl;
}

// Table
Table::Table(Player &player){
    this->player=player;
}
void Table::startGame()
{

    bool isPlaying = true;
    isPlayerWinner = false;
    string choice;

    do{
        isPlayerTurn = true;

        // Ask for player bet
        if(DoubleOrNothing){
            player.setTokens(player.getTokens()-tableBet); 
            setTableBet(tableBet);
        } else {
            if(player.getTokens() == 0){
                player.displayPlayer();
                cout<< "Out of Tokens - Thank you for playing!";
                break;
            }

            tableBet = 0;
            placeBet();                                      
        }


        DoubleOrNothing = false;



        //starting deal
        player.newGame();
        dealer.newGame();
        deck.shuffleDeck();
        
        player.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());



        //& PROG2100_01 Slide 9
        while(player.getHandValue() < 21){
            //& PROG2100_06 Slide 3
            displayTable();

            //& PROG2100_05 Slide 11
            try {
                //& PROG2100_01 Slide 5
                cout << "Hit or Stand? (h/s): ";
                cin >> choice;


                if(choice.length()!=1){
                    //& PROG2100_02 Slide 6
                    throw runtime_error("Invalid Input! ");
                } else {
                    //& PROG2100_02 Slide 9
                    choice = tolower(choice[0]);

                    //if hit add card to player
                    //& PROG2100_01 Slide 7
                    if (choice == "h"){
                        player.addCard(deck.dealCard());
                    } else if (choice == "s"){
                        break;
                    } else {
                        throw runtime_error("Invalid Input! ");
                    }
                }
            } catch (runtime_error& e){
                cout << e.what() << "Please enter only 'h or 's'.\n";
                pause();
            }
        }
        isPlayerTurn = false;
        displayTable();


        //dealers turn
        while (dealer.getHandValue() < 17){
            dealer.addCard(deck.dealCard());
        }
        displayTable();


        // determine if player won
        results();
        
        // Double or Nothing?
        if(isPlayerWinner){
            choice = "";
            while(true){    
                try {
                    cout << "Double or Nothing (Y/n): ";
                    cin >> choice;

                    if(choice.length()!=1){
                        throw runtime_error("Invalid Input! ");
                    } else {
                        choice = tolower(choice[0]);

                        if (choice == "y"){
                            DoubleOrNothing = true;
                            break;
                        } else if (choice == "n"){
                            DoubleOrNothing = false;
                            break;
                        } else {
                            throw runtime_error("Invalid Input! ");
                        }
                    }
                } catch (runtime_error& e){
                    cout << e.what() << "Please enter only 'y' or 'n'.\n";
                    pause();
                }
            }
        }


        //play again
        if(!DoubleOrNothing){
            choice = "";
            while(true){    
                try {
                    cout << "Do you want to play again? (Y/n): ";
                    cin >> choice;

                    if(choice.length()!=1){
                        throw runtime_error("Invalid Input! ");
                    } else {
                        choice = tolower(choice[0]);

                        if (choice == "y"){
                            isPlaying = true;
                            break;
                        } else if (choice == "n"){
                            isPlaying = false;
                            player.displayPlayer();
                            cout<< "Thank you for playing!";
                            break;
                        } else {
                            throw runtime_error("Invalid Input! ");
                        }
                    }
                } catch (runtime_error& e){
                    cout << e.what() << "Please enter only 'y' or 'n'.\n";
                    pause();
                }
            }
        }

    }while(isPlaying);

}
void Table::displayBet(){
    vector<string> display = boxify("BET", to_string(tableBet), 3);
    for(string line: display){
        cout << line << endl;
    }
}
void Table::displayTable(){
    player.displayPlayer();

    if (isPlayerTurn)
    {
        cout << "--------Player's turn--------" << endl;
        cout << "Dealers hand: " << endl;
        dealer.displayHand(isPlayerTurn);

        displayBet();

        cout << "\nPlayers hand: " << endl;
        player.displayHand();
        cout << "Player Total: " << player.getHandValue() << endl;
    }
    else
    {
        cout << "--------Dealer's turn--------" << endl;
        cout << "Dealers hand: " << endl;
        dealer.displayHand();

        displayBet();

        cout << "\nPlayers hand: " << endl;
        player.displayHand();

        cout << "Dealer Total: " << dealer.getHandValue() << endl;
    }
}
void Table::results()
{
    // Calculate results
    int winner = calculateWinner();
    
    // show dealers hand
    displayTable();

    //display results
    vector<string> display = boxify(string(30, '-'), "Game Over", 10);
    for(string line : display){
        cout << line << endl;
    }
        

    cout << "Final Results:" << endl;
    cout << "\tDealer total: " << dealer.getHandValue() << endl;
    cout << "\tPlayer total: " << player.getHandValue() << "\n"<< endl;

    if(winner == 1){
        cout << "Player Wins!" << endl;
        isPlayerWinner = true;
    } else if (winner == 0){
        cout << "Dealer Wins!" << endl;
        isPlayerWinner = false;
    } else {
        cout << "Draw" << endl;
        isPlayerWinner = false;
    }
    
}
void Table::placeBet()
{
    int playerBet;
    string playerInput;

    player.displayPlayer();
    while (true)
    {
        cout << "Enter your bet: ";
        cin >> playerInput;

        player.displayPlayer();
        // convert string to int
        try
        {
            playerBet = stoi(playerInput);
        }
        catch (invalid_argument &)
        {
            cout << "Invalid Input: Enter a number within your balance" << endl;
            continue;
        }

        // Bet a posative token value
        if (playerBet <= 0)
        {
            cout << "Bet must be greater then zero." << endl;
            continue;
        } // Not enough tokens
        else if (player.getTokens() < playerBet)
        {
            cout << "Not enought tokens." << endl;
            continue;
        }

        break;

    }

    // valid bet
    player.setTokens(player.getTokens()-playerBet);
    setTableBet(playerBet);
}
void Table::setTableBet(int playerBet){
    tableBet = 2 * playerBet;
}
int Table::calculateWinner(){
    int winner = 0;
    int p = player.getHandValue();
    int d = dealer.getHandValue();

    if (p > 21 && d > 21)
    {
        //DRAW - both bust
        player.setTokens(player.getTokens() + tableBet / 2);
        winner = -1;
    }
    else if (p == 21 && d == 21)
    {
        //DRAW - both hit 21
        player.setTokens(player.getTokens() + tableBet / 2);
        winner = -1;
    }
    else if (p == 21)
    {
        //WIN - player hits 21
        player.setTokens(player.getTokens() + tableBet);
        winner = 1;
    }
    else if (d == 21)
    {
        //LOSE - Dealer hit 21
        winner = 0;
    }
    else if (p > 21)
    {
        //LOSE - player bust
        winner = 0;
    }
    else if (d > 21)
    {
        //WIN - dealer bust
        player.setTokens(player.getTokens() + tableBet);
        winner = 1;
    }
    else if (p > d)
    {
        //WIN - player higher
        player.setTokens(player.getTokens() + tableBet);
        winner = 1;
    }
    else if (d > p)
    {
        //LOSE - dealer higher
        winner = 0;
    }
    else
    {
        //DRAW - same number
        player.setTokens(player.getTokens() + tableBet / 2);
        winner = -1;
    }

    return winner;
}