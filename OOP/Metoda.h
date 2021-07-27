#pragma once

// МЕТОДИЧКА
// ------------------



// Перегрузка операторов инкремента и декремента
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

    Day_int& operator++();   // версия префикс
    Day_int& operator--();  // версия префикс
    Day_int operator++(int); // версия постфикс
    Day_int operator--(int); // версия постфикс

    void getDay() { std::cout << m_day << endl; }
    void setDey(int day) { m_day = day; }

    // перегружаем оператор >
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
    // Если значением переменной m_day является 32, то выполняем сброс на 1
    //if (m_day >= 32)
    //    m_day = 1;
    // в противном случае просто увеличиваем m_day на единицу
    //else


    return *this;
}

Day_int& Day_int::operator--()
{
    --m_day;
    // Если значением переменной m_day является 0, то присваиваем m_day значение 31
    //if (m_day <= 0)

    //    m_day = 31;
    // в противном случае просто уменьшаем m_day на единицу
    //else

    return *this;
}

// постфиксная версия инкремента
Day_int Day_int::operator++(int)
{
    // Создаем временный объект класса Day с текущим значением переменной m_day
    Day_int temp(m_day);

    // Используем оператор инкремента версии префикс для реализации перегрузки оператора инкремента версии постфикс
    ++(*this); // реализация перегрузки

    // возвращаем временный объект
    return temp;
}

// постфиксная версия декремента
Day_int Day_int::operator--(int)
{
    // Создаем временный объект класса Day с текущим значением переменной m_day
    Day_int temp(m_day);

    // Используем оператор декремента версии префикс для реализации перегрузки оператора декремента версии постфикс
    --(*this); // реализация перегрузки

    // возвращаем временный объект
    return temp;
}


// Шаблоны функций
//-----------------


template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
const T& t_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


// Шаблоны классов
//------------------


template <class T> // шаблон класса
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
        // Указываем m_data значение nullptr, чтобы на выходе не получить висячий указатель!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index)
    {

        //assert(index < 0 || index > m_length);

        return m_data[index];
    }

    int getLength(); // определяем метод и шаблон метода getLength() ниже
    void print();
    void clear();
};



// метод, определенный вне тела класса, нуждается в собственном определении шаблона метода

template <typename T>
int Array<T>::getLength() { return m_length; }
// обратите внимание, имя класса - Array<T>, а не просто Array


template <typename T>
void Array<T>::print() {

    for (int i = 0; i < m_length; ++i)
    {
        cout << m_data[i] << endl;
    }
}
// обратите внимание, имя класса - Array<T>, а не просто Array



template <typename T>
void Array<T>::clear() {

    for (int i = 0; i < m_length; ++i)
    {
        m_data[i] = 0;
    }
}
// обратите внимание, имя класса - Array<T>, а не просто Array





//------------------------------------------------------------
//      Параметр non - type шаблона
//------------------------------------------------------------
//  Параметр non - type шаблона — это специальный параметр шаблона, 
//  который заменяется не типом данных, 
//  а конкретным значением.
//  Этим значением может быть :
//  целочисленное значение или перечисление;
//  указатель или ссылка на объект класса;
//  указатель или ссылка на функцию;
//  указатель или ссылка на метод класса.
//------------------------------------------------------------

template <class T, int size> // size является параметром non-type шаблона класса
class StaticArray
{
private:
    // параметр non-type шаблона класса отвечает за размер выделяемого массива
    T m_array[size];

};

//  Явная специализация шаблона функции
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
    // Определяем длину day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор

    // Выделяем память для хранения значения day
    m_day = new char[length];

    // Копируем фактическое значение day в m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}

template <>
Day_T<char*>::~Day_T()
//Repository<char*>::~Repository()
{
    delete[] m_day;
}

//  Явная специализация шаблона класса
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


//  Частичная специализация шаблона
//----------------------------------

// шаблон класса
template< typename T, typename S > class B {};
// его частичная специализация
template< typename U > class B< int, U > {};

template <class T, int size>
class StaticArray2
{
    // реализация класса StaticArray
};

// частичная специализация шаблона класса
template <int size>
class StaticArray2<double, size>
{
    // реализация частично специализированного шаблона класса
};

// шаблон базового класса
template <class T, int size>
class StaticArray_Base
{
    // реализация класса StaticArray_Base
};

// шаблон производного класса
template <class T, int size>
class StaticArray5 : public StaticArray_Base<T, size>
{
    // полностью наследует функционал StaticArray_Base,
    // собственные методы не нужны
};

// частично специализированный шаблон класса для типа double
template <int size>
class StaticArray5<double, size> : public StaticArray_Base<double, size>
{
    // реализация частично специализированного шаблона класса
};

//  Частичная специализация шаблонов и указатели
//------------------------------------------------
// Общий шаблон класса Day
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

// частичная специализация шаблона класса Day для работы с типами указателей
template <typename T>
class Day_T3<T*>
{
private:
    T* m_day;
public:
    Day_T3(T* day) // T - тип указателя
    {
        // Выполняем глубокое копирование
        m_day = new T(*day); // здесь копируется только одно отдельное значение
    }
    ~Day_T3()
    {
        delete m_day; // а здесь выполняется удаление этого значения
    }

    void print()
    {
        cout << *m_day << '\n';
    }
};

// Общий шаблон класса Day для работы не с указателями
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

// Частичная специализация шаблона класса Day для работы с указателями
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
// Полная специализация шаблона конструктора класса Day для работы с типом char*
template <>
Day_T4<char*>::Day_T4(char* day)
{
    // Определяем длину day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор

    // Выделяем память для хранения значения day
    m_day = new char[length];



    // Копируем фактическое значение day в m_day
    for (int count = 0; count < length; ++count)
        m_day[count] = day[count];
}

// Полная специализация шаблона деструктора класса Day для работы с типом char*
template<>
Day_T4<char*>::~Day_T4()
{
    delete[] m_day;
}

// Полная специализация шаблона метода print для работы с типом char*
// Без этого вывод Day<char*> привел бы к вызову Day<T*>::print(), 
// которое выводит только одно значение (в случае со строкой C-style - только первый символ)
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
    // Определяем длину day
    int length = 0;
    while (day[length] != '\0')
        ++length;
    ++length; // +1, учитывая нуль-терминатор

    // Выделяем память для хранения значения day
    m_day = new char[length];

    // Копируем фактическое значение day в m_day
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

    Array<int> intArray(10);

    intArray.clear();

    cout << intArray[0] << endl;

    intArray.print();

    cout << "--------Array<Day> dayArray(31);----------" << endl;

    Array<Day_int> dayArray(31);

    dayArray.clear();

    dayArray[0].getDay();

    dayArray.print();

    Array<double> doubleArray(10);

    cout << "------------------" << endl;

    StaticArray<int, 10>;

    cout << "------------------" << endl;

    // Объявляем целочисленный объект для проверки работы общего шаблона класса
    Day_T<int> myDay(6);
    myDay.print();

    // Объявляем объект с типом указателя для проверки работы частичной специализации шаблона
    int x = 8;
    Day_T<int*> myintptr(&x);

    // Если бы в myintptr выполнилось поверхностное копирование (присваивание указателя),
    // то изменение значения x изменило бы и значение myintptr
    x = 10;
    myintptr.print();




    cout << "------------------" << endl;
    cout << "------------------" << endl;
    cout << "------------------" << endl;

    // Динамически выделяем временную строку
    char* First_day = new char[40]{ "First" };

    //// Сохраняем число
    MyDay<char*> myNewDay(First_day);

    //// Удаляем временную строку
    delete[] First_day;
    //
    //// Выводим имя
    myNewDay.print();

    //// Удаляем временную строку
    //delete[] name;

    //// Выводим имя
    //myname.print();



    cout << "------------------" << endl;
    cout << "------------------" << endl;
    cout << "------------------" << endl;



}