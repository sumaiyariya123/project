#include <iostream>
#include <stdlib.h>

using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,colum;
bool draw = false;


void display_board(){
    system("cls");
//    clrscr()
    cout << "\n\t\tT i c k   C r o s s    G a m e\n" << endl;
    cout << "\tPlayer1 [X] \n\tPlayer2 [0]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout << "\t\t     |     |     \n";
}
void player_turn(){
    int choice;

    if(turn == 'X')
    cout << "\n\tPlayer1 [X] Turn:";
    if(turn == '0')
    cout << "\n\tPlayer2 [0] Turn:";

    cin>>choice;

    switch(choice)
    {
        case 1: row =0,colum =0; break;
        case 2: row =0,colum =1; break;
        case 3: row =0,colum =2; break;
        case 4: row =1,colum =0; break;
        case 5: row =1,colum =1; break;
        case 6: row =1,colum =2; break;
        case 7: row =2,colum =0; break;
        case 8: row =2,colum =1; break;
        case 9: row =2,colum =2; break;
        default:
            cout<<"invalid Choice\n";
            break;
    }
    if(turn == 'X' && board[row][colum]!='X' && board[row][colum]!='0')
    {
        board[row][colum] = 'X';
        turn = '0';
    }
    else if(turn == '0' && board[row][colum]!='X' && board[row][colum]!='0')
    {
        board[row][colum] = '0';
        turn = 'X';
    }
    else
    {
        cout<<"Box Already Filled!\n Please Try again!!\n\n";
        player_turn();
    }
    display_board();
}
bool gameover()
{
    //check win
    for (int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return false;


    //if there any box not filled
    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
    if (board[i][j] != 'X' && board[i][j] != '0')
        return true;


    //deaw
    draw = true;
    return false;


}

int main()
{

    while(gameover())
    {
    display_board();
    player_turn();
    gameover();
    }

if (turn == 'X' && draw == false)
cout<<"\n\tPlayer 2 [0] Wins!!! Congratulations\n";
else if (turn == '0' && draw == false)
cout<<"\n\tPlayer 1 [X] Wins!!! Congratulations\n";
else
cout<<"\n\tGAME DRAW!!! \n";

}

