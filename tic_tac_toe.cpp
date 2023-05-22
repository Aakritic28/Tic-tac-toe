#include<iostream>
#include<ctime>
#include<random>
using namespace std;
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();
int main(){
char mode;
cout<<"Select the mode :computer_vs_player (C) or player_vs_player (P) ";
cin>>mode;
if(mode=='C')computer_vs_player();
else if(mode=='P')player_vs_player();

}

void computer_vs_player(){
  string player_name;
  cout<<"Enter your name: ";
  cin>>player_name;
  while(true){
    system("cls");
    show_board();
    if(count_board('X')==count_board('O')){
      cout<<player_name<<"'s Turn."<<endl;
      get_x_player_choice(); }
      else{

        get_computer_choice();
      }
      char winner=check_winner();
      if(winner=='X'){
        system("cls");
        show_board();
        cout<<player_name<<" Won the game."<<endl;
        break;
      }
      if(winner=='O'){
         system("cls");
        show_board();
        cout<<" Computer won the game."<<endl;
        break;
      }
      else if(winner=='D'){
        cout<<"Game is draw."<<endl;
        break;
      }
 }
}


void get_computer_choice(){
srand(time(0));
int choice;
do{

choice=rand()%9;

if(board[0]==board[1] &&board[0]=='X' &&board[2]==' '){choice=2;break;}
if(board[0]==board[2] &&board[0]=='X' &&board[1]==' '){choice=1;break;}
if(board[2]==board[1] &&board[1]=='X' &&board[0]==' '){choice=0;break;}
if(board[3]==board[4] &&board[3]=='X' &&board[5]==' '){choice=5;break;}
if(board[5]==board[3] &&board[3]=='X' &&board[4]==' '){choice=4;break;}
if(board[4]==board[5] &&board[5]=='X' &&board[3]==' '){choice=3;break;}
if(board[6]==board[7] &&board[6]=='X' &&board[8]==' '){choice=8;break;}
if(board[7]==board[6] &&board[6]=='X' &&board[7]==' '){choice=7;break;}
if(board[7]==board[8] &&board[8]=='X' &&board[6]==' '){choice=6;break;}
if(board[0]==board[3] &&board[0]=='X' &&board[6]==' '){choice=6;break;}
if(board[0]==board[6] &&board[0]=='X' &&board[3]==' '){choice=3;break;}
if(board[3]==board[6] &&board[6]=='X' &&board[0]==' '){choice=0;break;}
if(board[1]==board[4] &&board[1]=='X' &&board[7]==' '){choice=7;break;}
if(board[1]==board[7] &&board[1]=='X' &&board[4]==' '){choice=4;break;}
if(board[4]==board[7] &&board[4]=='X' &&board[1]==' '){choice=1;break;}
if(board[2]==board[8] &&board[2]=='X' &&board[5]==' '){choice=5;break;}
if(board[2]==board[5] &&board[2]=='X' &&board[8]==' '){choice=8;break;}
if(board[5]==board[8] &&board[8]=='X' &&board[2]==' '){choice=2;break;}
if(board[0]==board[4] &&board[0]=='X' &&board[8]==' '){choice=8;break;}
if(board[0]==board[8] &&board[8]=='X' &&board[4]==' '){choice=4;break;}
if(board[4]==board[8] &&board[8]=='X' &&board[0]==' '){choice=0;break;}
if(board[2]==board[4] &&board[2]=='X' &&board[6]==' '){choice=6;break;}
if(board[2]==board[6] &&board[2]=='X' &&board[4]==' '){choice=4;break;}
if(board[4]==board[6] &&board[6]=='X' &&board[2]==' '){choice=2;break;}
if(count_board(' ')==6 &&board[4]==' '){choice=4;break;}
if(count_board(' ')==6 &&board[4]=='O'&&board[0]=='X'&&board[8]=='X'){choice%2==1;break;}
}while(board[choice]!=' ');
board[choice]='O';
}
void get_x_player_choice(){
  while(true){
    cout<<"Select your position(1-9): ";
    int choice;
    cin>>choice;
    choice--;
    if(choice<0 || choice>8){
      cout<<"Please select your choice from(1-9)."<<endl;
    }
    else if(board[choice]!=' '){
      cout<<"Please select an Empty positon."<<endl;
    }
    else{
      board[choice]='X';
      break;
    }
  }
}
void get_o_player_choice(){
  while(true){
    cout<<"Select your position(1-9): ";
    int choice;
    cin>>choice;
    choice--;
    if(choice<0 || choice>8){
      cout<<"Please select your choice from(1-9)."<<endl;
    }
    else if(board[choice]!=' '){
      cout<<"Please select an Empty positon."<<endl;
    }
    else{
      board[choice]='O';
      break;
    }
  }
}

void player_vs_player(){
  string x_player_name,o_player_name;
  cout<<"Enter X player name: ";
  cin>>x_player_name;cout<<endl;
  cout<<"Enter O player name: ";
  cin>>o_player_name;
  while(true){
    system("cls");
    show_board();
    if(count_board('X')==count_board('O')){
      cout<<x_player_name<<"'s Turn."<<endl;
      get_x_player_choice();

    }
    else{
        cout<<o_player_name<<"'s Turn."<<endl;
        get_o_player_choice();
      }
   char winner=check_winner();
   if(winner=='X'){
    system("cls");
    show_board();
    cout<<x_player_name<<" Won the game."<<endl;
    break;
   }
   else if(winner=='O'){
    system("cls");
    show_board();
    cout<<o_player_name<<" Won the game."<<endl;
    break;
   }
   else if(winner=='D'){
    cout<<"The Game is draw"<<endl;
    break;
   }
}
}










int count_board(char symbol){
  int total=0;
  for(int i=0;i<9;i++){
    if(board[i]==symbol)total+=1;
  }
  return total;
}
char check_winner(){
  //checking winner in horizontal/row
  if(board[0]==board[1]&& board[1]==board[2]&& board[0]!=' ')return board[0];
   if(board[3]==board[4]&& board[4]==board[5]&& board[3]!=' ')return board[3];
    if(board[6]==board[7]&& board[7]==board[8]&& board[8]!=' ')return board[6];
    //checking winner in vertical/column
    if(board[0]==board[3]&& board[3]==board[6]&& board[0]!=' ')return board[0];
   if(board[1]==board[4]&& board[4]==board[7]&& board[1]!=' ')return board[1];
    if(board[2]==board[5]&& board[5]==board[8]&& board[2]!=' ')return board[2];
    //checking winner in diagonal
    if(board[0]==board[4]&& board[4]==board[8]&&board[0]!=' ')return board[0];
     if(board[2]==board[4]&& board[4]==board[6]&&board[2]!=' ')return board[2];
     if(count_board('O')+count_board('X')<9)return 'C';
     else return 'D';

}




void show_board(){
    cout<<"    "<<"    |   "<<"    |   "<<endl;
    cout<<"    "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
     cout<<"    "<<"    |   "<<"    |   "<<endl;
     cout<<"-------------------------"<<endl;
    cout<<"    "<<"    |   "<<"    |   "<<endl;
    cout<<"    "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
     cout<<"    "<<"    |   "<<"    |   "<<endl;
      cout<<"-------------------------"<<endl;
    cout<<"    "<<"    |   "<<"    |   "<<endl;
    cout<<"    "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
     cout<<"    "<<"    |   "<<"    |   "<<endl;

}
