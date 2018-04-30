#ifndef _DATES_H_
#define _DATES_H_
#include "Headers.h"

class date
{
private:
	int day;
	int month;
	int year;
public:
	date() = default;
	date(int day, int month, int year);
	~date(){}

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	bool leap(int year);
	bool sameDate(int day, int month, int year);
	bool operator==(date obj);

	date operator+=(int day);
	
};


#endif