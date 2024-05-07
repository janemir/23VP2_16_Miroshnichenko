//// 23VP2_16_Miroshnichenko

#include "ComplexFigure.h"
#include "Stack.h"
#include <cassert>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Тестирование начато\n"<< endl;

	assert(testCompCreate1());
	assert(testCompCreate2());
	assert(testCompCreate3());
	assert(testCompCreate4());

	assert(testCompMove1());
	assert(testCompMove2());

	assert(testCompShow());
	assert(testCompHide());

	cout << "\nТестирование завершено успешно\n" << endl;

	Sleep(1200);

	Figure::Position v[4]{ pos(0, 0), pos(50, 0), pos(50, 50), pos(0, 50) };

	PolygonFigure p(pos(100, 100), v, 4);

	Rhombus r(pos(500, 200), 40, 70);

	////////////////////////////////////////////
	Figure::Position v1[5]{ pos(-50, -50), pos(50, 0), pos(50, 50), pos(25, 25), pos(0, 50) };

	ComplexFigure c(pos(700, 300), 55, 25, v1, 5);

	////////////////////////////////////////////
	Stack stack;

	stack.Push(&p);
	stack.Push(&r);
	stack.Push(&c);

	stack.ShowAll();

	Sleep(3000);

	////////////////////////////////////////////
	p.Hide(); r.Hide(); c.Hide();

	p.Move(pos(p.GetPosition().x + 550, p.GetPosition().y - 50));

	r.SetSize(r.GetWidth() + 70, r.GetHeight() - 10);

	c.Move(pos(c.GetPosition().x - 370, c.GetPosition().y - 120));

	Sleep(2000);

	////////////////////////////////////////////
	stack.Push(&p);
	stack.Push(&r);
	stack.Push(&c);

	stack.ShowAll();

	Sleep(9000);

}

