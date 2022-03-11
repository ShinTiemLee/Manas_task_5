#include "iostream"
#ifndef game
#define game

class tictactoe
{
    private:
    char player1[10],player2[10];

    public:

    void rules();                                                     
    void mat();
    void match();
    void grid(int pos, int turns, char player1[], char player2[]);
    void result(); 

};

#endif