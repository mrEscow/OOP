#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>



class Person {
protected:
	std::string m_name;
	std::string m_gender;
	int m_age;
	float m_weight;
public:
	Person(std::string name, std::string gender, int age,float weight) 
		: m_gender(gender), m_name(name),m_age(age),m_weight(weight)
	{

	};

	void SetName(std::string name) {
		m_name = name;
	}
	void SetAge(int age) {
		m_age = age;
	}
	void SetWeight(float weight) {
		m_weight = weight;
	}
};

class Student : public Person {
private:
	int m_yearsStudy{0};
public:
	static int m_count;
	Student(std::string name, std::string gender, int age, float weight, int yearsStudy) 
		:Person(name, gender,age, weight),m_yearsStudy(yearsStudy) 
	{
		m_count++;
	};

	void SetYearsStudy(int yearsStudy) {
		m_yearsStudy = yearsStudy;
	}

	void SetYearsStudy() {
		m_yearsStudy++;
	}

	friend void PrintStydent(const Student& student);
};


int Student::m_count{ 0 };

void PrintStydent(const Student& student) {
	std::cout << "Student:" << std::endl;
	std::cout << "Name:\t" << student.m_name << std::endl;
	std::cout << "Gender:\t" << student.m_gender << std::endl;
	std::cout << "Age:\t" << student.m_age << std::endl;
	std::cout << "Weight:\t" << student.m_weight << std::endl;
	std::cout << "Years of study:\t" << student.m_yearsStudy << std::endl;
}

//--------------------------------------------------------------------------------------------------------

class Fruit {

	std::string m_name;
	std::string m_color;

public:

	Fruit(std::string name, std::string color) {
		m_name = name;
		m_color = color;
	}

	std::string getName(){
		return m_name;
	}

	std::string getColor() {
		return m_color;
	}
};

class Apple : public Fruit{
public:
	Apple(std::string color, std::string name = "apple") : Fruit(name, color){
		
	}
};

class Banana : public Fruit {
public:
	Banana() :Fruit("banana", "yellow") {

	}
};

class GrannySmith : public Apple  {
public:
	GrannySmith() :Apple("green", "Granny Smith") {};
};

//--------------------------------------------------------------------------------------------------------

int K = -1;
const char* title[] = { "6","7","8","9","10","J","Q","K","A" };

struct Card
{
    unsigned int value : 4;
    unsigned int mast : 2;
    unsigned int ves : 4;
};
#define size 36

class Coloda
{
    Card card[size];
public:
    Coloda()
    {
        for (int i = 0; i < size; i++)
        {
            card[i].value = i % 9;
            card[i].mast = i % 4;
            if (card[i].value >= 0 && card[i].value <= 4) card[i].ves = card[i].value + 6;
            else if (card[i].value == 8)
                card[i].ves = 11;
            else
            {
                card[i].ves = card[i].value - 3;
            }
        }
    }
    void PaintCard(bool comp, int value = 0, int mast = 0)
    {
        if (comp)
        {
            std::cout << " ----- \n";
            std::cout << "| *** |\n";
            std::cout << "| *** |\n";
            std::cout << "| *** |\n";
            std::cout << " ----- \n";
        }
        else
        {
            std::cout << " ----- \n";
            std::cout << "|" << char(card[value].mast + 3) << "    |\n";
            std::cout << "|  " << title[card[value].value] << "  |\n";
            std::cout << "|     |\n";
            std::cout << " ----- \n";
        }
    }

    void GetCard(int& Player, int& Comp, char ans = 'y')
    {

        K++;
        Player += card[K].ves;
        PaintCard(false, K, card[K].mast);

        K++;
        Comp += card[K].ves;
        PaintCard(true, K, card[K].mast);


        Proverka(Player, Comp, false);
    }

    void Shuffle()
    {
        for (int i = 0; i < size; i++)
        {
            int k = rand() % 35;
            int tmp = card[k].value, tmp1 = card[k].mast, tmp2 = card[k].ves;
            card[k].value = card[i].value;
            card[k].mast = card[i].mast;
            card[k].ves = card[i].ves;

            card[i].value = tmp;
            card[i].mast = tmp1;
            card[i].ves = tmp2;
        }
    }
    void Proverka(int Player, int Comp, bool end)
    {
        if (end)
        {
            if (Player<21 && Player>Comp)
            {
                std::cout << "Player wins! With " << Player << "\n";
                std::cout << "Comp louse! With " << Comp << "\n";
            }
            else if (Player > 21)
            {
                std::cout << "Player louse!\n";
                std::cout << "Comp have " << Comp << "\n";
            }

            if (Comp<21 && Comp>Player)
            {
                std::cout << "Comp wins! With " << Comp << "\n";
                std::cout << "Player louse! With " << Player << "\n";
            }
            else if (Comp > 21)
            {
                std::cout << "Comp louse!\n";
                std::cout << "Player have " << Player << "\n";
            }
        }
        else
            std::cout << "Player have: " << Player << "\n";
    }

    void Play(int& Player, int& Comp)
    {
        char ans;
        std::cout << "Press 'q' to exit\n";
        do
        {
            std::cout << "Continue play and get one card?(y/n)\n";
            std::cin >> ans;
            if (ans == 'y')
                GetCard(Player, Comp);
            else if (ans == 'n')
            {
                Proverka(Player, Comp, true);
                break;
            }
        } while (ans != 'q');
    }


    void Print(int i)
    {
        std::cout << title[card[i].value] << " " << char(card[i].mast + 3) << " ";//<<card[i].ves<<"\n";            
    }
    void PrintAll()
    {
        for (int i = 0; i < size; i++)
            std::cout << title[card[i].value] << " " << char(card[i].mast + 3) << " " << card[i].ves << "\n";
    }
};

//--------------------------------------------------------------------------------------------------------

int main() {
    //--------------------------------------------------------------------------------------------------------
	std::cout << "-------------------" << std::endl;
	Student ivan("Ivan","man",18,70,2);
	Student vasia("Vasia", "man", 20, 80, 4);
	Student petia("Ivan", "man", 23, 65, 6);
	PrintStydent(vasia);
    //--------------------------------------------------------------------------------------------------------
	std::cout << "-------------------" << std::endl;
	Apple a("red");	
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    //--------------------------------------------------------------------------------------------------------
	std::cout << "-------------------" << std::endl;

	std::cout << "https://add-hobby.ru/blackjack.html" << std::endl;
    std::cout << "https://www.cyberforum.ru/cpp-beginners/thread89417.html" << std::endl;

    Coloda k1;
    srand(time(0));
    k1.Shuffle();

    int Player = 0, Comp = 0;

    for (int i = 0; i < 2; i++)
        k1.GetCard(Player, Comp);


    k1.Play(Player, Comp);


    //--------------------------------------------------------------------------------------------------------
	return 0;
}