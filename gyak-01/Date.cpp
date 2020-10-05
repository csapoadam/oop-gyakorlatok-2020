#include <iostream>
#include "date.h"

Date::Date(int y, int m, int d) { // year, month, day
	year = y;
	month = m;
	day = d;
}

void Date::print() {
	std::cout << year << "/" << month << "/" << day << std::endl;
}