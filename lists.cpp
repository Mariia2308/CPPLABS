#include<iostream>
using namespace std;

struct shipmaker {
	char maker[64];
	float price;
	char goods[64];
	int quantity;
	shipmaker* next;
};

void Fill(shipmaker*& start) {
	shipmaker* current = start;
	char maker[64];
	char goods[64];
	int i = 0;
	do {
		cout << "Enter maker of product " << i + 1 << ": ";
		cin.getline(maker, 64);
		if (strcmp(maker, "") != 0) {
			shipmaker* temp = new shipmaker;
			temp->next = NULL;
			strcpy_s(temp->maker, maker);
			cout << "Enter name of product " << i + 1 << ": ";
			cin.getline(goods, 64);
			strcpy_s(temp->goods, goods);
			cout << "Enter price of product " << i + 1 << ": ";
			cin >> temp->price;
			cout << "Enter quantity of products " << i + 1 << ": ";
			cin >> temp->quantity;
			cin.ignore();
			if (start == NULL)
				start = temp;
			else
				current->next = temp;
			current = temp;
			i++;
		}
		cout << endl;
	} while (strcmp(maker, ""));
}

void Sheet1(shipmaker* start) {
	shipmaker* current = start;
	int i = 0;
	cout << "#\t" << "Maker\t" << "Goods\t" << "Price\t" << "Quantity\t\t" << endl;
	cout << "------------------------------------------------" << endl;
	while (current != NULL) {

		cout << i + 1 << '\t'
			<< current->maker << '\t'
			<< current->goods << '\t'
			<< current->price << '\t'
			<< current->quantity << '\t'
			<< endl;
		cout << endl;
		i++;
		current = current->next;
	}
}
void ShowMaker(shipmaker* start) {
	shipmaker* current = start;
	cout << "Enter the name of the maker, whose products you want to see:" << endl;
	char maker[64];
	cin.getline(maker, 64);
	while (current != NULL) {
		if (strcmp(current->maker, maker) == 0) {
			cout << current->goods << " " << '\t';
			cout << endl;
		}
		current = current->next;
	}
}

struct shipment {
	char goods[64];
	int quantity;
	shipment* next;
};

shipment* QuantityCount(shipmaker * start) {
	if (start == NULL)
		return NULL;
	shipmaker * current = start;
	shipment * newStart = NULL;
	shipment* newTemp = new shipment;
	strcpy_s(newTemp->goods, current->goods);
	newTemp->quantity = current->quantity;
	newTemp->next = NULL;

	newStart = newTemp;
	shipment * newLast = newStart;
	current = current->next;

	while (current != NULL) {
		shipment * newCurrent = newStart;
		bool found = false;
		while (newCurrent != NULL){
			if (strcmp(newCurrent->goods, current->goods) == 0) {
				newCurrent->quantity += current->quantity;
				found = true;
			}
			newCurrent = newCurrent->next;
		}
		if (!found) {
			shipment* newTemp = new shipment;
			strcpy_s(newTemp->goods, current->goods);
			newTemp->quantity = current->quantity;
			newTemp->next = NULL;
			newLast->next = newTemp;
			newLast = newLast->next;
		}
		current = current->next;
	}
	return newStart;
}

void SortByQuantity(shipment * newStart){
	bool isSorted = false;
	shipment * newCurrent;
	shipment * previous;
	if (newStart == NULL)
		return;
	if (newStart->next == NULL)
		return;
	while (!isSorted){
		newCurrent = newStart->next;
		previous = newStart;
		isSorted = true;
		while (newCurrent != NULL){
			if (previous->quantity > newCurrent->quantity){
				isSorted = false;
				int quantity;
				char goods[64];
				quantity = newCurrent->quantity;
				strcpy(goods, newCurrent->goods);
				newCurrent->quantity = previous->quantity;
				strcpy(newCurrent->goods, previous->goods);
				previous->quantity = quantity;
				strcpy(previous->goods, goods);
			}
			previous = newCurrent;
			newCurrent = newCurrent->next;
		}
	}
}

void Sheet2(shipment* start) {
	shipment* current = start;
	int i = 0;
	cout << "The list of goods is sorted by quantity in the warehouse: " << endl;
	cout << endl;
	cout << "#\t" << "Goods\t" << "Quantity\t\t" << endl;
	cout << "---------------------------" << endl;
	while (current != NULL) {
		cout << i + 1 << '\t'
			<< current->goods << '\t'
			<< current->quantity << '\t'
			<< endl;
		cout << endl;
		current = current->next;
		i++;
	}
}

void deleteList1(shipmaker *& start){
	shipmaker * current = start;
	shipmaker * next = NULL;
	while (current != NULL){
		next = current->next;
		delete current;
		current = next;
	}
	start = NULL;
}

void deleteList2(shipment *& newStart){
	shipment * newCurrent = newStart;
	shipment * next = NULL;
	while (newCurrent != NULL){
		next = newCurrent->next;
		delete newCurrent;
		newCurrent = next;
	}
	newStart = NULL;
}

void main() {
	int deal;
	cout << "Do you want to fill in the data? Press '1' to begin - ";
	cin >> deal;
	cout << "If you want to stop entering press 'enter' in case of next element." << endl;
	if (deal == 1) {
		int actualSize = 0;
		shipmaker* start = NULL;
		cin.ignore();
		Fill(start);
		Sheet1(start);
		ShowMaker(start);
		shipment* newStart = QuantityCount(start);
		SortByQuantity(newStart);
		//system("cls");
		Sheet2(newStart);
		deleteList1(start);
		deleteList2(newStart);
	}
	else
		exit(0);
	system("pause");

}