// Tic Tac Two - @Mathieeeu

#include <iostream>
#include "CSymbol.h"
#include "CGame.h"
using namespace std;

int main()
{
	CGame game;
	game.Start();

	cin.ignore();
	cout << "Press enter to exit...";
	cin.get();
}
