#include "ComplexFigure.h"
ComplexFigure::ComplexFigure(Position pos, long width, long height, Position*
	Vertices, int VertexCount)
{
	position = pos;
	inner = new Rhombus(pos, width, height);
	outer = new PolygonFigure(pos, Vertices, VertexCount);
}
void ComplexFigure::Show()
{
	outer->Show();
	inner->Show();
}
void ComplexFigure::Hide()
{
	outer->Hide();
	inner->Hide();
}
void ComplexFigure::Move(Position position)
{
	outer->Move(position);
	inner->Move(position);
}
ComplexFigure::~ComplexFigure()
{
	delete inner;
	delete outer;
}
bool testCompCreate1()
{
	try
	{
		Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
		ComplexFigure r = ComplexFigure(pos(100, 100), 10, 10, v, 3);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testCompCreate2()
{
	try
	{
		Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
		ComplexFigure r = ComplexFigure(pos(0, 0), 10, 10, v, 3);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testCompCreate3()
{
	try
	{
		Figure::Position v[3]{ pos(-10, -15), pos(-20, -15), pos(-15, -20) };
		ComplexFigure r = ComplexFigure(pos(0, 0), 10, 10, v, 3);
	}
		catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testCompCreate4()
{
	try
	{
		Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
		ComplexFigure r = ComplexFigure(pos(10000, 10000), 10, 10, v, 3);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testCompMove1()
{
	try
	{
		Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
		ComplexFigure r = ComplexFigure(pos(100, 100), 10, 10, v, 3);
		r.Move(pos(10, 10));
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testCompMove2()
{
	try
	{
		Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
		ComplexFigure r = ComplexFigure(pos(100, 100), 10, 10, v, 3);
		r.Move(pos(-100, -100));
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
		return false;
}
bool testCompShow()
{
	Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
	ComplexFigure r = ComplexFigure(pos(100, 100), 10, 10, v, 3);
	try
	{
		r.Show();
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testCompHide()
{
	Figure::Position v[3]{ pos(10, 15), pos(20, 15), pos(15, 20) };
	ComplexFigure r = ComplexFigure(pos(100, 100), 10, 10, v, 3);
	r.Show();
	try
	{
		r.Hide();
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
