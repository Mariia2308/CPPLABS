#include<iostream>
#include<math.h>
#include<conio.h>>
using namespace std;

int main()
{
	int choice;
	cout << "Make your choice" << endl;
	cout << "If you want to work with int enter 1" << endl;
	cout << "If you want to work with float enter 2" << endl;
	cout << "If you want to work with sting enter 3" << endl;
	cout << "If you want to work with char enter 4" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
			  int a, b, c, discr, x1, x2;
			  cout << "The equation: 3a*x^2 + a^2*x + c. Find its roots." << endl;
			  cout << "Enter a: " << endl;
			  cin >> a;
			  c = 1;
			  b = pow(a,2);
			  a = 3 * a;

			  if (a != 0)
			  {
				  discr = b * b - 4 * a * c;
				  if (discr > 0)
				  {
					  x1 = ((-b) + sqrt(discr)) / (2 * a);
					  x2 = ((-b) - sqrt(discr)) / (2 * a);
					  cout << "x1 = " << x1 << endl;
					  cout << "x2 = " << x2 << endl;
				  }
				  if (discr == 0)
				  {
					  x1 = -(b / (2 * a));
					  cout << "x1 = x2 = " << x1 << endl;
				  }
				  if (discr < 0)
				  {
					  cout << "D < 0. No valid roots";
				  }
			  }
			  else
			  {
				  cout << "Division by zero is prohibited!" << endl;
			  }

			  break;
	}
	case 2:
	{
			  float b, y;
			  cout << "The equation: (b ^ (1/3))/(b^2 + 1)" << endl;
			  cout << "Enter b: " << endl;
			  cin >> b;
			  if (b < 0)
			  {
				  y = cbrt(b)/(pow(b,2) + 1);
				  cout << "y = "<< y << endl;
			  }
			  else
			  {
				  y = abs(cos(b));
				  cout << "y = " << y << endl;
			  }
			  break; 
	}
	case 3:
	{
			  char c[50];
			  cout << "Enter your word:" << endl;
			  cin >> c;
			  if (strcmp(c ,"first")>0)
			  {
				  cout << "first" << " " << c << endl;
			  }
			  else
				  cout << c << " " << "first" << endl;
			  break; 
	}
	case 4:
	{
			  char code;
				cout << "Press some key" << endl;
				code = _getch();
				if (code == 0)
				{
					code = _getch();
					cout << "You press extended key.";
				}
				cout << "Key code = " << (int)code << endl;
			  break;
	}

	default:
	{ 
			   cout << "You make wrong choice" << endl;
			   break; 
	}
	}
	system("pause");
}
