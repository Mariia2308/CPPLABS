#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Figure{
protected:
	HDC* hdc;
	HPEN hPen;
	HPEN bgPen;
	HBRUSH hBrush;
	HBRUSH bgBrush;
	virtual void Design() = 0;
public:
	Figure(HDC* _hdc_, COLORREF _bgColor_, COLORREF _frColor_){
		hdc = _hdc_;
		bgPen = CreatePen(PS_DOT, 5, _frColor_);
		hPen = CreatePen(PS_DOT, 5, _bgColor_);
		bgBrush = CreateSolidBrush(_frColor_);
		hBrush = CreateSolidBrush(_bgColor_);
	}
	void Show(){
		SelectObject(*hdc, bgPen);
		SelectObject(*hdc, bgBrush);
		Design();
	}
	void Hide(){
		SelectObject(*hdc, hPen);
		SelectObject(*hdc, hBrush);
		Design();
	}
	~Figure(){
		DeleteObject(bgPen);
		DeleteObject(hPen);
		DeleteObject(bgBrush);
		DeleteObject(hBrush);
	}
	void ChangeColor(COLORREF color){
		Hide();
		DeleteObject(bgPen);
		DeleteObject(bgBrush);
		bgPen = CreatePen(PS_DOT, 5, color);
		bgBrush = CreateSolidBrush(color);
	}
};

class Square : public Figure{
private:
	int x1, y1, x2, y2;
public:
	Square(HDC* _hdc_, COLORREF _bgColor_, COLORREF _frColor_, int _x1, int _y1, int _x2, int _y2) : Figure(_hdc_, _bgColor_, _frColor_){
		this->hdc = hdc;
		this->x1 = _x1;
		this->y1 = _y1;
		this->x2 = _x2;
		this->y2 = _y2;
	}
private:
	void Design() override{
		Rectangle(*hdc, x1, y1, x2, y2);
	}
};

class PolyAngle : public Figure{
private:
	POINT point2[5];
public:
	PolyAngle(HDC* _hdc_, COLORREF _bgColor_, COLORREF _frColor_, const POINT* pointFive) : Figure(_hdc_, _bgColor_, _frColor_){
		for (int i = 0; i < 5; i++)
			this->point2[i] = pointFive[i];
	}
private:
	void Design() override{
		Polygon(*hdc, point2, 5);
	}
};

class Star : public Figure{
private:
	POINT points3[10];
public:
	Star(HDC* _hdc_, COLORREF _bgColor_, COLORREF _frColor_, const POINT* pointsStar) : Figure(_hdc_, _bgColor_, _frColor_){
		for (int i = 0; i < 10; i++)
			this->points3[i] = pointsStar[i];
	}
private:
	void Design() override{
		Polygon(*hdc, points3, 10);
	}
};


int main(){
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);

	int colors = 5;
	int index2 = 0;

	COLORREF bgColor = RGB(0, 0, 0);
	COLORREF *color = new COLORREF[colors];
	for (int i = 0; i < colors; i++){
		color[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
	}

	int n = 3;
	int index1 = 0;
	Figure** figure = new Figure *[n];

	POINT fiveAngle[5]{{ 350, 125 }, { 525, 250 }, { 450, 450 }, { 250, 450 }, { 175, 250 }};
	POINT poly[10] = { { 350, 125 }, { 425, 225 }, { 525, 250 }, { 450, 325 }, 
	{ 450, 450 }, { 350, 400 }, { 250, 450 }, { 250, 325 }, { 175, 250 }, { 275, 225 } };

	figure[0] = new Square(&hdc, bgColor, *color, 200, 200, 500, 400);
	figure[1] = new PolyAngle(&hdc, bgColor, *color, fiveAngle);
	figure[2] = new Star(&hdc, bgColor, *color, poly);

	figure[index1]->Show();

	int code;
	do{
		code = _getch();
		if (code == 224)
			code = _getch();
		switch (code){
		case 80:{
					figure[index1]->Hide();
					index1 = (index1 - 1 + n) % n;
					figure[index1]->Show();
					break;}
		case 72:{
					figure[index1]->Hide();
					index1 = (index1 + 1) % n;
					figure[index1]->Show();
					break;}
		case 75:{
					index2 = (index2 + 1) % colors;
					for (int i = 0; i < n; i++){
						figure[i]->ChangeColor(color[index2]);
					}
					figure[index1]->Show();
					break;}
		case 77:{
					index2 = (index2 + 1) % colors;
					for (int i = 0; i < n; i++){
						figure[i]->ChangeColor(color[index2]);
					}
					figure[index1]->Show();
					break;}
		}
	} while (code != 27);
	ReleaseDC(hWnd, hdc);
	for (int i = 0; i < n; i++)
		delete figure[i];
	delete[] figure;
	delete[] color;
}
