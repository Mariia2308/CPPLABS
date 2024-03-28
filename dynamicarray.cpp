#include<iostream>
using namespace std;

struct shipmaker {
	char maker[64];
	float price;
	char goods[64];
	int quantity;
};

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
	for (int i = 0; i < actualSize; i++) {
		if (strcmp(makerarr[i].maker, maker) == 0)
			cout << makerarr[i].goods << " " << '\t';
		cout << endl;
	}
}

struct shipment {
	char goods[64];
	int quantity;
};

shipment * uniquesCount(shipmaker makerarr[], int actualSize, int &uniqueSize) {
	uniqueSize = 1;
	shipment* uniques = new shipment[uniqueSize];
	strcpy(uniques[0].goods, makerarr[0].goods);
	uniques[0].quantity = 0;
	for (int i = 1; i < actualSize; i++) {
		bool notAdded = true;
		char* finded = makerarr[i].goods;
		for (int j = 0; j < uniqueSize; j++) {
			if (strcmp(uniques[j].goods, finded) == 0){
				notAdded = false;
				break;
			}
		}
		if (notAdded) {
			shipment* uniquesNew = new shipment[uniqueSize + 1];
			for (int k = 0; k < uniqueSize; k++) {
				strcpy(uniquesNew[k].goods, uniques[k].goods);
				uniquesNew[k].quantity = 0;
			}
			strcpy(uniquesNew[uniqueSize].goods, finded);
			uniquesNew[uniqueSize].quantity = 0;
			delete[] uniques;
			uniques = uniquesNew;
			uniqueSize++;
		}
	}
	return uniques;
}

void QuantityCount(shipment uniqueNames[], shipmaker shipments[], int actualSize, int uniqueSize) {
	for (int i = 0; i < uniqueSize; i++) {
		for (int j = 0; j < actualSize; j++) {
			if (strcmp(uniqueNames[i].goods, shipments[j].goods) == 0) {
				uniqueNames[i].quantity += shipments[j].quantity;
			}
		}
	}
}

void SortByQuantity(shipment shiparr[], int uniqueSize) {
	shipment temp;
	for (int i = 0; i < uniqueSize - 1; i++)
	for (int j = 0; j < uniqueSize - 1 - i; j++)
	if (shiparr[j].quantity > shiparr[j + 1].quantity)
	{
		temp = shiparr[j];
		shiparr[j] = shiparr[j + 1];
		shiparr[j + 1] = temp;
	}
}

void Sheet2(shipment shiparr[], int uniqueSize) {
	cout << "The list of goods is sorted by quantity in the warehouse: " << endl;
	cout << endl;
	cout << "#\t" << "Goods\t" << "Quantity\t\t" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < uniqueSize; i++) {
		cout << i + 1 << '\t' << shiparr[i].goods
			<< '\t' << shiparr[i].quantity << '\t' << endl;
		cout << endl;
	}
}

int main() {
	int actualSize = 0;
	cout << "Enter amount of shipments: ";
	cin >> actualSize;
	shipmaker* makerarr;
	makerarr = new shipmaker[actualSize];
	Fill(makerarr, actualSize);
	system("cls");
	Sheet1(makerarr, actualSize);
	ShowMaker(makerarr, actualSize);
	int uniqueSize = 0;
	shipment *shiparr = uniquesCount(makerarr, actualSize, uniqueSize);
	QuantityCount(shiparr, makerarr, actualSize, uniqueSize);
	SortByQuantity(shiparr, uniqueSize);
	Sheet2(shiparr, uniqueSize);
	delete[] makerarr;
	delete[] shiparr;
	system("pause");
}