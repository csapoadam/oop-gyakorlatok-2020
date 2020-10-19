#include <iostream>
#include <vector>
#include <algorithm>
#include "date.h"

const std::vector<int> monthsWith30Days = {4,6,9,11};
const std::vector<int> monthsWith31Days = {1,3,5,7,8,10,12};

bool isLeapYear(int year) {return year % 4 == 0;}

bool monthHas30Days(int month) {
	if (month == 2) return false;
	return std::find(
		monthsWith30Days.begin(),
		monthsWith30Days.end(),
		month
	) != monthsWith30Days.end();
}

int getNumberOfDays(int month, int year) {
	if (month != 2) {
		if (monthHas30Days(month)) {
			return 30;
		}
		else {
			return 31;
		}
	}
	else {
		if (isLeapYear(year)) {
			return 29;
		}
		return 28;
	}
}

Date::Date(std::string id, int y, int m, int d) : id(id), year(y), month(m), day(d) { // year, month, day
	if (m < 1 || m > 12) {
		throw std::exception("invalid month");
	}
	if (d > getNumberOfDays(m, y) || d < 1) {
		throw std::exception("invalid number of days!");
	}
}

void Date::print() const {
	std::cout << id << ": " << year << "/" << month << "/" << day << std::endl;
}

Date& Date::addDays(int numDaysToAdd) {
	std::cout << "\tadding " << numDaysToAdd << " days to " << id << std::endl;
	int daysLeftInThisMonth = getNumberOfDays(month, year) - day;
	while (true) {
		if (daysLeftInThisMonth < numDaysToAdd) {
			numDaysToAdd = numDaysToAdd - daysLeftInThisMonth;
			month = (month % 12) + 1;
			if (month == 1) {
				year += 1;
			}
			day = 0;
			daysLeftInThisMonth = getNumberOfDays(month, year);
		}
		else {
			day += numDaysToAdd;
			break;
		}
	}
	return *this;

}