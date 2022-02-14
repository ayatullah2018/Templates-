#pragma once
#pragma onces

#include <iostream>
using namespace std;
#include"Date.h"

//// Note: you can use "class" or "typename" keywords to create template type
template<class T>
class Matrix {
private:
	T** mat;
	int row_size, col_size;

public:
	int getRowSize() {
		return row_size;
	}
	int getColSize()
	{
		return col_size;
	}
	Matrix(int row_size, int col_size) {

		this->row_size = row_size;
		this->col_size = col_size;

		//// Creating a dynamic 2D list
		mat = new T * [row_size];
		for (int i = 0; i < row_size; i++) {
			mat[i] = new T[col_size];
		}

		//// Intialzing the list to NULL
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				mat[i][j] = NULL;
			}
		}
	}

	void addValue(int row, int col, T value) {
		mat[row][col] = value;
	}

	bool belongTo(T value) {
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (mat[i][j] == value) {
					return true;
				}
				/* Note: Some people prefer to write the one line inside the "if" as following:

				 if (mat[i][j] == value)
						return true;

				 which is syntactically correct, but during development you could
				 simply forget and write anything below it leading to logical errors;
				 so please use the braces to be safe.*/
			}
		}
		return false;
	}

	void printRow(int row) {
		std::cout << "Printing the row:" << row << std::endl;
		for (int i = 0; i < col_size; i++) {
			std::cout << mat[row][i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Done Printing the row.\n";
	}

	void print() {
		std::cout << "Printing the matrix.\n";
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				std::cout << mat[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "Done Printing the matrix.\n";
	}

	T maxValue() {
		T max = mat[0][0];

		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (mat[i][j] > max) {
					max = mat[i][j];
				}
			}
		}
		return max;
	}
};


//// Template Specialization Solution
template<>
class Matrix<char*> {
private:
	char*** mat;
	int row_size, col_size;

public:
	Matrix(int row_size, int col_size) {

		this->row_size = row_size;
		this->col_size = col_size;

		//// Creating a dynamic 2D list
		mat = new char** [row_size];
		for (int i = 0; i < row_size; i++) {
			mat[i] = new char* [col_size];
		}

		//// Intialzing the list to NULL
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				mat[i][j] = new char[strlen("") + 1];
				strcpy(mat[i][j], "");
			}
		}
	}

	void addValue(int row, int col, char* value) {

		//if (mat[row][col] == nullptr) { std::cout << "null"; }	//if this pointer alreday has mem reserved, free it
		//else {
		delete[] mat[row][col];


		mat[row][col] = new char[strlen(value) + 1];
		strcpy(mat[row][col], value);
	}

	bool belongTo(char* value) {
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (strcmp(mat[i][j], value)) {
					return true;
				}
			}
		}
		return false;
	}

	void printRow(int row) {
		std::cout << "Printing the row:" << row << std::endl;
		for (int i = 0; i < col_size; i++) {
			std::cout << mat[row][i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Done Printing the row.\n";
	}

	void print() {
		std::cout << "Printing the matrix.\n";
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				std::cout << mat[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "Done Printing the matrix.\n";
	}

	char* maxValue() {
		char* max = mat[0][0];

		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (strcmp(max, mat[i][j]) < 0) {
					strcpy(max, mat[i][j]);
				}
			}
		}
		return max;
	}
};

//// Template Specialization Solution
template<>
class Matrix <Date>
{
private:
	Date** mat;
	int row_size, col_size;

public:
	int getRowSize() {
		return row_size;
	}
	int getColSize()
	{
		return col_size;
	}
	Matrix(int row_size, int col_size) {

		this->row_size = row_size;
		this->col_size = col_size;

		//// Creating a dynamic 2D list
		mat = new Date  *[row_size];
		for (int i = 0; i < row_size; i++) {
			mat[i] = new Date  [col_size];
		}

		//// Intialzing the list to NULL
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				Date tempObject;
				mat[i][j] = tempObject;
			}
		}
	}

	void addValue(int row, int col, Date value) {
		mat[row][col] = value;
	}

	bool belongTo(Date value) {
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (mat[i][j].getDay() == value.getDay() && mat[i][j].getMonth() == value.getMonth() && mat[i][j].getWeek() == value.getWeek()) {
					return true;
				}

			}
		}
		return false;
	}

	void printRow(int row) {
		std::cout << "Printing the row:" << row+1 << std::endl;
		for (int i = 0; i < col_size; i++) {
			
			std::cout << mat[row][i].getDay() << "/";
			std::cout << mat[row][i].getWeek() << "/";
			std::cout << mat[row][i].getMonth() << "/";
			std::cout << "   ";
			
		}
		std::cout << std::endl;
		std::cout << "Done Printing the row.\n";
	}

	void print() {
		std::cout << "Printing the matrix.\n";
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				std::cout << "here is the day" << "     ";
				std::cout << mat[i][j].getDay() << "\t";
				std::cout << "here is the week" << "         ";
				std::cout << mat[i][j].getWeek() << "\t";
				std::cout << "here is the month" << "         ";
				std::cout << mat[i][j].getMonth() << "\t";
				std::cout << "\t";
				std::cout << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "Done Printing the matrix.\n";
	}

	Date maxValue() {
		Date max = mat[0][0];

		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				if (mat[i][j].getMonth() > max.getMonth()) {
					max = mat[i][j];

				}
				else if (mat[i][j].getMonth() == max.getMonth())
				{
					if (mat[i][j].getWeek() > max.getWeek())
						max = mat[i][j];
				}
			}
		}
		return max;
	}

};

	