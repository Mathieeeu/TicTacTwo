#include "CSymbol.h"


CSymbol::CSymbol()
	: m_symbol('-'), m_color(8), m_age(0)
{
}

CSymbol::~CSymbol()
{
}

void CSymbol::SetSymbol(char symbol)
{
	m_symbol = symbol;
}

void CSymbol::SetColor(int color)
{
		m_color = color;
}

char CSymbol::GetSymbol()
{
	return m_symbol;
}

int CSymbol::GetColor()
{
	return m_color;
}

void CSymbol::AddAge(int age)
{
	m_age += age;
}

int CSymbol::GetAge()
{
	return m_age;
}

bool CSymbol::operator==(const CSymbol& symbol)
{
	return m_symbol == symbol.m_symbol;
}

ostream& operator<<(ostream& os, const CSymbol& symbol)
{
	if (symbol.m_age >= 6) {
		os << "\033[5m";
		if (symbol.m_color == 52) {
			os << "\033[38;5;9";
		}
		else if (symbol.m_color == 31) {
			os << "\033[38;5;37";
		}
	}
	else {
		os << "\033[38;5;" << symbol.m_color;
	}
	os << "m" << symbol.m_symbol << "\033[0m";
	return os;
}
