



//Создать абстрактный класс Figure(фигура).
//Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure {
protected:
	Figure();
	virtual float area() = 0;
};

class Parallelogram : protected Figure {
private:
	float m_width{ 0 };
	float m_height{ 0 }; 
public:

	Parallelogram(float width, float height) : m_width(width), m_height(height){}

	float area() override {
		return m_width * m_height;
	}
};

class Circle : protected Figure {
	Circle();
	float area() override {

	}
};

class Rectangle : protected Parallelogram {
	Rectangle();
	float area() override {

	}
};

class Square : protected Parallelogram {
	Square();
	float area() override {

	}
};

class Rhombus : protected Parallelogram {
	Rhombus();
	float area() override {

	}
};
int main() {
	return 0;
}