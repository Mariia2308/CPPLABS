#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	int const N = 100;
	int demention, k;

	cout << "Enter dementions of array: ";
	cin >> demention;
	float array[N];

	if (demention >= 100) cout << "A demention is too big, it would be less than 100." << endl;
	else
		cout << "Choose a way to fill the array. Press 1 to do it yourself. Press 2 for random input. ";
	cin >> k;
	cout << "Enter fractional elements of the array:" << endl;
	switch (k)
	{
	case 1:

		for (int i = 0; i < demention; i++)
		{
			cout << "Enter a number [" << i << "] = " << endl;
			cin >> array[i];
		}
		break;

	case 2:
		cout << "Input array: " << endl;
		srand(time(NULL));
		for (int i = 0; i < demention; i++)
		{
			array[i] = rand() % 100 / 10.;
			cout << " "<< array [i] << " " << endl;
		}
		break;
}

	int i, j;
	float temp;
	for (int i = 0; i < demention; i++)
	{
		for (j = i + 1; j < demention; j++)
		{
			if (abs((array[i] - (array[i])) - 0.5) >= abs((array[j] - (array[j])) - 0.5))
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	cout << "Result array: ";
	for (int i = 0; i < demention; i++)
		cout << " " << array[i] << " ";
	cout << endl;

	system("pause");

	return 0;
}