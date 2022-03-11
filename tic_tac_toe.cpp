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
    getch();
    return 0;
}