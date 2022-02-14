#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Matrix.h"
#include"Date.h"

int main() {

	/////////////////////////////////////////////////////////////
	// Testing with integers //

	int row_size = 5;
	int col_size = 7;

	Matrix<int> matrix1(row_size, col_size);

	////populating the matrix with numbers
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			//// i+j just an arbitrary value, you can choose whatever value you want
			matrix1.addValue(i, j, i + j);
		}
	}

	//// Testing the print fucntions
	matrix1.print();
	matrix1.printRow(1);

	//// Testing the maxValue function
	std::cout << "The max value in the matrix is: " << matrix1.maxValue() << std::endl;

	//// Testing the belongTo function
	int temp_value;

	std::cout << "Input a value to check the belongTO function\n";
	std::cin >> temp_value;
	if (matrix1.belongTo(temp_value)) {
		std::cout << "The value does exist\n";
	}
	else {
		std::cout << "The value doesn't exist\n";
	}


	/////////////////////////////////////////////////////////////
	// Testing with strings //

	char name1[30] = "Ahmed Emad";
	char name2[50] = "Safaa Mahmoud";
	char name3[20] = "Hani Farouk";
	char name4[20] = "Alaa Mohamed";

	Matrix<char*> matrix2(2, 2);

	////populating the matrix with strings
	matrix2.addValue(0, 0, name1);
	matrix2.addValue(0, 1, name2);
	matrix2.addValue(1, 0, name3);
	matrix2.addValue(1, 1, name4);


	//// Testing the print fucntions
	matrix2.print();
	matrix2.printRow(0);

	//// Testing the maxValue function
	std::cout << "The max value in the matrix is: " << matrix2.maxValue() << std::endl;

	//// Testing the belongTo function
	char name5[20] = "Hazem Ayman";
	if (matrix2.belongTo(name5)) {
		std::cout << "The value does exist\n";
	}
	else {
		std::cout << "The value doesn't exist\n";
	}
	/////////////testing Date object
	Matrix<Date> M(5, 7);
	Date date1;
	Date date2;
	Date date3;
	date1.setDate(3, 5, 7);
	 date2.setDate(5,8,10);
	 date3.setDate(12,12,12);
	 M.addValue(1,1, date1);
	 M.addValue(1, 2, date2);
	 M.addValue(1, 3, date3);
	bool output= M.belongTo( date1);
	cout << "the last matrix inclusion result is" << " " << output << endl;
	Date obj=M.maxValue();
	cout << "maximum day is" << obj.getDay() << endl;
	cout << "maximum week is" << obj.getWeek()<< endl;
	cout << "maximum month is" << obj.getMonth()<< endl;
	M.printRow(1);




}