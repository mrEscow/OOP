



//Создать абстрактный класс Figure(фигура).
//Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure {
	Figure();
	virtual void area()=0;
};

class Parallelogram : Figure {
	Parallelogram();
	void area() override {

	}
};

class Circle : Figure {
	Circle();
	void area() override {

	}
};

class Rectangle : Parallelogram {
	Rectangle();
	void area() override {

	}
};

class Square : Parallelogram {
	Square();
	void area() override {

	}
};

class Rhombus : Parallelogram {
	Rhombus();
	void area() override {

	}
};
int main() {
	return 0;
}