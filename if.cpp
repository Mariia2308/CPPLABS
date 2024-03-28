#include <iostream>
#include <math.h>
using namespace std;
int main()
{

	float A, B, C, D;
	float AD, sum, term1, term2;

	A = -7;
	B = 0;
	cout << "y=((D+C*A^D)^1/3)+fabs (B/sin(A)" << endl;

	cout << "A =" << A << endl;
	cout << "B =" << B << endl;
	cout << "Enter C = " << endl;
	cin >> C;
	cout << "Enter D = " << endl;
	cin >> D;

	if (sin(A) != 0)
	{
		term2 = fabs(B / (sin(A)));
	}
	else
	{
		cout << "Error, sin = 0. The denominator = 0" << endl;
	}

	if (A > 0)
	{
		AD = exp(D + log(A));
	}
	else
	{
		if ((lround(D) - D) == 0)
		if ((lround(D) % 2) == 0)
			AD = exp(D + log(-A));
		else
			AD = -exp(D + log(-A));
		else
		{
			cout << "Error.No exist." << endl;

			return 0;
		}
	}
	sum = D + C * AD;
	if (sum > 0)
		term1 = (exp((1. / 3) * log(sum)));
	else
		term1 = -(exp((1. / 3) * log(-sum)));
	float y = (term1 + term2);
	cout << "y=" << y << endl;

	system("pause");

	return 0;
}