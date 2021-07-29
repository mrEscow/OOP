#pragma once

//----------------------------------------------------------------------------------------------------------
//	������� ���������, ������� ��������� ����� ����� ���� int.
//	� ��������� ������� �� ������ : ���� ������������ ������ ��� - �� ����� ������ �������������� ��������, 
//	����� ������� ��������� �� ������ � ���������� ������ ����� ��� ���.
//	������ ������������ ��������� ����� :
//	rbtrb
//	nj34njkn
//	1n
//----------------------------------------------------------------------------------------------------------

class ReadInt {
private:
    int m_date{ 0 };
    bool m_is_empty{ 1 };
public:
 

     friend istream& operator>> (istream& in, ReadInt& date){
         while (true)
         {
             cout << "Enter a int value: ";
             double a;
             // �������� ��������, �������� date (������ ������ ReadInt) ������ ���� �� �����������, ����� �� ����� ����������� �������� ����� ������
             in >> date.m_date;

             // �������� �� ���������� ����������
             if (in.fail()) // ���� ���������� ���������� ��������� ���������,
             {
                 in.clear(); // �� ���������� cin � '�������' ����� ������
                 in.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
                 cout << "Oops, that input is invalid.  Please try again." << endl;
             }
             else
             {
                 in.ignore(32767, '\n'); // ������� ������ �������� 
                 date.m_is_empty = !true;
                 return in;
             }
         }
     }

     friend ostream& operator<< (ostream& out, const ReadInt& date){
         if (!date.m_is_empty) {
             out << date.m_date;
             return out;
         }
         else {
             cout << "The object of the ReadInt class is empty." << endl;
             return out;
         }
     }

};


//-------------------------------------------------------------------------------------------------------------------------------
//	������� ����������� ����������� endll ��� ������������ ������ ������, ������� ������� ��� �������� ������ � ���������� �����.
//-------------------------------------------------------------------------------------------------------------------------------

ostream& endll (ostream& out){  
    out << "\n" << endl;
    return out;
}



void Lesson_6() {
	cout << "Lesson_6" << endl;
	cout << "----------------" << endl;
    ReadInt readint;
    cin >> readint;
    cout << readint << endl;
    cout << "----------------" << endl;   
    cout << "doble endl" << endll;
    cout << "----------------" << endl;
}