#pragma once

template<typename T>
class Pair1 {
private:
    T m_data_1;
    T m_data_2;
public:
    Pair1(T data1, T data2);
    //~Pair1();

     T  first()   const { return  m_data_1; }
     T  second()  const { return  m_data_2; }


};

template<typename T>
inline Pair1<T>::Pair1(T data1,T data2)
{
    m_data_1 = data1;
    m_data_2 = data2;
}

void Lesson_5() {
	cout << "Lesson_5\n" << endl;

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    
}


