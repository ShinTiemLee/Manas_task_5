# Manas_task_5

*Game Of Tic Tac Toe in c++* 


_`Defined functions:`_

void rules()    :- Dispalys the rules of the game and assigns name to Player 1 and 2. Also makes sure no rewriting on a tile occurs.

void mat()      :- Displays the configuration(3x3 grid/tile).

void match()    :- Executes the match.

void grid()     :- Changes the members of the tile based on players input.

void result()   :- Checks win condition and terminates game if win condition is satisfied.


_` IMP Variables:`_

turns=             Var to choose which player's turn to play

no_of_turns=       Var to set number of valid turns per match (excluding invalid inputs/turns)

toggle=            Var acts as flag to check rewriting/overwriting on the same tile 

check_repeat[]=    Array to gather the address of tiles already occupied

pos=               Var with the tile address to be marked/occupied with the current player's symbol

*Program is commented for more clarity *
