#include <iostream>
#include <iomanip> 
using namespace std;

class CustomArray{
private:

	int maxSize;
	int actualSize;
	int *elements;
	float arsum;
	void Increase(){
		int newMaxSize = maxSize * 2;
		int *newElements = new int[newMaxSize];
		for (int i = 0; i < maxSize; i++)
			newElements[i] = elements[i];
		delete[] elements;
		elements = newElements;
		maxSize = newMaxSize;
	}
	void ArSum(){
		float minEl = elements[0];
		float maxEl = elements[0];
		for (int i = 1; i < actualSize; i++){
			if (elements[i] < minEl)
				minEl = elements[i];
			else if (elements[i] > maxEl)
				maxEl = elements[i];
		}
		arsum = (minEl + maxEl) / 2;
	}

public:
	CustomArray(){
		maxSize = 1;
		actualSize = 0;
		elements = new int[maxSize];
		arsum = 0;
	}

	CustomArray(int maxSize){
		this->maxSize = maxSize;
		actualSize = 0;
		elements = new int[maxSize];
		arsum = 0;
	}

	void Add(int element){
		if (actualSize >= maxSize)
			Increase();
		elements[actualSize] = element;
		actualSize++;
	}

	void Sort(){
		ArSum();
		cout << endl;
		cout << "Arithmetical mean of minimal and maximal elements: " << arsum << endl;
		for (int i = 0; i < actualSize - 1; i++){
			for (int j = 0; j < actualSize - 1 - i; j++){
				if ((abs(elements[j] - arsum)) >(abs(elements[j + 1] - arsum)))
				{
					float temp = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = temp;
				}
			}
		}
		cout << endl;
	}

	int &operator[](int index){
		if (index >= 0 && index < actualSize)
			return elements[index];
	}

	int ActualSize(){
		return actualSize;
	}

	~CustomArray(){
		delete[] elements;
	}
};

CustomArray * EnterArray(int demention){
	int temp;
	CustomArray * myArray = new CustomArray(demention);
	cout << "Enter the elements of the array: " << "\n";
	for (int i = 0; i < demention; i++){
		cout << i + 1 << " element: ";
		cin >> temp;
		myArray->Add(temp);
	}
	return myArray;
}

void AddToElements(CustomArray * myArray){
	int temp;
	cout << myArray->ActualSize() + 1 << " element: ";
	cin >> temp;
	while (temp != 0){
		cout << myArray->ActualSize() + 2 << " element: ";
		myArray->Add(temp);
		cin >> temp;
	}
}

void PrintArray(CustomArray * myArray){
	for (int i = 0; i < (*myArray).ActualSize(); i++)
		cout << (*myArray)[i] << "\t";
	cout << endl;
}

void main(){
	cout << "Laboratorna robota #4" << "\n"
		<< "studentky grupy OF-01 FMF" << "\n"
		<< "Kaplaushenko M.V" << "\n"
		<< "Variant #5 " << endl;
	cout << endl;

	int demention = 0;
	int agree;
	cout << "Enter the demention of array: ";
	cin >> demention;
	CustomArray *  myArray = EnterArray(demention);
	cout << "Entered array: " << endl;
	PrintArray(myArray);
	myArray->Sort();
	cout << "Sorted array: " << endl;
	PrintArray(myArray);
	cout << endl;

	cout << "Do you want to add elements to array?" << "\n"
		<< "Press < 1 > to continue filling the array, < 0 > if that's enough: ";
	cin >> agree;
	if (agree == 1){
		AddToElements(myArray);
		cout << endl;
		cout << "Entered array: " << endl;
		PrintArray(myArray);
		myArray->Sort();
		cout << "Sorted array: " << endl;
		PrintArray(myArray);
	}
	system("pause");
}