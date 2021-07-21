#include <iostream>
#include <cmath>



//Создать абстрактный класс Figure(фигура).
//Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

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
int main() {

	Parallelogram parallelogram(15, 10);
	Circle circle(20);
	Rectangle rectangle(8, 20);
	Square square(17);
	Rhombus rhombus(5, 45);

	Figure* figure;

	figure = &parallelogram;
	std::cout << figure->area() << std::endl;
	figure = &circle;
	std::cout << figure->area() << std::endl;
	figure = &rectangle;
	std::cout << figure->area() << std::endl;
	figure = &square;
	std::cout << figure->area() << std::endl;
	figure = &rhombus;
	std::cout << figure->area() << std::endl;
	return 0;
}