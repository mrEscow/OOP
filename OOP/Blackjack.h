#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card {
private:

	enum Suit {
		Hearts,
		spades,
		diamonds,
		clubs
	} m_Suit;

	enum  Rank {
		ace = 1,
		deuce,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack = 10,
		queen = 10,
		king = 10
	} m_Rank;

	bool m_isFaceUp;

public:

	bool Flip() {
		return !m_isFaceUp;
	}
	int GetValue() {
		return m_Rank;
	}
};

//---------------------------------------------------------------------------------------------------------------------------------------------
//	����������� ����� Hand, ������� ������������ ����� ��������� ����.
//	� ������ ����� ���� ���� : ������ ���������� ����
//	(������ ������������ ������, �.�.��� �� ���� ������������ ������, � ��� ��� ��������� ������ ���� - ��������� �� ������� ������ Card).
//	����� � ������ Hand ������ ���� 3 ������ :
//	����� Add, ������� ��������� � ��������� ���� ����� �����, �������������� �� ��������� � �������� ��������� ��������� �� ����� �����
//	����� Clear, ������� ������� ���� �� ����
//	����� GetValue, ������� ���������� ����� ����� ���� ����(����� ������������� ����������� ����, ��� ��� ����� ���� ����� 11).
//---------------------------------------------------------------------------------------------------------------------------------------------
class Hard {
	vector<Card*> m_Cards;
public:
	void Add(Card* pCard) {

	}
	void Clear();
	int GetTotal();

};

class GenericPlayer {

};

class Player {

};

class House {

};

class Deck {

};

class Game {
public:
	Game(vector<string> names) {

	}

	void Play() {

	}
};

void Blackjack() {
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		//cin >> numPlayers;
		numPlayers = 1;
	}

	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	// ������� ����
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		//cin >> again;
		again = 'n';
	}


}


