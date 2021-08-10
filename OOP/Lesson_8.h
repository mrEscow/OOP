#pragma once


#pragma execution_character_set("utf-8")

//----------------------------------------------------------------------------------------------------------------------------------
//	Написать шаблонную функцию div, 
//	которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0. 
//	В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
//----------------------------------------------------------------------------------------------------------------------------------

namespace LS_8{
	template<typename T1, typename T2>
	T2 div(T1 one, T2 two) {
		if (two == 0)
			throw "DivisionByZero";
		return one / two;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра.
//	Написать класс Bar, хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
//	Если y + a > 100, возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.
//	В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//	Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
//	В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Ex {
	float x;
public:
	Ex(float x) : x{x} {}
	float getError() { return x; }
};

class Bar {
	float y;
public:
	Bar() : y{0} {}

	void set(float a) {
		if ((y + a) > 100)
			throw Ex(a* y);
		else
			y = a;
	}
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//	Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.
//	Эти методы должны запускать классы - исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда(направление не находится в нужном диапазоне).
//	Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
//	Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class Robot {
public:
	class ExRobot {
		string m_error;
		string m_dir;
		string m_pos;

	public:
		ExRobot(string error) {

			if (error == "OffTheField") {
				m_error = "OffTheField";
			}
			if (error == "IllegalCommand") {
				m_error = "IllegalCommand";
			}
		}
		void PrintError(Robot& robot) {
			switch (robot.GetDir())
			{
			case Robot::RIGHT:
				m_dir = "RIGHT";
				break;
			case Robot::LEFT:
				m_dir = "LEFT";
				break;
			case Robot::UP:
				m_dir = "UP";
				break;
			case Robot::DOWN:
				m_dir = "DOWN";
				break;
			default:
				m_dir = "Error!";
				break;
			}
			m_pos = robot.GetPos();
			cout << "****************" << endl;
			cout << "ROBOT ERROR:\n";
			cout << m_error << "\n";
			cout << "DIR:  " << m_dir << "\n";
			cout << "SIZE: " << robot.m_size << "\n";
			cout << "POS:  " << m_pos << "\n";
			cout << "****************" << endl;
		}
	};
public:
	enum Dir {
		RIGHT,
		LEFT,
		UP,
		DOWN,
	};

	Robot(){
		map[y][x] = 1;
		PrintRobotPos();
	}
	void GoOnNewPosition(Dir dir, int size) {
		m_size = size;
		if(size <= 0)
			throw ExRobot("IllegalCommand");
		map[y][x] = 0;

		switch (dir)
		{
		case Robot::RIGHT:
			if (x + size > 9)
				throw ExRobot("OffTheField");
			x += size;
			break;
		case Robot::LEFT:
			if (x - size < 0)
				throw ExRobot("OffTheField");
			x -= size;
			break;
		case Robot::UP:
			if (y - size < 0)
				throw ExRobot("OffTheField");
			y -= size;
			break;
		case Robot::DOWN:
			if (y + size > 9)
				throw ExRobot("OffTheField");
			y += size;
			break;
		default:
			throw ExRobot("IllegalCommand");
			break;
		}
		map[y][x] = 1;
		PrintRobotPos();
	}
	void PrintRobotPos() {
		cout << "Robot on map: " << endl;
		for (size_t i_y = 0; i_y < 10; i_y++)
		{
			for (size_t j_x = 0; j_x < 10; j_x++)
			{
				cout << map[i_y][j_x];
			}
			cout << endl;
		}
	}
	void SetDir(Dir dir) {
		m_dir = dir;
	}
	Dir GetDir() {
		return m_dir;
	}
	string GetPos() {
		return  "x = " + to_string(x) + " y = " + to_string(y);
	}
private:
	int map[10][10]{ 0 };
	int x{ 0 }, y{ 0 };
	int m_size{ 0 };
	Dir m_dir;
};

void Lesson_8() {
	cout << "Lesson_8" << endl;
	cout << "----------------" << endl;
	{
		try {
			cout << LS_8::div(2.5, 0.0) << endl;
		}
		catch (const char*) {
			cout << "Nenene na null delit nelzia" << endl;
		}
		catch (...) {
			// эллипсис(…)
		}
	}
	cout << "----------------" << endl;
	{
		//Bar bar;
		//float a{-1};
		//try {
		//	while (a != 0) {
		//		cout << "Input float please: ";
		//		cin >> a;
		//		bar.set(a);				
		//	}
		//}
		//catch(Ex& a){
		//	cout << "EX: " << a.getError() <<  endl;
		//}
	}
	cout << "----Robot----" << endl;
	{
		Robot robot;
		char again = 'y';
		while (again != 'n' && again != 'N')
		{
			cout << "\nDo you want to play with the robot? (Y/N): ";
			cin >> again;

			int dir{ -1 };
			int size{ 0 };
			cout << "Input dir:\n 0 = RIGHT\n 1 = LEFT\n 2 = UP\n 3 = DOWN\n:  ";
			cin >> dir;
			if (dir == 0)
				robot.SetDir(robot.RIGHT); 
			if (dir == 1)
				robot.SetDir(robot.LEFT);
			if (dir == 2)
				robot.SetDir(robot.UP);
			if (dir == 3)
				robot.SetDir(robot.DOWN);
			cout << "Input size:  ";
			cin >> size;
			try {
				robot.GoOnNewPosition(robot.GetDir(), size);
			}
			catch (Robot::ExRobot &error) {
				error.PrintError(robot);
			}
		}
	}
	cout << "----------------" << endl;
}