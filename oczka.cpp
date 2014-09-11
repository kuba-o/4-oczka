#include <iostream>
#include <cstdlib>

using namespace std;

char board[7][9];
char kolumny[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printBoard();
void getMove(string name, char symbol);
int checkHorizontally(string name, char symbol);
int checkVertically(string name, char symbol);

int main(){
	int moveA;
	int moveB;
	string nameA;
	string nameB;
	char A;
	char B;
	int zero=0;
	int* temp = &zero;

	//creating an empty board
	for (int i=0; i<7; i++){
		for (int j=0;j<9; j++)
			board[i][j]=' ';
	}
	/*	
	cout<<"Welcome to the game. It is ment for 2 players. Please type the name of the first player: ";
	cin>>nameA;
	cout<<"Now please type the symbol of the player "<<nameA<<": ";
	cin>>A;

	cout<<"This time, type in name  of the second player: ";
	cin>>nameB;
	cout<<"Please type the symbol of the player "<<nameB<<": ";
	cin>>B;
	*/
	nameA = 'A';
	A = 'a';
	nameB = 'B';
	B = 'b';
	/*
	board[3][5]='a';
	board[4][5]='a';
	board[5][5]='a';
	board[6][5]='a';
	*/
	int end;
	while (1){

		printBoard();
		getMove(nameA, A);
		checkHorizontally(nameA, A);
		checkVertically(nameA, A);
		printBoard();
		getMove(nameB, B);
		checkHorizontally(nameB, B);
		checkVertically(nameB, B);
	}	
	return 0;
}

void printBoard(){
	for (int i=0; i<7; i++){
		for (int j=0;j<9; j++){
			cout<<board[i][j]<<"|   ";
		}
		cout<<endl;
	}	
	for (int i=0; i<50; i++)
		cout<<"_";
	cout<<endl;
	for (int i=0; i<9; i++)
		cout<<kolumny[i]<<"    ";
}

void getMove(string name, char symbol){
	int move;
	int temp;
	do {
		cout<<endl<<"Give me the column for the move of the "<<name<<" player: ";
		cin>>move;
	}  while (board[0][move-1]!=' ' || move<1 || move>9);

	if (board[0][move-1]==' '){
		for (int i=0; i<8; i++){

		if (board[i][move-1]==' '){
			temp=i;
			}
		}	
	board[temp][move-1]=symbol;
	}
	temp=0;
}

int checkHorizontally(string name, char symbol){
	int temp;
	for (int i=0; i<7; i++){
		temp=0;
		for (int j=0; j<9; j++){ //zle, musi byc ciagled
			if (board[i][j]==symbol){
				temp++;
			}
			else
				temp=0;

			if (temp==4){
				cout<<"THE END! "<<name<<" wins!"<<endl;
				return 0;
			}
		}
	}
	return 0;
}

int checkVertically(string name, char symbol){
	int temp;
	
	for (int i=0; i<9; i++){
		temp=0;
		for (int j=0; j<7; j++){
			if (board[j][i]==symbol)
				temp++;
			else
				temp=0;
			if (temp==4){
				cout<<"THE END! "<<name<<" wins!"<<endl;
				return 0;
			}
		}
	}
	return 0;
}