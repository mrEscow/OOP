
#include <iostream>
#include <string>
#include <cassert> // ��� assert()
#include <vector>
#include <algorithm>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::set;



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
    //----------------------------------------------------------------------------------------------
    ~ArrayInt()
    {
        delete[] m_data;
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------
//  ��� ������ �����, ��������� ��������, ������� ����� ��� ���������.
//  ����������� ������������ ����������� ������� ��������.
//----------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------------------------
//  ����������� ����� Hand, ������� ������������ ����� ��������� ����.
//  � ������ ����� ���� ���� : ������ ���������� ����
//  (������ ������������ ������, �.�.��� �� ���� ������������ ������, � ��� ��� ��������� ������ ���� - ��������� �� ������� ������ Card).
//  ����� � ������ Hand ������ ���� 3 ������ :
//    ����� Add, ������� ��������� � ��������� ���� ����� �����, �������������� �� ��������� � �������� ��������� ��������� �� ����� �����
//    ����� Clear, ������� ������� ���� �� ����
//    ����� GetValue, ������� ���������� ����� ����� ���� ����(����� ������������� ����������� ����, ��� ��� ����� ���� ����� 11).
//----------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    //--------------------------------------------------------------------------------------
    //ArrayInt array;
    //for (int i = 0; i < 3; i++)
    //    array.push_back(rand() % 100);
    //array.print();
    //array.sort();
    //array.print();
    //array.pop_front();
    //array.print();
    //array.pop_back();
    //array.print();
    //array.pop_back();
    //array.print();
    //array.pop_front();
    //array.print();
    //--------------------------------------------------------------------------------------
    //vector<int> vec;
    //set<int> set;
    //for (int x = 1; x <= 20; x++) {
    //    for (int i = 0; i < x; ++i) {
    //        vec.push_back(rand() % 10);
    //        set.insert(vec[i]);
    //    }          
    //    cout << set.size() << endl;
    //    vec.clear();
    //    set.clear();
    //}
    //--------------------------------------------------------------------------------------

    Blackjack();  //  #include "Blackjack.h"  !!!

    return 0;
}

#include "Header.h"  



int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	Metoda();

	Lesson_1();
	Lesson_2();
	Lesson_3();
	Lesson_4();
	Lesson_5();
	Lesson_6();
	Lesson_7();
	Lesson_8();

	Blackjack(); 
  
  return 0;
}




