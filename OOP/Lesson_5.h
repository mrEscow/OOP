#pragma once

//------------------------------------------------------------------------------------------------------
// ����������� ������ ������ Pair1, ������� ��������� ������������ ���������� ������ ������ ���� ������.
//------------------------------------------------------------------------------------------------------

template<typename T>
class Pair1 {
private:
    T m_data_1;
    T m_data_2;
public:
    Pair1(T data1, T data2);
    //~Pair1();
    T  first()    { return  m_data_1; }
    T  second()   { return  m_data_2; }

    T  first()   const { return  m_data_1; }
    T  second()  const { return  m_data_2; }

};

template<typename T>
inline Pair1<T>::Pair1(T data1,T data2)
{
    m_data_1 = data1;
    m_data_2 = data2;
}

//------------------------------------------------------------------------------------------------
// ����������� ����� Pair, ������� ��������� ������������ ������ ���� ������ � ������������ �����.
//------------------------------------------------------------------------------------------------

template<typename T1, typename T2>
class Pair {
private:
    T1 m_data_1;
    T2 m_data_2;
public:
    Pair(T1 data1, T2 data2);
    //~Pair();

    T1  first()   const { return  m_data_1; }
    T2  second()  const { return  m_data_2; }

};

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair(T1 data1, T2 data2)
{
    m_data_1 = data1;
    m_data_2 = data2;
}

//--------------------------------------------------------------------------------------------------------------
// �������� ������ ������ StringValuePair, � ������� ������ �������� ������ ���� string, � ������ � ������ ����.
// ���� ������ ������ ������ ����������� �������� ������������������ ����� Pair, 
// � ������� ������ �������� � string, � ������ � ������ ���� ������.
//--------------------------------------------------------------------------------------------------------------

template<typename Type>
class StringValuePair : public Pair<string, Type> {
public:
    StringValuePair(string str, Type data) : Pair<string, Type> (str, data){}
};

// ���������: ��� ������ ������������ ������ Pair �� ������������ ������ StringValuePair �� �������� �������, ��� ��������� ��������� � ������ Pair.

void Lesson_5() {
    cout << "Lesson_5" << endl;
    cout << "----------------" << endl;
    {
        Pair1<int> p1(6, 9);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
        
        const Pair1<double> p2(3.4, 7.8);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    cout << "----------------" << endl;
    {
        Pair<int, double> p1(6, 7.8);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair<double, int> p2(3.4, 5);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    cout << "----------------" << endl;
    {
        StringValuePair<int> svp("Amazing", 7);
        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    }
    cout << "----------------" << endl;
}


