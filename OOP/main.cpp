#include <iostream>
#include <cmath>
#include <string>
#include <cassert>


//--------------------------------------------------------------------------------------------------------------------------------------
//  Создать абстрактный класс Figure(фигура).
//  Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//  Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//  Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//  Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
//--------------------------------------------------------------------------------------------------------------------------------------
const float PI = 3.141592653589;

class Figure {
public:
	//Figure();
	virtual float area() = 0;
};

class Parallelogram : public Figure {
private:
	float m_width{ 0 };
	float m_height{ 0 }; 
public:

	Parallelogram(float width, float height) : m_width(width), m_height(height){}

	float area() override {
		return m_width * m_height;
	}
};

class Circle : public Figure {
private:
	float m_diameter{ 0 };
public:

	Circle(float diameter): m_diameter(diameter){}

	float area() override {
		return PI * ((m_diameter * m_diameter) / 4);
	}
};

class Rectangle : public  Parallelogram {
private:
	float m_width{ 0 };
	float m_height{ 0 };
public:
	Rectangle(float width, float height): Parallelogram(width, height) {
		m_width = width;
		m_height = height;
	}
	float area() override {
		return m_width * m_height; 
	}
};

class Square : public Parallelogram {
private:
	float m_side{ 0 };
public:
	Square(float side) : Parallelogram(side, side), m_side(side) {}
	float area() override {
		return m_side * m_side;
	}
};

class Rhombus : public Parallelogram {
private:
	float m_side{ 0 };
	float m_angle{ 0 };
public:
	Rhombus(float side,float angle):Parallelogram(side,side),m_side(side),m_angle(angle){}
	float area() override {
		std::cout << sin(m_angle)<< std::endl;
		return (m_side * m_side) * sin(m_angle);
	}
};

//--------------------------------------------------------------------------------------------------------------------------------------
//  Создать класс Car(автомобиль) с полями company(компания) и model(модель).
//  Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).
//  От этих классов наследует класс Minivan(минивэн).
//  Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//  Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».
//  Примечание : если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
//--------------------------------------------------------------------------------------------------------------------------------------

class Car {
private:

std::string m_company;
std::string m_model;

public:
	Car(std::string company, std::string model) : m_company(company), m_model(model) {
		std::cout << "constructor Car" << std::endl;
		std::cout << "Company:\t" << m_company << std::endl;
		std::cout << "Model:  \t" << m_model << std::endl;
	
	}
	~Car() {
		std::cout << "destructor Car" << std::endl;
	}
	std::string GetCompany() { return m_company; }
	std::string GetModel() { return m_model; }
};

class PassengerCar : virtual public Car{
public:
	PassengerCar(std::string company, std::string model) : Car(company,model) {
		std::cout << "constructor PassengerCar" << std::endl;
		std::cout << "Company:\t" << GetCompany() << std::endl;
		std::cout << "Model:  \t" << GetModel() << std::endl;
	}
	~PassengerCar() {
		std::cout << "destructor PassengerCar" << std::endl;
	}
};

class Bus : virtual public Car{
public:
	Bus(std::string company, std::string model) : Car(company, model) {
		std::cout << "constructor Bus" << std::endl;
		std::cout << "Company:\t" << GetCompany() << std::endl;
		std::cout << "Model:  \t" << GetModel() << std::endl;
	}
	~Bus() {
		std::cout << "destructor Bus" << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus{
public:
	Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model), Car(company, model) {
		std::cout << "constructor Minivan" << std::endl;
		std::cout << "Company:\t" << GetCompany() << std::endl;
		std::cout << "Model:  \t" << GetModel() << std::endl;
	}
	~Minivan() {
		std::cout << "destructor Minivan" << std::endl;
	}
};

//--------------------------------------------------------------------------------------------------------------------------------------
//  Создать класс : Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить :
//	математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями
//	унарный оператор(-)
//	логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).
//	Примечание : Поскольку операторы < и >= , > и <= — это логические противоположности, попробуйте перегрузить один через другой.
//	Продемонстрировать использование перегруженных операторов.
//--------------------------------------------------------------------------------------------------------------------------------------

class Fraction {
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };
public:
	Fraction() // конструктор по умолчанию
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(int numerator, int denominator = 1) // конструктор с параметрами
	{
		m_numerator = numerator;
		//assert(denominator != 0); // Обработчик ошибок
		if (denominator == 0) {
			std::cout << "ERROR: it is forbidden to divide by zero!" << std::endl;
			std::cout << "ERROR: The default divisor(1) is used!" << std::endl;
			m_denominator = 1;
		}
		else {
			m_denominator = denominator;
		}
	}
	void PrintFraction() {
		std::cout << "Fraction:\t" << m_numerator << "/" << m_denominator << std::endl;
	}
	Fraction operator+(const Fraction& second) {
		Fraction temp;
		temp.m_numerator = (this->m_numerator * second.m_denominator) + (second.m_numerator * this->m_denominator);
		temp.m_denominator = this->m_denominator * second.m_denominator;
		return Fraction(temp.m_numerator,temp.m_denominator);
	}
	Fraction operator-(const Fraction& second) {
		Fraction temp;
		temp.m_numerator = (this->m_numerator * second.m_denominator) - (second.m_numerator * this->m_denominator);
		temp.m_denominator = this->m_denominator * second.m_denominator;
		return Fraction(temp.m_numerator, temp.m_denominator);
	}
	Fraction operator*(const Fraction& second) {
		Fraction temp;
		temp.m_numerator = this->m_numerator * second.m_numerator;
		temp.m_denominator = this->m_denominator * second.m_denominator;
		return Fraction(temp.m_numerator, temp.m_denominator);
	}
};

int main() {
	//----------------------------------------------------
	//Parallelogram parallelogram(15, 10);
	//Circle circle(20);
	//Rectangle rectangle(8, 20);
	//Square square(17);
	//Rhombus rhombus(5, 45);

	//Figure* figure;

	//figure = &parallelogram;
	//std::cout << figure->area() << std::endl;
	//figure = &circle;
	//std::cout << figure->area() << std::endl;
	//figure = &rectangle;
	//std::cout << figure->area() << std::endl;
	//figure = &square;
	//std::cout << figure->area() << std::endl;
	//figure = &rhombus;
	//std::cout << figure->area() << std::endl;
	//----------------------------------------------------
	//std::cout << "-------------------------" << std::endl;
	//Car car{ "Null", "Null" };
	//std::cout << "-------------------------" << std::endl;
	//PassengerCar passengerCar{ "Lada","Sedan" };
	//std::cout << "-------------------------" << std::endl;
	//Bus bus{ "Benc","Bus" };
	//std::cout << "-------------------------" << std::endl;
	//Minivan minivan{ "Fiat","Multipra" };
	//std::cout << "-------------------------" << std::endl;
	//----------------------------------------------------
	Fraction fraction1(1, 3);
	fraction1.PrintFraction();
	Fraction fraction2(2, 5);
	fraction2.PrintFraction();
	std::cout << "-------------------------" << std::endl;
	std::cout << "Addition:" << std::endl;
	Fraction fraction3 = fraction1 + fraction2;
	fraction3.PrintFraction();
	std::cout << "-------------------------" << std::endl;
	std::cout << "Subtraction:" << std::endl;
	fraction3 = fraction1 - fraction2;
	fraction3.PrintFraction();
	std::cout << "-------------------------" << std::endl;
	std::cout << "Multiplication:" << std::endl;
	fraction3 = fraction1 * fraction2;
	fraction3.PrintFraction();
	std::cout << "-------------------------" << std::endl;
	std::cout << "Division:" << std::endl;
	//----------------------------------------------------

	return 0;
}