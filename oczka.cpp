#include <iostream>
#include <cstdlib>

using namespace std;

char board[7][9];
char kolumny[9]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool end=0;
int temp;
int movesDone=0;
void printBoard();
void getMove(string name, char symbol);
void checkHorizontally(string name, char symbol);
void checkVertically(string name, char symbol);
void checkSlantDown(string name, char symbol);
void checkSlantUp(string name, char symbol);
void checkIfWin(string name, char symbol);
int main(){
	int moveA;
	int moveB;
	string nameA;
	string nameB;
	char A;
	char B;

	system("clear"); 

	//creating an empty board
	for (int i=0; i<7; i++){
		for (int j=0;j<9; j++)
			board[i][j]=' ';
	}
	
	cout<<"Welcome to the game. It is ment for 2 players. Please type the name of the first player: ";
	cin>>nameA;
	cout<<"Now please type the symbol of the player "<<nameA<<": ";
	cin>>A;

	cout<<"This time, type in name  of the second player: ";
	cin>>nameB;
	cout<<"Please type the symbol of the player "<<nameB<<": ";
	cin>>B;
	system("cls");

	while (end==0&&movesDone<63){

		printBoard();
		getMove(nameA, A);
		system("cls");  //pod windowsem "clear" zamienic na "cls"
		checkIfWin(nameA, A);
		printBoard();
		if (end==0&&movesDone<63){
			getMove(nameB, B);
			system("cls");  //pod windowsem "clear" zamienic na "cls"
			checkIfWin(nameB, B);
		}
	}
	if (movesDone>62)
		cout<<"Draw!";
	printBoard();
	cout<<endl;
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
	movesDone++;
}

void checkHorizontally(string name, char symbol){
	for (int i=0; i<7; i++){
		temp=0;
		for (int j=0; j<9; j++){ //zle, musi byc ciagled
			if (board[i][j]==symbol){
				temp++;
			}
			else
				temp=0;

			if (temp==4){
				end=1;
				cout<<"THE END! "<<name<<" wins!"<<endl;
			}
		}
	}
}

void checkVertically(string name, char symbol){
	for (int i=0; i<9; i++){
		temp=0;
		for (int j=0; j<7; j++){
			if (board[j][i]==symbol)
				temp++;
			else
				temp=0;
			if (temp==4){
				end=1;
				cout<<"THE END! "<<name<<" wins!"<<endl;
			}
		}
	}
}

void checkSlantDown(string name, char symbol){
	for (int i=0; i<6; i++){
		for (int j=0; j<4; j++){
			temp=0;
			for (int m=0; m<4; m++){
				if (board[i+m][j+m]==symbol)
					temp++;
				else
					temp=0;
				if (temp==4){
					end=1;
					cout<<"THE END! "<<name<<" wins!"<<endl;
				}
			}
		}
	}
}

void checkSlantUp(string name, char symbol){
	for (int i=3; i<7; i++){
		for (int j=0; j<6; j++){
			temp=0;
			for (int m=0; m<4; m++){
				if (board[i-m][j+m]==symbol)
					temp++;
				else
					temp=0;
				if (temp==4){
					end=1;
					cout<<"THE END! "<<name<<" wins!"<<endl;
						
				}
			}
		}
	}
}

void checkIfWin(string name, char symbol){
	checkHorizontally(name, symbol);
	checkVertically(name, symbol);
	checkSlantDown(name, symbol);
	checkSlantUp(name, symbol);
}