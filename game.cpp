#include "iostream"
#include "conio.h"
#include "dos.h"
#include "game.h"
#include "string.h"

using namespace std;
static char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};


void tictactoe :: rules()                 //Displays rules and takes players' names      
{ 
  cout<<"Each player enters the number corresponding to the position of the tile they want to mark in each turn and the first player to successfully make a line pass through their symbol wins\n";
  mat();
  cout<<"The 1st player will be 'X' and the 2nd will be 'O'\n";
  cout<<"Enter the name of the player1:";
  cin>>player1;
  cout<<"\nEnter the name of player2:";
  cin>>player2;

}

void tictactoe :: mat()        //Displays the configuration of the game
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

void tictactoe :: match()       //Executes the match once
{
    int no_of_turns=0;
    int turns=0;                        //swtiching variable to change players' turn 
    int pos,index=0,toggle=0;           
    int check_repeat[9];
    while (no_of_turns<9)              // loop for maximum number of turns per game i.e '9'
    {
     switch(turns)
     {
         case 0: cout<<"\n<--"<<player1<<"'s turn---> \n\n"<<"Enter the position to mark: ";
                 if(cin>>pos)
                 {;}
                 else
                 {
                    cin.clear(); 
                    cin.ignore();
                    continue;
                 }
                 break;  
         
         case 1: cout<<"\n<--"<<player2<<"'s turn---> \n\n"<<"Enter the position to mark: ";
                 if(cin>>pos)
                 {;}
                 else
                 {
                    cin.clear(); 
                    cin.ignore();
                    continue;
                 }
                 break; 
         default: break;                         
     }
     for(int k=0;k<index;k++)                                         // No rewriting on tile is allowed,player is asked to try again
     {
         if (check_repeat[k]==pos)
         {
            cout<<"\n -------Tile already occupied!!!-------"<<endl<<"-------Try again!--------\n";
            toggle=1;
            break;
         }
     }
     if(!(pos<10 && pos>0))
     {
       cout<<"Invalid input........Try again!";
       toggle=1;
     }
     if(toggle==1)
     {
        toggle=0;
        continue;
     }
     check_repeat[index]=pos;
     index++;
     grid(pos,turns,player1,player2);
     result();
     turns=!turns;
     no_of_turns++;
    }
    cout<<"\n ------------------Draw----------------";
    for(int delay=0;delay<32000;delay++)
    for(int d=0;d<32000;d++){};
    exit(0);
}

void tictactoe :: grid(int pos, int turns, char player1[], char player2[])        //Changes and displays the tiles according to input by player
{
    char var;
    if (turns==0)
      var='X';
    else 
      var='O';  
    
    switch(pos)      // Changes the tile(element in matrix) as per player input 
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
            default: break;
                    
              
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
         cout<<arr[i][j]<<"\t";
        cout<<endl; 

    }
}
 
/*void tictactoe :: result()      //Checks win condition and terminates on achieving win condition
{
    int j=0;
    for(int i=0;i<3;i++)          //Checks for horizonatl and vertical win condition
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
     //checks for diagonal win condition
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
} */

void tictactoe :: result()
{
    char cmp1[3],cmp2[3],cmp3[3],cmp4[3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cmp1[j]=char(arr[i][j]);
            cmp2[j]=arr[j][i];
            if(i==j)
            cmp3[j]=arr[i][j];
            if(i+j==2)
            cmp4[j]=arr[i][2-i];
            
        }
     if ((cmp1[0]=='X' && cmp1[1]=='X' && cmp1[2]=='X') ||(cmp2[0]=='X' && cmp2[1]=='X' && cmp2[2]=='X') || (cmp3[0]=='X' && cmp3[1]=='X' && cmp3[2]=='X') || (cmp4[0]=='X' && cmp4[1]=='X' && cmp4[2]=='X'))
     {
           cout<<"***************"<<player1<<" is the winner**********************";
           for(int delay=0;delay<32000;delay++)
            for(int d=0;d<32000;d++){};
           exit(0);
     }  
     else  if ((cmp1[0]=='O' && cmp1[1]=='O' && cmp1[2]=='O') ||(cmp2[0]=='O' && cmp2[1]=='O' && cmp2[2]=='O') || (cmp3[0]=='O' && cmp3[1]=='O' && cmp3[2]=='O') || (cmp4[0]=='O' && cmp4[1]=='O' && cmp4[2]=='O'))
     {
           cout<<"***************"<<player2<<" is the winner**********************";
           for(int delay=0;delay<32000;delay++)
            for(int d=0;d<32000;d++){};
           exit(0);
     }  
    
    }


}
