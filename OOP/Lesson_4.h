#pragma once

//--------------------------------------------------------------------------------
//  Добавить в контейнерный класс, который был написан в этом уроке, методы:
//  для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//  для удаления первого элемента массива(аналог pop_front() в векторах)
//  для сортировки массива
//  для вывода на экран элементов.
//--------------------------------------------------------------------------------
class ArrayInt
{
private:

    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];


        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

      
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        
        delete[] m_data;


        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }
    //--------------------------------------------------------------------------
    void pop_back() { resize(m_length - 1); }

    void pop_front() {

        if (m_length == 1) {
            erase();
            return;
        }

        if (m_length > 1) {

            int* data = new int[m_length - 1];

            for (int index = 0; index < m_length - 1; ++index)
                data[index] = m_data[index + 1];

            delete[] m_data;
            m_data = data;
            --m_length;
        }
    }
    void sort() { std::sort(m_data, m_data + m_length); }
    void print() {
        if (m_length > 0) {
            cout << "Array : { ";
            for (int index = 0; index < m_length; index++)
            {
                if (index == m_length - 1)
                    cout << m_data[index] << " ";
                else
                    cout << m_data[index] << ", ";
            }
            cout << "}" << endl;
        }
        else {
            cout << "Array is empty!" << endl;
        }
    }
    //--------------------------------------------------------------------------
    ~ArrayInt()
    {
        delete[] m_data;
    }
};

//---------------------------------------------------------------------
//  Дан вектор чисел, требуется выяснить, сколько среди них различных.
//  Постараться использовать максимально быстрый алгоритм.
//---------------------------------------------------------------------

// Create in function Lesson_4

void Lesson_4() {
    std::cout << "Lesson_4" << std::endl;
    std::cout << "-------------------------" << std::endl;
    ArrayInt array;
    for (int i = 0; i < 3; i++)
        array.push_back(rand() % 100);
    array.print();
    array.sort();
    array.print();
    array.pop_front();
    array.print();
    array.pop_back();
    array.print();
    array.pop_back();
    array.print();
    array.pop_front();
    array.print();
    std::cout << "-------------------------" << std::endl;
    vector<int> vec;
    set<int> set;
    for (int x = 1; x <= 20; x++) {
        for (int i = 0; i < x; ++i) {
            vec.push_back(rand() % 10);
            set.insert(vec[i]);
        }          
        cout << "In vector "<< x << "\t" << set.size() << " different numbers"<< endl;
        vec.clear();
        set.clear();
    }
    std::cout << "-------------------------" << std::endl;
}