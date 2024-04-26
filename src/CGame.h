#pragma once
#include "CSymbol.h"
#include <iostream>
#include <random>
#include <map>
using namespace std;

class CGame
{
private:
	int m_player;
	CSymbol m_board[3][3];
	map<char, int> m_symbols;
public:
	CGame();
	~CGame();
	void Start();
	void Display();
	bool CheckWin(CSymbol s);
};

