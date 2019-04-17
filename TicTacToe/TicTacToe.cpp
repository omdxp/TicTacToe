// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct Player {
	int id;
	string name;
};
char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int checkwin();
void board();

int main()
{
	Player player1, player2;
	int player = 1, i, choice;
	// Filling names of players
	cout << "Enter name for player 1: ";
	player1.id = 1;
	getline(cin, player1.name);
	cout << "Enter name for player 2: ";
	player2.id = 2;
	getline(cin, player2.name);
	char mark;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;
		if (player == 1)
		{
			cout << "Player " << player1.id << ": '" << player1.name << "', enter a number: ";
		}
		else
		{
			cout << "Player " << player2.id << ": '" << player2.name << "', enter a number: ";
		}
		cin >> choice;
		mark = (player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout << "Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i = checkwin();
		player++;
	} while (i == -1);
	board();
	if (i == 1)
		if (player1.id == --player)
		{
			cout << "==>\aPlayer '" << player1.name << "' win ";
		}
		else
		{
			cout << "==>\aPlayer '" << player2.name << "' win ";
		}
	else
		cout << "==>\aGame draw";
	cin.ignore();
	cin.get();
	return 0;
}
/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
	cout << endl;
	cout << " | | " << endl;
	cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << " | | " << endl;
	cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << " | | " << endl;
	cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;
	cout << " | | " << endl << endl;
}

/*******************************************************************
END OF PROJECT
********************************************************************/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
