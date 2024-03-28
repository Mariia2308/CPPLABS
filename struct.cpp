#include<iostream>
using namespace std;

struct shipmaker {
	char maker[64];
	float price;
	char goods[64];
	int quantity;
};

void Check(int actualSize, int maxSize) {
	if (actualSize > maxSize)
		exit(0);
}

void Fill(shipmaker makerarr[], int& actualSize) {
	for (int i = 0; i < actualSize; i++) {
		cout << i + 1 << " shipment array." << endl;
		cin.ignore();
		cout << "Enter maker of product " << i + 1 << ": ";
		cin.getline(makerarr[i].maker, 64);
		cout << "Enter name of product " << i + 1 << ": ";
		cin.getline(makerarr[i].goods, 64);
		cout << "Enter price of product " << i + 1 << ": ";
		cin >> makerarr[i].price;
		cout << "Enter quantity of products " << i + 1 << ": ";
		cin >> makerarr[i].quantity;
		cout << endl;
	}
}

void Sheet1(shipmaker makerarr[], int actualSize) {
	cout << "#\t" << "Maker\t" << "Goods\t" << "Price\t" << "Quantity\t\t" << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < actualSize; i++) {
		cout << i + 1 << '\t' << makerarr[i].maker << '\t' << makerarr[i].goods
			<< '\t' << makerarr[i].price << '\t' << makerarr[i].quantity << '\t' << endl;
		cout << endl;
	}
}

void ShowMaker(shipmaker makerarr[], int actualSize) {
	cout << "Enter the name of the maker, whose products you want to see:" << endl;
	char maker[64];
	cin.ignore();
	cin.getline(maker, 64);
	for (int i = 0; i < actualSize; i++){
		if (strcmp(makerarr[i].maker, maker) == 0)
			cout << makerarr[i].goods << " " << '\t';
		cout << endl;
	}
}

struct shipment {
	char goods[64];
	int quantity;
};

void SortByQuantity(shipment shiparr[], shipmaker makerarr[], int actualSize, int& newActualSize)
{
	bool check;
	for (int i = 0; i < actualSize; i++){
		check = true;
		for (int j = 0; j < newActualSize; j++){
			if (strcmp(makerarr[i].goods, shiparr[j].goods) == 0){
				check = false;
				shiparr[j].quantity += makerarr[i].quantity;
				break;
			}
		}
		if (check){
			shiparr[newActualSize].quantity = makerarr[i].quantity;
			strcpy(shiparr[newActualSize].goods, makerarr[i].goods);
			newActualSize++;
		}
	}
	shipment temp;
	for (int i = 0; i < newActualSize - 1; i++)
	for (int j = 0; j < newActualSize - 1 - i; j++)
	if (shiparr[j].quantity > shiparr[j + 1].quantity)
	{
		temp = shiparr[j];
		shiparr[j] = shiparr[j + 1];
		shiparr[j + 1] = temp;
	}
}

void Sheet2(shipment shiparr[], int actualSize)
{
	cout << "The list of goods is sorted by quantity in the warehouse: " << endl;
	cout << endl;
	cout << "#\t" << "Goods\t" << "Quantity\t\t" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < actualSize; i++) {
		cout << i + 1 << '\t' << shiparr[i].goods
			<< '\t' << shiparr[i].quantity << '\t' << endl;
		cout << endl;
	}
}

int main() {
	int const maxSize = 100;
	shipmaker makerarr[maxSize];
	shipment shiparr[maxSize];
	int actualSize = 0;
	cout << "Enter amount of shipments: ";
	cin >> actualSize;
	Check(actualSize, maxSize);
	Fill(makerarr, actualSize);
	system("cls");
	Sheet1(makerarr, actualSize);
	ShowMaker(makerarr, actualSize);
	int newActualSize = 0;
	SortByQuantity(shiparr, makerarr, actualSize, newActualSize);
	Sheet2(shiparr, newActualSize);
	system("pause");
}