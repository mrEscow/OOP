#pragma once

// МЕТОДИЧКА
// ------------------



// ���������� ���������� ���������� � ����������
//-----------------------------------------------


class Day_int
{
private:
    int m_day;
public:
    Day_int(int day = 1) : m_day(day)
    { }
    //Day& operator++();
    //Day& operator--();

    Day_int& operator++();   // ������ �������
    Day_int& operator--();  // ������ �������
    Day_int operator++(int); // ������ ��������
    Day_int operator--(int); // ������ ��������

    void getDay() { std::cout << m_day << endl; }
    void setDey(int day) { m_day = day; }

    // ����������� �������� >
    friend bool operator>(const Day_int& d1, const Day_int& d2)
    {
        return (d1.m_day > d2.m_day);
    }

    //int operator<<(const Day& d)
    //{
    //    return (d.m_day);
    //}

    friend std::ostream& operator<< (std::ostream& out, const Day_int& day)
    {
        //out << "Day(" << day.m_day  << ")";
        out << day.m_day;
        return out;
    }

};

Day_int& Day_int::operator++()
{
    ++m_day;
    // ���� ��������� ���������� m_day �������� 32, �� ��������� ����� �� 1
    //if (m_day >= 32)
    //    m_day = 1;
    // � ��������� ������ ������ ����������� m_day �� �������
    //else


    return *this;
}

Day_int& Day_int::operator--()
{
    --m_day;
    // ���� ��������� ���������� m_day �������� 0, �� ����������� m_day �������� 31
    //if (m_day <= 0)

    //    m_day = 31;
    // � ��������� ������ ������ ��������� m_day �� �������
    //else

    return *this;
}

// ����������� ������ ����������
Day_int Day_int::operator++(int)
{
    // ������� ��������� ������ ������ Day � ������� ��������� ���������� m_day
    Day_int temp(m_day);

    // ���������� �������� ���������� ������ ������� ��� ���������� ���������� ��������� ���������� ������ ��������
    ++(*this); // ���������� ����������

    // ���������� ��������� ������
    return temp;
}

// ����������� ������ ����������
Day_int Day_int::operator--(int)
{
    // ������� ��������� ������ ������ Day � ������� ��������� ���������� m_day
    Day_int temp(m_day);

    // ���������� �������� ���������� ������ ������� ��� ���������� ���������� ��������� ���������� ������ ��������
    --(*this); // ���������� ����������

    // ���������� ��������� ������
    return temp;
}


// ������� �������
//-----------------


template <typename T>
T T_max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
const T& t_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


// ������� �������
//------------------


template <class T> // ������ ������
class Array
{
private:
    int m_length;
    T* m_data;

public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Array(int length)
    {
        m_data = new T[length];
        m_length = length;

    }

    ~Array()
    {

        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        // ��������� m_data �������� nullptr, ����� �� ������ �� �������� ������� ���������!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index)
    {

        //assert(index < 0 || index > m_length);

        return m_data[index];
    }

    int getLength(); // ���������� ����� � ������ ������ getLength() ����
    void print();
    void clear();
};



// �����, ������������ ��� ���� ������, ��������� � ����������� ����������� ������� ������

template <typename T>
int Array<T>::getLength() { return m_length; }
// �������� ��������, ��� ������ - Array<T>, � �� ������ Array


template <typename T>
void Array<T>::print() {

    for (int i = 0; i < m_length; ++i)
    {
        cout << m_data[i] << endl;
    }
}
// �������� ��������, ��� ������ - Array<T>, � �� ������ Array



template <typename T>
void Array<T>::clear() {

    for (int i = 0; i < m_length; ++i)
    {
        m_data[i] = 0;
    }
}
// �������� ��������, ��� ������ - Array<T>, � �� ������ Array





//------------------------------------------------------------
//      �������� non - type �������
//------------------------------------------------------------
//  �������� non - type ������� � ��� ����������� �������� �������, 
//  ������� ���������� �� ����� ������, 
//  � ���������� ���������.
//  ���� ��������� ����� ���� :
//  ������������� �������� ��� ������������;
//  ��������� ��� ������ �� ������ ������;
//  ��������� ��� ������ �� �������;
//  ��������� ��� ������ �� ����� ������.
//------------------------------------------------------------

template <class T, int size> // size �������� ���������� non-type ������� ������
class StaticArray
{
private:
    // �������� non-type ������� ������ �������� �� ������ ����������� �������
    T m_array[size];

};

//  ����� ������������� ������� �������
//---------------------------------------

template <class T>
class Day_T
{
private:
    T m_day;
public:
    Day_T(T day)
    {
        m_day = day;
    }

    ~Day_T()
    { }

    void print()
    {
        cout << m_day << '\n';
    }
};

template <>
Day_T<char*>::Day_T(char* day)
{
    // ���������� ����� day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, �������� ����-����������

    // �������� ������ ��� �������� �������� day
    m_day = new char[length];

    // �������� ����������� �������� day � m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}

template <>
Day_T<char*>::~Day_T()
//Repository<char*>::~Repository()
{
    delete[] m_day;
}

//  ����� ������������� ������� ������
//-------------------------------------


template <class T>
class Day_T2
{
private:
    T m_day[8];

public:
    void set(int index, const T& day)
    {
        m_day[index] = day;
    }

    const T& get(int index)
    {
        return m_day[index];
    }
};


//  ��������� ������������� �������
//----------------------------------

// ������ ������
template< typename T, typename S > class B {};
// ��� ��������� �������������
template< typename U > class B< int, U > {};

template <class T, int size>
class StaticArray2
{
    // ���������� ������ StaticArray
};

// ��������� ������������� ������� ������
template <int size>
class StaticArray2<double, size>
{
    // ���������� �������� ������������������� ������� ������
};

// ������ �������� ������
template <class T, int size>
class StaticArray_Base
{
    // ���������� ������ StaticArray_Base
};

// ������ ������������ ������
template <class T, int size>
class StaticArray5 : public StaticArray_Base<T, size>
{
    // ��������� ��������� ���������� StaticArray_Base,
    // ����������� ������ �� �����
};

// �������� ������������������ ������ ������ ��� ���� double
template <int size>
class StaticArray5<double, size> : public StaticArray_Base<double, size>
{
    // ���������� �������� ������������������� ������� ������
};

//  ��������� ������������� �������� � ���������
//------------------------------------------------
// ����� ������ ������ Day
template <class T>
class Day_T3
{
private:
    T m_day;
public:
    Day_T3(T day)
    {
        m_day = day;
    }

    ~Day_T3()
    { }

    void print()
    {
        cout << m_day << '\n';
    }
};

// ��������� ������������� ������� ������ Day ��� ������ � ������ ����������
template <typename T>
class Day_T3<T*>
{
private:
    T* m_day;
public:
    Day_T3(T* day) // T - ��� ���������
    {
        // ��������� �������� �����������
        m_day = new T(*day); // ����� ���������� ������ ���� ��������� ��������
    }
    ~Day_T3()
    {
        delete m_day; // � ����� ����������� �������� ����� ��������
    }

    void print()
    {
        cout << *m_day << '\n';
    }
};

// ����� ������ ������ Day ��� ������ �� � �����������
template <class T>
class Day_T4
{
private:
    T m_day;
public:
    Day_T4(T day)
        //Repository(T day)
    {
        m_day = day;
    }

    ~Day_T4()
    { }

    void print()
    {
        cout << m_day << '\n';
    }
};

// ��������� ������������� ������� ������ Day ��� ������ � �����������
template <class T>
class Day_T4<T*>
{
private:
    T* m_day;
public:
    Day_T4(T* day)
    {
        m_day = new T(*day);
    }

    ~Day_T4()
    {
        delete m_day;
    }

    void print()
    {
        cout << *m_day << '\n';
    }
};
//}
// ������ ������������� ������� ������������ ������ Day ��� ������ � ����� char*
template <>
Day_T4<char*>::Day_T4(char* day)
{
    // ���������� ����� day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, �������� ����-����������

    // �������� ������ ��� �������� �������� day
    m_day = new char[length];



    // �������� ����������� �������� day � m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}

// ������ ������������� ������� ����������� ������ Day ��� ������ � ����� char*
template<>
Day_T4<char*>::~Day_T4()
{
    delete[] m_day;
}

// ������ ������������� ������� ������ print ��� ������ � ����� char*
// ��� ����� ����� Day<char*> ������ �� � ������ Day<T*>::print(), 
// ������� ������� ������ ���� �������� (� ������ �� ������� C-style - ������ ������ ������)
template<>
void Day_T4<char*>::print()
{
    std::cout << m_day;
}









//  MyDay
//-----------------------------------------------------------------------------------------------
template<class T>
class MyDay {
private:
    T m_day;
public:

    MyDay(T day);

    ~MyDay();

    void print();
};


template<class T>
inline MyDay<T>::MyDay(T day)
{
    m_day = day;
}

template<class T>
inline void MyDay<T>::print()
{
    cout << m_day << endl;
}

template <>
MyDay<char*>::MyDay(char* day) 
{
    // ���������� ����� day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, �������� ����-����������

    // �������� ������ ��� �������� �������� day
    m_day = new char[length];

    // �������� ����������� �������� day � m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];

}

template <>
MyDay<char*>::~MyDay()
{
    delete[] m_day;
}



//-----------------------------------------------------------------------------------------------
void Metoda()
{
    cout << "------------------" << endl;

    Day_int day(31);
    day.getDay();
    (++day).getDay();
    (--day).getDay();
    (--day).getDay();
    (day++).getDay();
    (day).getDay();
    (day--).getDay();
    (day).getDay();


    cout << "------------------" << endl;


    int i = t_max(4, 8);
    cout << i << '\n';

    double d = t_max(7.56, 21.434);
    cout << d << '\n';

    char ch = t_max('b', '9');
    cout << ch << '\n';


    cout << "------------------" << endl;


    Day_int seven(7);
    Day_int twelve(12);


    Day_int bigger = t_max(seven, twelve);
    bigger.getDay();


    cout << "------------------" << endl;


    cout << "--------Array<int> intArray(10);----------" << endl;

    Array<int> intArray(5);

    intArray.clear();

    cout << intArray[0] << endl;

    intArray.print();

    cout << "--------Array<Day> dayArray(31);----------" << endl;

    Array<Day_int> dayArray(5);

    dayArray.clear();

    dayArray[0].getDay();

    dayArray.print();

    Array<double> doubleArray(10);

    cout << "------------------" << endl;

    StaticArray<int, 10>;

    cout << "------------------" << endl;

    // ��������� ������������� ������ ��� �������� ������ ������ ������� ������
    Day_T<int> myDay(6);
    myDay.print();

    // ��������� ������ � ����� ��������� ��� �������� ������ ��������� ������������� �������
    int x = 8;
    Day_T<int*> myintptr(&x);

    // ���� �� � myintptr ����������� ������������� ����������� (������������ ���������),
    // �� ��������� �������� x �������� �� � �������� myintptr
    x = 10;
    myintptr.print();




    cout << "------------------" << endl;
    cout << "------------------" << endl;
    cout << "------------------" << endl;

    // ����������� �������� ��������� ������
    char* First_day = new char[40]{ "First" };

    //// ��������� �����
    MyDay<char*> myNewDay(First_day);

    //// ������� ��������� ������
    delete[] First_day;
    //
    //// ������� ���
    myNewDay.print();

    //// ������� ��������� ������
    //delete[] name;

    //// ������� ���
    //myname.print();



    cout << "------------------" << endl;
    cout << "------------------" << endl;
    cout << "------------------" << endl;


}