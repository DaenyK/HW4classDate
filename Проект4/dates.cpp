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
	
	return *this;

}

