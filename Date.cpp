#include"Date.h"
Date::Date() 
{
	day =0;
	week = 0;
	month = 0;
}
void Date::setDate(int day, int week, int month)
{
	this->day = day;
	this->week = week;
	this->month = month;
}
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getWeek()
{
	return week;
}
/*bool Date::belongTo(Date value)
{
	for (int i = 0; i < getRowSize; i++) {
		for (int j = 0; j < col_size; j++) {
			if (mat[i][j] == value) {
				return true;
			}
}
void Date::printRow(int row)
{

}
void Date::print()
{

}
Date Date::maxValue()
{

}
*/