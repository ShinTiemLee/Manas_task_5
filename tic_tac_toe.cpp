#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "game.h"

using namespace std;

int main()   
{
    tictactoe play;
    play.rules();
    play.match();
    play.result();
    getch();
    return 0;
}