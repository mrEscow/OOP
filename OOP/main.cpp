



//������� ����������� ����� Figure(������).
//��� ������������ �������� ������ Parallelogram(��������������) � Circle(����).
//����� Parallelogram � ������� ��� ������� Rectangle(�������������), Square(�������), Rhombus(����).
//��� ���� ������� ������� ������������.��� ������ Figure �������� ����� ����������� ������� area() (�������).
//�� ���� ��������� ������� �������������� ��� �������, ������ �� �������������� ������ ���������� �������.

const float PI = 3.141592653589;

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
private:
	float m_diameter{ 0 };
public:

	Circle(float diameter): m_diameter(diameter){}

	float area() override {
		return PI * ((m_diameter * m_diameter) / 4);
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