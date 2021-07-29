#pragma once
class Person {
protected:
    std::string m_name;
    std::string m_gender;
    int m_age;
    float m_weight;
public:
    Person(std::string name, std::string gender, int age, float weight)
        : m_gender(gender), m_name(name), m_age(age), m_weight(weight)
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
    int m_yearsStudy{ 0 };
public:
    static int m_count;
    Student(std::string name, std::string gender, int age, float weight, int yearsStudy)
        :Person(name, gender, age, weight), m_yearsStudy(yearsStudy)
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

    std::string getName() {
        return m_name;
    }

    std::string getColor() {
        return m_color;
    }
};

class Apple : public Fruit {
public:
    Apple(std::string color, std::string name = "apple") : Fruit(name, color) {

    }
};

class Banana : public Fruit {
public:
    Banana() :Fruit("banana", "yellow") {

    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() :Apple("green", "Granny Smith") {};
};

//--------------------------------------------------------------------------------------------------------



void Lesson_1() {
    //--------------------------------------------------------------------------------------------------------
    std::cout << "-------------------" << std::endl;
    Student ivan("Ivan", "man", 18, 70, 2);
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


    //--------------------------------------------------------------------------------------------------------
}