#include "dates.h"

date::date(int day, int month, int year)
{
	if (year > 0 && year < 2019)
	{
		this->year = year;

		if (leap(year) == 1)
		{
			if (month == 2)
			{
				if (day > 0 && day < 30)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "некорректна€ дата, проdерьте правильность даты, тк это високосный год\n";
			}
			else if (month == 1 || month == 3 || month == 5 || month == 7
				|| month == 8 || month == 10 || month == 12)
			{
				if (day > 0 && day < 32)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "вы ввели некорректную дату\n";
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 0 && day < 31)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "вы ввели некорректную дату\n";
			}
			else cout << "некорректна€ дата(мес€ц)\n";
		}
		else
		{
			if (month == 2)
			{
				if (day > 0 && day < 29)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "некорректна€ дата, проверьте правильность даты, тк это Ќ≈ високосный год\n";
			}
			else if (month == 1 || month == 3 || month == 5 || month == 7
				|| month == 8 || month == 10 || month == 12)
			{
				if (day > 0 && day < 32)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "вы ввели некорректную дату\n";
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 0 && day < 31)
				{
					this->month = month;
					this->day = day;
				}
				else cout << "вы ввели некорректную дату\n";
			}
			else cout << "некорректна€ дата(мес€ц)\n";
		}


	}
	else cout << "некорректна€ дата(год)\n";
}

bool date::leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
}

bool date::sameDate(int day, int month, int year)
{
	if (this->day == day && this->month == month && this->year == year)
		return true;
	else false;
}

bool date :: operator ==(date obj)
{
	if (this->day == obj.day)
	{
		if (this->month == obj.month)
		{
			if (this->year == obj.year)
				return true;
		}
	}
	else return false;
}

date date::operator+=(int day)
{
	short result;
	do {
		if (leap(this->year))
		{
			if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
				|| this->month == 8 || this->month == 10)
			{
				this->day += day;
				if (this->day >= 31)
				{
					this->month += 1;
					this->day -= 31;
					if (this->day >= 30 && month == 4 || month == 6 || month == 9 || month == 11)
					{
						this->month += 1;
						this->day -= 30;
					}
					if (this->month == 2 && this->day > 29)
					{
						this->month += 1;
						this->day -= 29;
					}

				}
			}
			else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 10)
			{
				this->day += day;
				if (this->day >= 30)
				{
					this->month += 1;
					this->day -= 30;
					if (this->day >= 30 && this->month == 1 || this->month == 3 || this->month == 5
						|| this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
					{
						this->month += 1;
						this->day -= 31;
					}
					if (this->month == 2 && this->day > 29)
					{
						this->month += 1;
						this->day -= 29;
					}

				}
			}
			else if (this->month == 2)
			{
				this->day += day;
				if (this->day > 29)
				{
					this->month += 1;
					this->day -= 29;
					if (this->day >= 31)
					{
						this->month += 1;
						this->day -= 31;
						if (this->day >= 30 && month == 4 || month == 6 || month == 9 || month == 11)
						{
							this->month += 1;
							this->day -= 30;
						}
					}
				}
			}
			else if (this->month == 12)
			{
				this->day += day;
				if (this->day > 31)
				{
					this->month = 1;
					this->day -= 31;
					this->year += 1;
					if (this->day > 31)
					{
						this->month += 1;
						this->day -= 31;
						if (this->day > 31)
						{
							this->month += 1;
							this->day -= 28;
						}
					}
				}
			}
		}
		else

		{
			if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
				|| this->month == 8 || this->month == 10)
			{
				this->day += day;
				if (this->day >= 31)
				{
					this->month += 1;
					this->day -= 31;
					if (this->day >= 30 && month == 4 || month == 6 || month == 9 || month == 11)
					{
						this->month += 1;
						this->day -= 30;
					}
					if (this->month == 2 && this->day > 28)
					{
						this->month += 1;
						this->day -= 28;
					}

				}
			}
			else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 10)
			{
				this->day += day;
				if (this->day >= 30)
				{
					this->month += 1;
					this->day -= 30;
					if (this->day >= 30 && this->month == 1 || this->month == 3 || this->month == 5
						|| this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
					{
						this->month += 1;
						this->day -= 31;
					}
					if (this->month == 2 && this->day > 28)
					{
						this->month += 1;
						this->day -= 28;
					}

				}
			}
			else if (this->month == 2)
			{
				this->day += day;
				if (this->day > 28)
				{
					this->month += 1;
					this->day -= 28;
					if (this->day >= 31)
					{
						this->month += 1;
						this->day -= 31;
						if (this->day >= 30 && month == 4 || month == 6 || month == 9 || month == 11)
						{
							this->month += 1;
							this->day -= 30;
						}
					}
				}
			}
			else if (this->month == 12)
			{
				this->day += day;
				if (this->day > 31)
				{
					this->month = 1;
					this->month -= 31;
					this->year += 1;
					if (this->day > 31)
					{
						this->month += 1;
						this->day -= 31;
						if (leap(this->year))
						{
							if (this->day > 29)
							{
								this->month += 1;
								this->day -= 29;
							}
						}
						else
							if (this->day > 28)
							{
								this->month += 1;
								this->day -= 28;
							}
					}
				}
			}
		}
		if (this->day > 31 && ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)))
		{
			result = 1;
			day = this->day - 31;
			this->day = 31;
		}
		else if (this->day > 30 && ((month == 4 || month == 6 || month == 9 || month == 11)))
		{
			result = 1;
			day = this->day - 30;
			this->day = 30;
		}
		else if (month == 2 && (leap(this->year)) && (this->day > 29))
		{
			result = 1;
			day = this->day - 29;
			this->day = 29;
		}
		else if (month == 2 && !(leap(this->year)) && (this->day > 28))
		{
			result = 1;
			day = this->day - 28;
			this->day = 28;
		}
		else result = 0;
	} while (result != 0);
	return *this;

}

date date::operator-=(int day)
{
	if (this->day <= day)
	{
		do {
			if (leap(this->year))
			{
				if (this->month == 3 || this->month == 5 || this->month == 7
					|| this->month == 8 || this->month == 10 || this->month == 12)
				{
					month--;
					day = day - this->day;
					if (this->month == 2)
						this->day = 29 - day;
					else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
						this->day = 30 - day;
					else if (this->month == 7)
						this->day = 31 - day;


				}

				else if (this->month == 2
					|| this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
				{
					month--;
					day = day - this->day;
					if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
						|| this->month == 8 || this->month == 10 || this->month == 12)
						this->day = 31 - day;
				}

				else if (this->month == 1)
				{
					day = day - this->day;
					this->month = 12;
					this->year -= 1;
					this->day = 31 - day;
				}
			}
			else
			{
				if (this->month == 3 || this->month == 5 || this->month == 7
					|| this->month == 8 || this->month == 10 || this->month == 12)
				{
					month--;
					day = day - this->day;
					if (this->month == 2)
						this->day = 28 - day;
					if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
						this->day = 30 - day;

				}
				else if (this->month == 2
					|| this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
				{
					month--;
					day = day - this->day;
					if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7
						|| this->month == 8 || this->month == 10 || this->month == 12)
						this->day = 31 - day;
				}

				else if (this->month == 1)
				{
					day = day - this->day;
					this->month = 12;
					this->year -= 1;
					this->day = 31 - day;
				}
			}
			if (this->day < 0)
			{
				day = this->day*(-1) + 1;
				this->day = 1;
			}
		} while (this->day == 1);
	}
	else
	{
		this->day -= day;
	}
	return *this;

}

date date::operator+(date obj)
{
	date buf;
	buf.year = this->year + obj.year;
	buf.month = this->month + obj.month;
	if (buf.month > 12)
	{
		do {
			buf.month -= 12;
			buf.year++;
		} while (buf.month > 12);
	}

	buf.day = this->day + obj.day;
	if (buf.day > 31 && ((buf.month == 1 || buf.month == 3 || buf.month == 5 || buf.month == 7
		|| buf.month == 8 || buf.month == 10)))
	{
		buf.day -= 31;
		buf.month++;
	}
	else if (buf.day > 30 && ((buf.month == 4 || buf.month == 6 || buf.month == 9 || buf.month == 11)))
	{
		buf.day -= 30;
		buf.month++;
	}
	else if (buf.day > 31 && ((buf.month == 12)))
	{
		buf.day -= 31;
		buf.month = 1;
		buf.year++;
	}
	else if (buf.day > 29 && ((buf.month == 2)) && (leap(buf.year)))
	{
		buf.day -= 29;
		buf.month++;
	}
	else if (buf.day > 28 && ((buf.month == 2)) && !(leap(buf.year)))
	{
		buf.day -= 28;
		buf.month++;
	}
	return buf;
}

date date::operator-(date obj)
{
	date buf;
	buf.year = this->year - obj.year;
	if (buf.year < 0)
	{
		cout << "\nошибка: год отрицательный\n";
		EXIT_FAILURE;
	}
	buf.month = this->month - obj.month;
	if (buf.month < 0)
	{
		buf.month = 12 + buf.month;
		buf.year--;
	}
	else if (buf.month == 0)
	{
		buf.month = 12;//или тут 1?
		buf.year--;
	}

	buf.day = this->day - obj.day;
	if (buf.day < 0)
	{
		if (((buf.month == 12 || buf.month == 3 || buf.month == 5 || buf.month == 7
			|| buf.month == 8 || buf.month == 10)))
		{
			buf.day = 31 + buf.day;
			buf.month--;
		}
		else if (((buf.month == 4 || buf.month == 6 || buf.month == 9 || buf.month == 11)))
		{
			buf.day = 30 + buf.day;
			buf.month--;
		}
		else if ((buf.month == 1))
		{
			buf.day = 31 + buf.day;
			buf.month = 12;
			buf.year--;
		}
		else if ((buf.month == 2) && (leap(buf.year)))
		{
			buf.day = 29+buf.day;
			buf.month--;
		}
		else if (buf.day > 28 && ((buf.month == 2)) && !(leap(buf.year)))
		{
			buf.day = 28 + buf.day;
			buf.month--;
		}
	}
	return buf;
}
