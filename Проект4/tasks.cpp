#include "dates.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	short nz, answer;
	int year, month, day;
	char s;

	do
	{
		cout << "1 - Проверка на равенство двух дат(операция = =)" << endl
			<< "2,3 - Изменение даты на указанное число дней(операции +=, -=)" << endl
			<< "4,5 - Сложение и вычитание двух дат(операции + , -)" << endl
			<< "введите номер задания, либо 0 - для выхода: ";
		cin >> nz;
		system("cls");

		switch (nz)
		{
		case 0:
		{
			exit(0);
		}break;

		case 1:
		{
			cout << "enter the first date(12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date one(day, month, year);
			cout << "enter the second date(12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date two(day, month, year);
			int result = (one == two);
			if (result == 1)
				cout << "\nэти две даты одинаковые\n";
			else 	cout << "\nэти две даты НЕ одинаковые\n";
		}break;

		case 2:
		{
			int num;
			cout << "введите дату(н. 12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date one(day, month, year);
			cout << "введите количество дней, чтобы изменить дату на указанное число дней: ";
			cin >> num;
			one += num;
			cout << one.getDay() << "." << one.getMonth ()<< "." << one.getYear ()<< endl;
		}break;

		case 3:
		{
			int num;
			cout << "введите дату(н. 12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date one(day, month, year);
			cout << "введите количество дней, чтобы изменить дату на указанное число дней: ";
			cin >> num;
			one -= num;
			cout << one.getDay() << "." << one.getMonth() << "." << one.getYear() << endl;
		}break;

		case 4 :
		{
			cout << "enter the first date(12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date one(day, month, year);
			cout << "enter the second date(12.12.2012): "; cin >> day >> s >> month >> s >> year;
			date two(day, month, year);
			date result = one + two;
			cout << result.getDay() << "." << result.getMonth() << "." << result.getYear() << endl;


		}break;
		
		case 5:
		{

		}break;

		}

		cout << endl;
		cout << "хотите продолжить?1/0 ";
		cin >> answer;
		system("cls");
	} while (answer!=0);
	system("pause");

}