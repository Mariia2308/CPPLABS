#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

using namespace std;

void check(const int x) {
	if (x > 20) {
		cout << "Error, demention is too big ";
		exit(0);
	}
}


void DIY_matrix(int matrix[20][20], const int& lines, const int& columns) {

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void random_matrix(int matrix[20][20], const int& lines, const int& columns) {

	srand(time(NULL));
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rand() % 200 - 50;
	}
}
void output(int matrix[20][20], const int& lines, const int& columns)
{
	cout << "matrix A \n";
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

}

void delete_matrix(int matrix[20][20], const int& line_to_delete, const int& column_to_delete, const int& lines, const int& columns) {

	for (int i = line_to_delete - 1; i < lines - 1; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = matrix[i + 1][j];
		}
	}

	for (int i = 0; i < lines - 1; i++) {
		for (int j = column_to_delete - 1; j < columns - 1; j++) {
			matrix[i][j] = matrix[i][j + 1];
		}
	}
}

int main() {
	int matrix[20][20];
	int lines, columns, var, line_to_delete, column_to_delete;

	cout << "Enter quantity of lines: "; cin >> lines;
	check(lines);
	cout << "Enter quantity of columns: "; cin >> columns;
	check(columns);

	cout << "Press 1 to do it yourself. Press 2 for random input. " << endl;
	cout << "Choose way for fill matrix: ";
	int choose = 0;
	cin >> var;
	cout << endl;

	switch (var) {
	case 1:
		DIY_matrix(matrix, lines, columns);
		break;
	case 2:
		random_matrix(matrix, lines, columns);
		break;
	}
	cout << "Start matrix: \n";
	output(matrix, lines, columns);
	cout << endl;

	  cout << "Input line to delete: ";
  cin >> line_to_delete;

  if (line_to_delete > lines) {
    cout << "Error, lines is too big ";
    exit(0);
  }
  
  cout << "Input column to delete: ";
  cin >> column_to_delete;
  
  if (column_to_delete > columns) {
    cout << "Error, columns is too big ";
    exit(0);
  }

	delete_matrix(matrix, line_to_delete, column_to_delete, lines, columns);
	cout << "Final matrix: \n";

	output(matrix, lines - 1, columns - 1);
	system("pause");
}

