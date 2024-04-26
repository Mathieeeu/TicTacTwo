#pragma once
#include <iostream>
using namespace std;
class CSymbol
{
private: 
	char m_symbol;
	int m_color;
	int m_age;
public:
	CSymbol();
	~CSymbol();
	void SetSymbol(char symbol);
	void SetColor(int color);
	char GetSymbol();
	int GetColor();
	void AddAge(int age);
	int GetAge();
	friend ostream& operator<<(ostream& os, const CSymbol& symbol);
	bool operator==(const CSymbol& symbol);
};

