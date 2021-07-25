#include <iostream>
#include <string>
#include <cassert> // ��� assert()

using std::string;
using std::cout;
using std::endl;

//----------------------------------------------------------------------------------------------------------------------------------------------------
//  �������� � ������������ �����, ������� ��� ������� � ���� �����, ������:
//  ��� �������� ���������� �������� �������(������ ������� pop_back() � ��������)
//  ��� �������� ������� �������� �������(������ pop_front() � ��������)
//  ��� ���������� �������
//  ��� ������ �� ����� ���������.
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

        // ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // ������� resize �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
    void resize(int newLength)
    {
        // ���� ������ ��� ������ ����� � return
        if (newLength == m_length)
            return;

        // ���� ����� ������� ������ ������ � ������ ��� � ����� return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // ������ �����, ��� newLength >0
        // �������� ����� ������
        int* data = new int[newLength];

        // ����� ����� ����������� � ����������� ���������� ��������� � ����� ������
        // ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // ���������� �������� ��������
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // ������� ������ ������, ��� ��� �� ��� ��� �� �����
        delete[] m_data;

        // � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
        // �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������. ���������
        // ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // �������� ������������ ������������� �������
        assert(index >= 0 && index <= m_length);

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length + 1];

        // �������� ��� �������� �� index-�
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        // ��������� ����� ������� � ����� ������
        data[index] = value;

        // �������� ��� �������� ����� ������������ ��������
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // ������� ������ ������ � ���������� ������ ���� ����� 
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




