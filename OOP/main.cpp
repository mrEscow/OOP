



//������� ����������� ����� Figure(������).
//��� ������������ �������� ������ Parallelogram(��������������) � Circle(����).
//����� Parallelogram � ������� ��� ������� Rectangle(�������������), Square(�������), Rhombus(����).
//��� ���� ������� ������� ������������.��� ������ Figure �������� ����� ����������� ������� area() (�������).
//�� ���� ��������� ������� �������������� ��� �������, ������ �� �������������� ������ ���������� �������.

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