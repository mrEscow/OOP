#pragma once



class Date {
	int m_day{ 0 };
	int m_month{ 0 };
	int m_year{ 0 };

public:
    friend ostream& operator<< (ostream& out, const Date& date) {
        return out << "Date: " << date.m_day << "." << date.m_month << "." << date.m_year;
    }

	void SetDay(int day) {
		m_day = day;
	}

	void SetMonth(int month) {
		m_month = month;
	}

	void SetYear(int year) {
		m_year = year;
	}

	int GetDay() {
		return m_day;
	}

	int GetMonth() {
		return m_month;
	}

	int GetYear() {
		return m_year;
	}
};



Date CompareTwoData(unique_ptr<Date> &date1, unique_ptr<Date> &date2) {

	if (date1.get()->GetYear() > date2.get()->GetYear()) return* date1;
	if (date1.get()->GetYear() < date2.get()->GetYear()) return*date2;

	if (date1.get()->GetMonth() > date2.get()->GetMonth()) return*date1;
	if (date1.get()->GetMonth() < date2.get()->GetMonth()) return*date2;

	if (date1.get()->GetDay() > date2.get()->GetDay()) return*date1;
	if (date1.get()->GetDay() < date2.get()->GetDay()) return*date1;

	return *date1;
}
void SharingResources(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
	unique_ptr<Date> temp(new Date());
	temp = move(date1);
	date1 = move(date2);
	date2 = move(temp);
}


void Lesson_7() {
	cout << "Lesson_7" << endl;
	cout << "----------------" << endl;
	{
		unique_ptr<Date> today(new Date());
		unique_ptr<Date> date(new Date());

		today.get()->SetDay(9);
		today.get()->SetMonth(8);
		today.get()->SetYear(2021);

		cout << *today << endl;

		cout << "----------------" << endl;

		date = move(today);
		cout << *date << endl;

		cout << "----------------" << endl;

		if (today) cout << "today not_nullptr" << endl;
		else cout << "today nullptr" << endl;

		if (date) cout << "date not_nullptr" << endl;
		else cout << "date nullptr" << endl;
	}
	cout << "----------------" << endl;
	{
		unique_ptr<Date> date1(new Date());
		date1.get()->SetDay(1);
		date1.get()->SetMonth(1);
		date1.get()->SetYear(2021);

		unique_ptr<Date> date2(new Date());
		date2.get()->SetDay(31);
		date2.get()->SetMonth(12);
		date2.get()->SetYear(2021);

		cout << "-Two_Date:-" << endl;

		cout << *date1 << endl;
		cout << *date2 << endl;

		cout << "-CompareTwoData:-" << endl;

		Date newDate = CompareTwoData(date1, date2);

		cout << newDate << endl;
		cout << "----------------" << endl;
		cout << "-Two_Date:-" << endl;

		cout << *date1 << endl;
		cout << *date2 << endl;

		cout << "-SharingResources:-" << endl;

		SharingResources(date1, date2);

		cout << *date1 << endl;
		cout << *date2 << endl;

	}
	cout << "----------------" << endl;
}