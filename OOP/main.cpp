#include <cmath>
#include <cstdint>
#include <iostream>

class Power
{
private:

	float m_one{0};
	float m_two{0};

public:

	void SetValue(float one, float two) {
		m_one = one;
		m_two = two;
	}
	float Calculate() {
		return pow(m_one, m_two);
	}
};

class RGBA
{
private:

	std::uint8_t
		m_red{ 0 },
		m_green{ 0 },
		m_blue{ 0 },
		m_alpha{ 255 };

public:

	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
		: m_red(red), m_green(green), m_blue(blue),m_alpha(alpha)
	{
	
	};

	void print() {
		std::cout << "RED\t" << m_red << std::endl;
		std::cout << "GREEN\t" << m_green << std::endl;
		std::cout << "BLUE\t" << m_blue << std::endl;
		std::cout << "ALPHA\t" << m_alpha << std::endl;
	}
};

class Stack
{
private:
	int m_array[10]{ 0 };
	int m_length{ 0 };
public:
	void reset();
	bool push(int value);
	void pop();
	void print();
};

void Stack::reset() {
	m_length = 0;
	for (int i = 0; i < 10; ++i) {
		m_array[i] = 0;
	}
}

bool Stack::push(int value) {
	if (m_length > 9) {
		std::cout << "STACK IS OVER" << std::endl;
		return false;
	}
	else {
		m_array[m_length] = value;
		m_length++;
		return true;
	}
}

void Stack::pop() {
	if (m_length == -1) {
		std::cout << "STACK IS EMPTY" << std::endl;
	}
	else {
		m_array[m_length] = 0;
		m_length--;
	}
}

void Stack::print() {
	std::cout << "(";
	for (int i = 0; i < m_length; ++i) {
		std::cout << " " << m_array[i] << " ";
	}
	std::cout << ")" << std::endl;
}


int main(){

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}

