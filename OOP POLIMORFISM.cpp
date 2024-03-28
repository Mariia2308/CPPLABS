#include<iostream>
using namespace std;

class Lecturer
{
protected:
	char surname[64];
	float experience;
	float salary;
	char title[64];

public:
	Lecturer(){
		strcpy_s(this->surname, "");
		this->experience = 0;
		this->salary = 0;
		strcpy_s(this->title, "");
	}

	Lecturer(char surname[64], float experience, float salary){
		strcpy_s(this->surname, surname);
		this->experience = experience;
		this->salary = salary;
		strcpy_s(this->title, "Lecturer");
	}

	virtual void ShowReport(){

		cout << "Surname: " << surname << "  ";
		cout << "Experience: " << experience << "  ";
		cout << "Salary: " << GetSalary() << "  ";
		cout << "Title: " << title << "  ";
	}

	virtual float GetSalary(){
		return salary;
	}
};

class SeniorLecturer : public Lecturer{
public:
	SeniorLecturer(char surname[64], float experience, float salary) :Lecturer(surname, experience, salary){
		strcpy_s(this->title, "Senior Lecturer");
	}
	void ShowReport() override {
		cout << "Surname: " << surname << "  ";
		cout << "Salary: " << GetSalary() << "  ";
		cout << "Title: " << title << "  ";
	}
	float GetSalary() override {
		float fullSalary = this->salary;
		if (experience > 5)
			fullSalary += (salary*0.1);
		if (experience > 10)
			fullSalary += (salary*0.15);
		if (experience > 15)
			fullSalary += (salary*0.2);
		return fullSalary;
	}
};

class Docent : public SeniorLecturer{
protected:
	bool isCandidate;
public:
	Docent(char surname[64], float experience, float salary, bool isCandidate) : SeniorLecturer(surname, experience, salary){
		this->isCandidate = isCandidate;
		strcpy_s(this->title, "Docent");
		
	}
	void ShowReport() override{
		cout << "Surname: " << surname << " ";
		cout << "Salary: " << GetSalary() << " ";
		cout << "Title: " << title << " s";

		cout << "Has candidate degree? ";
		if (this->isCandidate)
			cout << "Yes. ";
		else
			cout << "No. ";
	}
	float GetSalary() override {
		float fullSalary = this->salary;
		fullSalary += (salary * 0.1);
		if (experience > 5)
			fullSalary += (salary * 0.1);
		if (experience > 10)
			fullSalary += (salary*0.15);
		if (experience > 15)
			fullSalary += (salary * 0.2);
		else if (this->isCandidate)
			fullSalary += (salary * 0.1);
		return fullSalary;
	}
};

class Professor : public Docent{
private:
	bool isDoctor;
public:
	Professor(char surname[64], float experience, float salary, bool isCandidate, bool isDoctor)
		: Docent(surname, experience, salary, isCandidate){
		this->isDoctor = isDoctor;
		strcpy_s(this->title, "Professor");
	}
	void ShowReport() override{
		cout << "Surname: " << surname << "  ";
		cout << "Salary: " << GetSalary() << "  ";
		cout << "Title: " << title << "  ";
		cout << "Has candidate degree? ";
		if (this->isCandidate)
			cout << "Yes. ";
		else
			cout << "No. ";
		cout << "Has doctor degree? ";
		if (this->isDoctor)
			cout << "Yes. ";
		else
			cout << "No. ";
	}
	float GetSalary() override {
		float fullSalary = this->salary;
		fullSalary += (salary * 0.2);
		if (experience > 5)
			fullSalary += (salary*0.1);
		if (experience > 10)
			fullSalary += (salary*0.15);
		if (experience > 15){
			fullSalary += (salary*0.2);
			if (this->isCandidate)
				fullSalary += (salary* 0.1);
			else if (this->isDoctor)
				fullSalary += (salary * 0.15);
		}
		return fullSalary;
	}
};

class LecturerArray{
private:
	int maxSize;
	int actualSize;
	Lecturer ** elements;

	void Increase(){
		int newMaxSize = maxSize * 2;
		Lecturer ** newElements = new Lecturer*[newMaxSize];
		for (int i = 0; i < maxSize; i++)
			newElements[i] = elements[i];

		delete[] elements;
		elements = newElements;
		maxSize = newMaxSize;
	}
public:
	LecturerArray(){
		maxSize = 1;
		actualSize = 0;
		elements = new Lecturer *[maxSize];
	}

	LecturerArray(int maxSize){
		this->maxSize = maxSize;
		actualSize = 0;
		elements = new Lecturer *[maxSize];
	}

	int Size(){
		return this->actualSize;
	}

	void Add(Lecturer * item){
		if (actualSize >= maxSize)
			Increase();
		elements[actualSize] = item;
		actualSize++;
	}

	Lecturer *operator[](int index){

		if (index < this->actualSize && index >= 0)
			return elements[index];
	}

	~LecturerArray(){
		delete[] elements;
	}
};

class Departament {
private:
	char title[64];
	LecturerArray * lecturers;
public:
	Departament(char title[64]){
		strcpy_s(this->title, title);
		this->lecturers = new LecturerArray();
	}

	void Add(Lecturer * newPrepod){
		this->lecturers->Add(newPrepod);
	}

	void ShowPrepodReport(){
		cout << title << endl;
		for (int i = 0; i < this->lecturers->Size(); i++)
		{
			(*this->lecturers)[i]->ShowReport();
			cout << endl;
		}
		cout << "Total Salary: " << TotalSalary() << endl;
	}

	float TotalSalary(){
		float totalSalary = 0;
		for (int i = 0; i < this->lecturers->Size(); i++){
			totalSalary += (*this->lecturers)[i]->GetSalary();
		}
		return totalSalary;
	}

	~Departament()
	{
		for (int i = 0; i < this->lecturers->Size(); i++)
		{
			delete (*this->lecturers)[i];
		}
		delete lecturers;
	}
};


void main(){
	Departament ZFFTT = Departament("KAFEDRA ZAGAL'NOII FIZYKY TA FIZYKY TVERDOGO TILA");
	Lecturer * lector1 = new Lecturer("Kikot", 8, 2000);
	SeniorLecturer * seniorlector1 = new SeniorLecturer("Chornobryviy", 6, 3000);
	Docent * docent1 = new Docent("Reva", 9, 4000, false);
	Professor * profesor1 = new Professor("Tartachnyk", 6, 5000, false, true);
	ZFFTT.Add(lector1);
	ZFFTT.Add(seniorlector1);
	ZFFTT.Add(docent1);
	ZFFTT.Add(profesor1);
	ZFFTT.ShowPrepodReport();
	cout << endl;

	

	Departament MAtaTI = Departament("KAFEDRA MATEMATYCHNOGO ANALIZU TA TEORII IMOVIRNOSTI");
	Lecturer * lector2 = new Lecturer("Muravska", 5, 2000);
	SeniorLecturer * seniorlector2 = new SeniorLecturer("Dvoychenkov", 12, 3000);
	Docent * docent2 = new Docent("Bryzhenko", 11, 4000, true);
	Professor * profesor2 = new Professor("Gorenstein", 16, 5000, true, true);
	MAtaTI.Add(lector2);
	MAtaTI.Add(seniorlector2);
	MAtaTI.Add(docent2);
	MAtaTI.Add(profesor2);
	MAtaTI.ShowPrepodReport();
	

	system("pause");
}