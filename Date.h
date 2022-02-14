#pragma once

class Date 

{
private:
	int day, week, month;
public:
	Date();
	void setDate(int day, int week, int month);
	int getDay();
	int getMonth();
	int getWeek();
	/*bool belongTo(Date value);
	void printRow(int row);
	void print();
	Date maxValue();
	*/
};

