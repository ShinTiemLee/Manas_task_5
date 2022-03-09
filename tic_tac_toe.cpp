#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void rules();                                                     
void mat();
void match(char player1[],char player2[]);
void grid(int pos, int turns, char player1[], char player2[]);
void result(char arr[][3], char player1[], char player2[]);

void rules()                 //Displays rules and takes players' names
{
    char player1[10],player2[10];
    cout<<"Each player enters the number corresponding to the position of the tile they want to mark in each turn and the first player to successfully make a line pass through their symbol wins\n";
    mat();
    cout<<"The 1st player will be 'X' and the 2nd will be 'O'\n";
    cout<<"Enter the name of the player1:";
    cin>>player1;
    cout<<"\nEnter the name of player2:";
    cin>>player2;
    match(player1, player2);

}

void mat()        //Displays the configuration of the game
{ 
    cout<<"-------------------------------------------------------------------------"<<endl;
    int count=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          cout<<count<<"\t";
          count++;
        }
        cout<<"\n"; 
    }
    cout<<"-------------------------------------------------------------------------"<<endl;
}

void match(char player1[],char player2[])       //Executes the match once
{
    int no_of_turns=0;
    int turns=0;
    int pos,index=0,toggle=0;
    int check_repeat[9];
    while (no_of_turns<9)
    {
     switch(turns)
     {
         case 0: cout<<"\n<--"<<player1<<"'s turn---> \n\n"<<"Enter the position to mark: ";
                 cin>>pos;
                 break;  
         
         case 1: cout<<"\n<--"<<player2<<"'s turn---> \n\n"<<"Enter the position to mark: ";
                 cin>>pos;
                 break;                  
     }
     for(int k=0;k<index;k++)                                         // No rewriting on tile is allowed,player is asked to try again
     {
         if (check_repeat[k]==pos)
         {
            no_of_turns--;
            cout<<"\n -------Tile already occupied!!!-------"<<endl<<"-------Try again!--------\n";
            toggle=1;
            break;
         }
     }
     if(toggle==1)
     {
        toggle=0;
        continue;
     }
     check_repeat[index]=pos;
     index++;
     grid(pos,turns,player1,player2);
     turns=!turns;
     no_of_turns++;
    }
    cout<<"\n ------------------Draw----------------";
    exit(0);
}

void grid(int pos, int turns, char player1[], char player2[])        //Changes and displays the tiles according to input by player
{
    static char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char var;
    if (turns==0)
      var='X';
    else 
      var='O';  
    
    switch(pos)
        {
            case 1: arr[0][0]=var;
                    break;

            case 2: arr[0][1]=var;
                    break;

            case 3: arr[0][2]=var;
                    break;

            case 4: arr[1][0]=var;
                    break;

            case 5: arr[1][1]=var;
                    break;

            case 6: arr[1][2]=var;
                    break;

            case 7: arr[2][0]=var;
                    break;

            case 8: arr[2][1]=var;
                    break;

            case 9: arr[2][2]=var;
                    break;
              
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
         cout<<arr[i][j]<<"\t";
        cout<<endl; 

    }
    result(arr,player1,player2);
}
 
void result(char arr[3][3],char player1[],char player2[])      //Checks win condition and terminates on achieving win condition
{
    int j=0;
    for(int i=0;i<3;i++)
    {
      if(((arr[i][j]==arr[i][j+1])&&(arr[i][j+1]==arr[i][j+2]))&&(arr[i][j]=='X'))
       {
           cout<<"***************"<<player1<<" is the winner**********************";
           exit(0);
       }

       if(((arr[i][j]==arr[i][j+1])&&(arr[i][j+1]==arr[i][j+2]))&&(arr[i][j]=='O'))
       {
           cout<<"***************"<<player2<<" is the winner**********************";
           exit(0);
       }

       if(((arr[j][i]==arr[j+1][i])&&(arr[j+1][i]==arr[j+2][i]))&&(arr[j][i]=='X'))
       {
           cout<<"***************"<<player1<<" is the winner**********************";
           exit(0);
       }

       if(((arr[j][i]==arr[j+1][i])&&(arr[j+1][i]==arr[j+2][i]))&&(arr[j][i]=='O'))
       {
           cout<<"***************"<<player2<<" is the winner**********************";
           exit(0);
       }

    }

    if(((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2]))&&(arr[1][1]=='X'))
       {
           cout<<"***************"<<player1<<" is the winner**********************";
           exit(0);
       }

    if(((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2]))&&(arr[1][1]=='O'))
       {
           cout<<"***************"<<player2<<" is the winner**********************";
           exit(0);
       }   

    if(((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0]))&&(arr[1][1]=='X'))
       {
           cout<<"***************"<<player1<<" is the winner**********************";
           exit(0);
       }   
    
    if(((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0]))&&(arr[1][1]=='0'))
       {
           cout<<"***************"<<player2<<" is the winner**********************";
           exit(0);
       }      
}


int main()   
{
    rules();
    
    getch();
    return 0;
}