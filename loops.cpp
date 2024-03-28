#include <iostream>
#include <math.h>
#include <iomanip> 
#include <conio.h>
using namespace std;

int main()
{
	cout << "Function y = 1/(cos(x)+1)*sin(x)) on the interval from 0 to pi." << endl;
	cout << "Specify the accuracy with which to calculate:" << endl;
	float x, eps;
	cin >> eps;
	cout << "eps = " << eps << endl;
	cout << "Enter the variable x = " << endl;
	cin >> x;
	cout << "x = " << x << endl;
	float aCos, sumCos, aSin, sumSin;
	int i = 1;
	aSin = x;
	sumSin = aSin;
	aCos = 1;
	sumCos = 2;
	float newS, oldS;

	if (x != 0)
	{
			cout << "\xda\xc4\xc4\xc4\xc4" <<
				"\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
				"\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n"
				<< "\xb3Step\xb3 newS - oldS\xb3     newS   \xb3 \n";
		do
		{
			oldS = 1 / (sumCos*sumSin);
			i++;
			aCos = aCos * (-x * x / (2 * (i - 1)*(i * 2 - 3)));
			sumCos = sumCos + aCos;

			aSin = aSin * (-x * x / (2 * (i - 1)*(2 * i - 1)));
			sumSin = sumSin + aSin;

			newS = 1 / (sumCos*sumSin);

			cout << "\xc3\xc4\xc4\xc4\xc4" << "\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
				"\xc5\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb4\n";

			cout << "\xb3" << setfill(' ') << setw(4) << int(i) << "\xb3"
				<< setw(12) << setprecision(6) << newS - oldS << "\xb3" << setw(12) << newS << "\xb3\n";

		} while (abs(newS - oldS) > eps);
			cout << "\xc0\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
			<< "\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n";

	}

		else
		{
			cout << "There is no answer" << endl;
		}

	system("pause");
	return 0;
}