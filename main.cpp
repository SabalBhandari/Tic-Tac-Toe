#include <iostream>

using namespace std;

char square[10] ={'1','2','3','4','5','6','7','8','9'};

void winner_check(char val){

    if (val == 'X')
    {
        cout<<endl<<"Player1 won!"<<endl;
        exit(0);
    }
    else{
        cout<<endl<<"Player2 won!"<<endl;
        exit(0);
    }

}

int checkWin()
{

    if (
        ((square[0] == square[1]) && (square[0]==square[2]))||
        ((square[0] == square[3]) && (square[0]==square[6]))||
        ((square[0] == square[4]) && (square[0]==square[8]))
        )
    {
        return 0;
        // winner_check(square[0]);
    }
    else if (
        ((square[1] == square[4]) && (square[1]==square[7]))
        )
    {
        return 1;
        // winner_check(square[1]);
    }
    else if (
        ((square[2] == square[5]) && (square[2]==square[8]))
        )
    {
        return 2;
        // winner_check(square[2]);
    }
    else if (
        ((square[3] == square[4]) && (square[3]==square[5]))
        )
    {
        return 3;
        // winner_check(square[3]);
    }
    else if (
        ((square[6] == square[7]) && (square[6]==square[8]))
        )
    {
        return 6;
        // winner_check(square[6]);
    }
    else if (
        ((square[2] == square[4]) && (square[2]==square[6]))
        )
    {
        return 2;
        // winner_check(square[2]);
    }
    else
    {
        return -1;
    }
}

void board(){

    system("clear");
    
    cout<<"Player 1 'X' --- Player 2 'O'"<<endl<<endl;

    cout<<"     |       |     "<<endl;

    cout<<"  "<<square[0]<<"  |   "<<square[1]<<"   |  "<<square[2]<<endl;

    cout<<"_____|_______|_____"<<endl;
    cout<<"     |       |     "<<endl;

    cout<<"  "<<square[3]<<"  |   "<<square[4]<<"   |  "<<square[5]<<endl;

    cout<<"_____|_______|_____"<<endl;

    cout<<"     |       |     "<<endl;

    cout<<"  "<<square[6]<<"  |   "<<square[7]<<"   |  "<<square[8]<<endl;

    cout<<"     |       |     "<<endl;

}
void checkDraw(int move){
    
    if (move>=9){

        cout<<"DRAW!"<<endl;
        exit(0);

    }
    
}

int main(){

    board();
    int ch,i =0;
    int moveCounter = 0;
    //  checkWin()== 0
    while (i<=5)
    {
        top:
        system("cls");
        board();
        cout<<"Player1:";
        cin>>ch;
        if (square[ch-1]!= 'X' && square[ch-1]!='O')
        {

            square[ch-1] = 'X';
            
        }
        else{
            goto top;
        }
        moveCounter++;
        board();
        checkDraw(moveCounter);
        if (checkWin()>=0)
        {
            winner_check(square[checkWin()]);
        }
        if (i == 5)
        {
            if (checkWin()<=0)
            {
                winner_check(square[checkWin()]);
            }
            else{
                cout<<"DRAW!"<<endl;
            }
        }
        
        top2:
        system("cls");
        board();
        cout<<"Player2:";
        cin>>ch;
        if (square[ch-1]!= 'X' && square[ch-1]!='O')
        {
            
            square[ch-1] = 'O';
            
        }
        else{

            goto top2;

        }
        moveCounter++;
        board();
        checkDraw(moveCounter);
        if (checkWin()>=0)
        {
            winner_check(square[checkWin()]);
        }
    }
    

    return 0;

}