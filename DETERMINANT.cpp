#include <iostream>
#include <iomanip>
using namespace std;

int ReadInteger(){
	int input = 0;
	while ((cin >> input).fail() || cin.peek() != '\n' || input < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Dimension isn't an integer, try again." << endl;
	}
	return input;
}

float ReadFloat(){
	float input = 0;
	while ((cin >> input).fail() || cin.peek() != '\n'){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Element isn't an integer, try again." << endl;
	}
	return input;
}

void InputMatrix(float **matrix, int demention){
	cout << "Enter values of square matrix: " << endl;
	for (int i = 0; i <= demention; i++)
	for (int j = 0; j <= demention; j++){
		cout << "[" << i << "]" << "[" << j << "]";
		matrix[i][j] = ReadFloat();
	}
	cout << endl;
}

void OutputMatrix(float **matrix, int demention){
	cout << "Entered matrix: " << endl;
	for (int i = 0; i <= demention; i++){
		for (int j = 0; j <= demention; j++)
			cout << setw(6) << setprecision(5) << matrix[i][j] << "   ";
		cout << endl;
	}
}

float Determinant(float **matrix, int demention){
	int permutation = 0;
	float determinant = 1;
	for (int j = 0; j < demention; j++){
		for (int i = demention; i >= j + 1; --i){

			if (matrix[i][j] == 0){
				continue;
			}

			if (matrix[i-1][j] == 0){
				for (int k = 0; k <= demention; k++){
					float temp = matrix[i - 1][k];
					matrix[i - 1][k] = matrix[i][k];
					matrix[i][k] = -temp;
					permutation++;
				}
				continue;
			}

			float coef = (-matrix[i][j] / matrix[i - 1][j]);
			for (int k = 0; k <= demention; k++){
				matrix[i][k] = matrix[i - 1][k] * coef + matrix[i][k];
			}
		}
	}
	determinant = pow(-1, permutation);
	for (int i = 0; i <= demention; i++){
		for (int j = 0; j <= demention; j++)
		if (matrix[i][i] == 0){
			return 0;
		}
		determinant *= matrix[i][i];
	}
	return determinant;
}

void DeleteMemory(float** matrix, int demention){
	for (int i = 0; i < demention; i++)
		delete[]matrix[i];
	delete[]matrix;
}

void main(){
	cout << "Enter the demention of square matrix: ";
	int demention = ReadInteger();
	demention--;
	float **matrix = new float*[demention];
	for (int i = 0; i <= demention; i++)
		matrix[i] = new float[demention];
	InputMatrix(matrix, demention);
	OutputMatrix(matrix, demention);
	float D = Determinant(matrix, demention);
	cout << "Determinant = "<< D << endl;
	system("pause");
}