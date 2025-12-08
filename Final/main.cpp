// main.cpp

#include <windows.h>
#include <iostream>
//& PROG2100_11 Slide 10
#include "blackJack.h"

using namespace std;

//chcp 65001
int main(){
    SetConsoleOutputCP(CP_UTF8); //set UTF-8 out put to display ♠ ♥ ♦ ♣
    Player p1;
    Table t1(p1);
    t1.startGame();
    return 0;
}