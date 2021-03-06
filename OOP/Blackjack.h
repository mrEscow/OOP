#pragma once


//--------------------------------------------------------------------------------------------------------------------------------------
//	Начиная с этого урока, будем с использованием полученных знаний по ООП создавать игру Blackjack.
//	Суть проста : раздаются карты, за каждую из которых начисляются очки.
//	Игрок пытается заработать 21 очко, не больше.За каждую карту с числом дается столько очков, сколько на ней указано.
//	За туз — либо 1 очко, либо 11 (что больше подходит игроку), а за валета, даму и короля — по 10 очков.
//	Компьютер выступает дилером и играет против группы от одного до семи игроков.
//	В начале кона все участники, включая дилера, получают две карты.
//	Игроки могут видеть все свои карты, а также сумму очков.Однако одна из карт дилера скрыта на протяжении всего кона.
//	Далее каждый игрок может брать дополнительные карты.
//	Если сумма очков у него превысит 21, он проигрывает.
//	Когда все игроки получили возможность набрать дополнительные карты, дилер открывает скрытую карту.
//	Далее он обязан брать новые карты до тех пор, пока сумма его очков не превышает 16. 
//	Если у дилера перебор, все игроки, не имеющие перебора, побеждают.
//	В противном случае сумма очков каждого из оставшихся игроков сравнивается с суммой очков дилера.
//	Игрок побеждает, если сумма его очков больше, чем у дилера.В противном случае — проигрывает.
//	Если суммы очков игрока и дилера одинаковы, засчитывается ничья.
//--------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------
//  Создание классов для игры Blackjack:
//---------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------------
//	Создать класс Card, описывающий карту в игре БлэкДжек.
//	У этого класса должно быть три поля : масть, значение карты и положение карты(вверх лицом или рубашкой).
//	Сделать поля масть и значение карты типом перечисления(enum).Положение карты - тип bool.
//	Также в этом классе должно быть два метода :
//	метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
//--------------------------------------------------------------------------------------------------------------------------------------



class Card {
public:
	enum Suit { hearts, spades, diamonds, clubs } ;
	enum Rank {
		ace = 1,
		deuce, three, four, five, six, seven, eight, nine, ten,
		jack = 10,
		queen = 10,
		king = 10
	} ;

	
private:
	Suit m_Suit;
	Rank m_Rank;
	bool m_isFaceUp;

public:
	Card(Rank rank, Suit suit, bool ifu) : m_Rank(rank), m_Suit(suit), m_isFaceUp(ifu) {}
	void Flip() {
		m_isFaceUp = !m_isFaceUp;
	}

	int GetValue() {

		int value = 0;
		if (m_isFaceUp) {
			value = m_Rank;
		}
		return value;
	}
	//	Если карта перевернута рубашкой вверх(мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
	friend ostream& operator<< (ostream& out, Card& card) {
		if (card.m_isFaceUp) {
			string suit;
			switch (card.m_Suit)	
			{
			case hearts:
				suit = "hearts";
			case spades:
				suit = "spades";
			case diamonds:
				suit = "diamonds";
			case clubs:
				suit = "clubs";
			default:
				break;
			}
			

			out << "Card: " << suit << "\t" << card.m_Rank;
		}
			
		else
			out << "XX";
		return out;
	}
};

//---------------------------------------------------------------------------------------------------------------------------------------------
//	Реализовать класс Hand, который представляет собой коллекцию карт.
//	В классе будет одно поле : вектор указателей карт(удобно использовать вектор, 
//	т.к.это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).
//	Также в классе Hand должно быть 3 метода :
//	метод Add, который добавляет в коллекцию карт новую карту, 
//	соответственно он принимает в качестве параметра указатель на новую карту
//	метод Clear, который очищает руку от карт
//	метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).
//---------------------------------------------------------------------------------------------------------------------------------------------

class Hand {
public:
	vector<Card*> m_Cards;

public:
	Hand() { m_Cards.reserve(7); }
	
	virtual ~Hand(); 


	void Add(Card* pCard) {
		m_Cards.push_back(pCard);
	}

	void Clear() {
		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}
		m_Cards.clear();

	}

	int GetTotal() const {
		if (m_Cards.empty()) return 0;
		if (m_Cards[0]->GetValue() == 0) return 0;
		int sum{ 0 };
		for (auto card : m_Cards) 
			sum += card->GetValue();
		bool containsAce = false;
		for (auto card : m_Cards)
			if (card->GetValue() == Card::ace)
				containsAce = true;
		if (containsAce && sum <= 11)		
			sum += 10;
		
			
		return sum;
	}


};


Hand::~Hand() { Clear(); }

//------------------------------------------------------------------------------------------------------------------------
//	Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
//	который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.
//	Создать класс GenericPlayer, в который добавить поле name - имя игрока.Также добавить 3 метода:
//	IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//	IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//	Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
//------------------------------------------------------------------------------------------------------------------------

class GenericPlayer : public Hand{
protected:
	string m_name;

public:
	GenericPlayer(string name) : m_name(name) {}
	//virtual ~GenericPlayer();

	// показывает, хочет ли игрок продолжать брать карты
	// Для класса GenericPlayer функция не имеет своей реализации,
	// т.к. для игрока и дилера это будут разные функции
	virtual bool IsHitting() const = 0;

	// возвращает значение, если у игрока перебор -
	// сумму очков большую 21
	// данная функция не виртуальная, т.к. имеет одинаковую реализацию
	// для игрока и дилера
	bool IsBoosted() const {
		return (GetTotal() > 21);

		//if (GetTotal() > 21)
		//	return true;
		//else
		//	return false;
	}

	// объявляет, что игрок имеет перебор
	// функция одинакова как для игрока, так и для дилера
	void Bust() const{
		cout << m_name << " has too many points!" << endl;
	}

	// вывод должен отображать имя игрока и его карты, а также общую сумму очков его карт.
	friend ostream& operator<< (ostream& out, GenericPlayer& gp) {
		
		out << "\nPlayer: " << gp.m_name << "\n" << "Cards:\n"; 
		for (auto c : gp.m_Cards)
			out << *c << "\n";
		out << "Total: " << gp.GetTotal();
		return out;
	}
};

//------------------------------------------------------------------------------------------------------------------------
//	Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
//	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
//	Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
//	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
//	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
//------------------------------------------------------------------------------------------------------------------------

class Player : public GenericPlayer{
private:

public:
	Player(string name) :GenericPlayer(name){}
	//virtual ~Player();

	bool IsHitting() const {
		if (GetTotal() < 21) {
			char answer;
			cout << m_name <<  ", do you need another card ?  Y/N :  ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				return true;
			else
				return false;
		}
		else
			return false;
	}
	void Win() const {
		cout << "Player " << m_name << " is win!" << endl;
	}
	void Lose() const {
		cout << "Player " << m_name << " is lose!" << endl;
	}
	void Push() const {
		cout << "Player " << m_name << " played a draw!" << endl;
	}
};

//------------------------------------------------------------------------------------------------------------------------
//	Реализовать класс House, который представляет дилера.Этот класс наследует от класса GenericPlayer.
//	У него есть 2 метода:
//	virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.
//	Если у дилера не больше 16 очков, то он берет еще одну карту.
//	void FlipFirstCard() - метод переворачивает первую карту дилера.
//------------------------------------------------------------------------------------------------------------------------

class House : public GenericPlayer {
public:
	House():GenericPlayer("Diler"){}
	//virtual ~House();
	virtual bool IsHitting() const {
		return GetTotal() < 16;
		//if (GetTotal() < 16)
		//	return true;
		//else
		//	return false;
	}
	void FlipFirstCard() {
		if(m_Cards[0]->GetValue() == 0)
			m_Cards[0]->Flip();
	}
	void FlipSecondCard() {
		m_Cards[1]->Flip();
	}
};

//-------------------------------------------------------------------------------------------------------------------------------------------
//	Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.
//	Класс Deck имеет 4 метода:
//	vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
//	void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
//	vold Deal(Hand& aHand) - метод, который раздает в руку одну карту
//	void AddltionalCards(GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
//	Обратите внимание на применение полиморфизма.В каких методах применяется этот принцип ООП ?
//-------------------------------------------------------------------------------------------------------------------------------------------

class Deck :  public Hand {
public:
	Deck(){
		m_Cards.reserve(52);
		Populate();
	 }
    //virtual ~Deck();
	void Populate() { // - Создает стандартную колоду из 52 карт, вызывается из конструктора.
		Clear();
		// создает стандартную колоду
		for (int s = Card::hearts; s <= Card::clubs; ++s)
		{
			for (int r = Card::ace; r <= Card::king + 3; ++r)
			{
				Add(new Card(static_cast<Card::Rank>(r),
					static_cast<Card::Suit>(s),false));
			}
		}

	}
	void Shuffle() { //- Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
		random_shuffle(m_Cards.begin(), m_Cards.end());
	}
	void Deal(Hand& aHand) { // - метод, который раздает в руку одну карту
		if (!m_Cards.empty())
		{
			if(aHand.m_Cards.size() > 1)
				m_Cards.back()->Flip();
			aHand.Add(m_Cards.back());				
			m_Cards.pop_back();	
		}
		else
		{
			cout << "Out of cards. Unable to deal.";
		}

	}
	void AddltionalCards(GenericPlayer& aGenerlcPlayer) { // - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
		cout << endl;
		// продолжает раздавать карты до тех пор, пока у игрока не случается
		// перебор или пока он хочет взять еще одну карту
		while (!aGenerlcPlayer.IsBoosted() && aGenerlcPlayer.IsHitting())
		{
			Deal(aGenerlcPlayer);
			
			cout << aGenerlcPlayer << endl;

			if (aGenerlcPlayer.IsBoosted())
			{
				aGenerlcPlayer.Bust();
			}
		}

	}
};

//--------------------------------------------------------------------------------------------------------
//	Реализовать класс Game, который представляет собой основной процесс игры.У этого класса будет 3 поля:
//	колода карт
//	рука дилера
//	вектор игроков.
//	Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
//	В конструкторе создается колода карт и затем перемешивается.
//	Также класс имеет один метод play().
//	В этом методе раздаются каждому игроку по две стартовые карты, а первая карта дилера прячется.
//	Далее выводится на экран информация о картах каждого игра, в т.ч.и для дилера.
//	Затем раздаются игрокам дополнительные карты.
//	Потом показывается первая карта дилера и дилер набирает карты, если ему надо.
//	После этого выводится сообщение, кто победил, а кто проиграл.В конце руки всех игроков очищаются.
//--------------------------------------------------------------------------------------------------------


class Game {
private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;

public:
	Game(const vector<string> names) {
		// создает вектор игроков из вектора с именами
		vector<string>::const_iterator pName;
		for (pName = names.begin(); pName != names.end(); ++pName)
		{
			m_Players.push_back(Player(*pName));
		}

		// запускает генератор случайных чисел
		srand(static_cast<unsigned int>(time(0)));
		m_Deck.Populate();
		m_Deck.Shuffle();
	}

	//~Game();

	void Play() {
		// раздает каждому по две стартовые карты
		vector<Player>::iterator pPlayer;
		for (int i = 0; i < 2; ++i)
		{

			for ( pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			{
				m_Deck.Deal(*pPlayer);
			}
			m_Deck.Deal(m_House);
		}

		// прячет первую карту дилера
		m_House.FlipFirstCard();

		// открывает руки всех игроков
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			for (auto card : pPlayer->m_Cards)
				card->Flip();
			cout << *pPlayer << endl;
		}
		cout << m_House << endl;

		//cout << "system pause 1" << endl;
		//system("pause");

		// раздает игрокам дополнительные карты
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.AddltionalCards(*pPlayer);
		}

		// показывает первую карту дилера
		m_House.FlipSecondCard();
		cout << endl << m_House;

		//cout << "system pause 2" << endl;
		//system("pause");

		// раздает дилеру дополнительные карты
		m_Deck.AddltionalCards(m_House);

		//cout << "system pause 3" << endl;
		//system("pause"); 

		if (m_House.IsBoosted())
		{
			// все, кто остался в игре, побеждают
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			{
				if (!(pPlayer->IsBoosted()))
				{
					pPlayer->Win();
				}
			}
		}
		else
		{
			// сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
				++pPlayer)
			{
				if (!(pPlayer->IsBoosted()))
				{
					if (pPlayer->GetTotal() > m_House.GetTotal())
					{
						pPlayer->Win();
					}
					else if (pPlayer->GetTotal() < m_House.GetTotal())
					{
						pPlayer->Lose();
					}
					else
					{
						pPlayer->Push();
					}
				}
			}

		}
		//cout << "system pause 4" << endl;
		//system("pause");
		// очищает руки всех игроков
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			pPlayer->Clear();
		}
		m_House.Clear();

	}
};

//--------------------------------------------------------------------------------------------------------------------------------------
//	Написать перегрузку оператора вывода для класса Card.
//	Если карта перевернута рубашкой вверх(мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
//	Также для класса GenericPlayer написать перегрузку оператора вывода, 
//	который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
//--------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------
//	Написать функцию main() к игре Блекджек.
//	В этой функции вводятся имена игроков.
//	Создается объект класса Game и запускается игровой процесс.
//	Предусмотреть возможность повторной игры.
//-------------------------------------------------------------


void Blackjack() {
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;

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



	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}


}