#include "CGame.h"

CGame::CGame()
	: m_player(0), m_symbols({ {'x', 52}, {'o', 31} }), m_board{{CSymbol(), CSymbol(), CSymbol()},
																{CSymbol(), CSymbol(), CSymbol()},
																{CSymbol(), CSymbol(), CSymbol()} }
{
}

CGame::~CGame()
{
}

void CGame::Start()
{
	// player1 = x = red	(52)
	// player2 = o = blue	(31)
	srand(time(NULL));
	m_player = rand() % 2 + 1;
	char symbol;
	int color;
	CSymbol s;

	while (true)
	{
		symbol = m_player == 1 ? 'x' : 'o';
		color = m_symbols[symbol];
		s.SetSymbol(symbol);
		s.SetColor(color);

		Display();

		int x, y;
		cout << "Enter line: ";
		cin >> x;
		cout << "Enter column: ";
		cin >> y;
		x--; y--; // 1-based to 0-based
		if (m_board[x][y].GetSymbol() == '-')
		{
			m_board[x][y] = s;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (m_board[i][j].GetAge() >= 6)
					{
						m_board[i][j].SetSymbol('-');
						m_board[i][j].SetColor(8);
						m_board[i][j].AddAge(-6);
					}
					if (m_board[i][j].GetSymbol() != '-') {
						m_board[i][j].AddAge(1);
					}
				}
			}
			if (CheckWin(s))
			{
				Display();
				cout << '\n' << s << " wins!" << endl;
				break;
			}
			m_player = m_player == 1 ? 2 : 1;
		}
		else
			cout << "Invalid move!" << endl;
	}
}

void CGame::Display() {
	system("cls || clear");

	CSymbol current;
	current.SetSymbol(m_player == 1 ? 'x' : 'o');
	current.SetColor(m_symbols[current.GetSymbol()]);
	cout << "Tic Tac Two" << endl;
	cout << current << "'s turn" << endl << endl;

	for (int i = 0; i < 3; i++) {
		cout << "  ";
		for (int j = 0; j < 3; j++)
			cout << m_board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool CGame::CheckWin(CSymbol s)
{
	// check rows
	for (int i = 0; i < 3; i++)
	{
		if (m_board[i][0] == s && m_board[i][1] == s && m_board[i][2] == s)
		{
			return true;
		}
	}

	// check columns
	for (int i = 0; i < 3; i++)
	{
		if (m_board[0][i] == s && m_board[1][i] == s && m_board[2][i] == s)
		{
			return true;
		}
	}

	// check diagonals
	if (m_board[0][0] == s && m_board[1][1] == s && m_board[2][2] == s)
	{
		return true;
	}
	if (m_board[0][2] == s && m_board[1][1] == s && m_board[2][0] == s)
	{
		return true;
	}

	return false;
}


