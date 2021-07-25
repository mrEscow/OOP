#include <iostream>
#include <string>
#include <cassert> // для assert()

using std::string;
using std::cout;
using std::endl;

//----------------------------------------------------------------------------------------------------------------------------------------------------
//  Добавить в контейнерный класс, который был написан в этом уроке, методы:
//  для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//  для удаления первого элемента массива(аналог pop_front() в векторах)
//  для сортировки массива
//  для вывода на экран элементов.
//----------------------------------------------------------------------------------------------------------------------------------------------------
class ArrayInt
{
private:

    int m_length;
    int* m_data;

    void quickSort(int* array, int low, int high)
    {
        int i = low;
        int j = high;
        int pivot = array[(i + j) / 2];
        int temp;

        while (i <= j)
        {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        if (j > low)
            quickSort(array, low, j);
        if (i < high)
            quickSort(array, i, high);
    }

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

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int* data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int* data = new int[m_length + 1];

        // Копируем все элементы до index-а
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data[index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }
    //----------------------------------------------------------------------------------------------
    void pop_back() { resize(m_length - 1); }

    void pop_front() {

        if(m_length == 1) {
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
    void sort() { quickSort(m_data, 0, m_length - 1); }
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
    //----------------------------------------------------------------------------------------------
    ~ArrayInt()
    {
        delete[] m_data;
    }
};

int main()
{
    ArrayInt array;
    for (int i = 0; i < 3; i++)
    {
        array.push_back(rand() % 100);
    }
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
    return 0;
}




