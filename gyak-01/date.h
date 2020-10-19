#pragma once

class Date {
	int year, month, day;
	const std::string id;
public:
	Date(std::string, int, int, int); // year, month, day
	Date& addDays(int);
	void print() const;
};
