#include <iostream>
#include <string>


//Создать класс Person(человек) с полями : имя, возраст, пол и вес.
//Определить методы переназначения имени, изменения возраста и веса.
// 
//Создать производный класс Student(студент), имеющий поле года обучения.
//Определить методы переназначения и увеличения этого значения.
//Создать счетчик количества созданных студентов.
//В функции main() создать несколько студентов.
//По запросу вывести определенного человека.

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

int main() {
	
	Student ivan("Ivan","man",18,70,2);
	Student vasia("Vasia", "man", 20, 80, 4);
	Student petia("Ivan", "man", 23, 65, 6);
	PrintStydent(vasia);
	return 0;
}