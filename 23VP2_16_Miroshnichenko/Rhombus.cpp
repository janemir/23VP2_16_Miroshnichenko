#include "Rhombus.h"
Rhombus::Rhombus(Position position, long width, long height)
{
	if (width <= 0)
	{
		const char* w = "Ширина ромба отрицательна или равна нулю";
		const char* r = "Ширина ромба должна быть больше нуля";
		throw new FigureException(w, r);
	}
	if (height <= 0)
	{
		const char* w = "Высота ромба отрицательна или равна нулю";
		const char* r = "Высота ромба должна быть больше нуля";
		throw new FigureException(w, r);
	}
	this->position = position;
	this->width = width;
	this->height = height;
	VertexCount = 4;
	Vertices = new Position[VertexCount];
	Position top;
	top.x = position.x;
	top.y = position.y - height;
	if ((top.x < 0) || (top.y < 0))
	{
		const char* w = "Верхняя вершина ромба выходит за экран";
		const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Position down;
	down.x = position.x;
	down.y = position.y + height;
	if ((down.x < 0) || (down.y < 0))
	{
		const char* w = "Нижняя вершина ромба выходит за экран";

			const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Position left;
	left.x = position.x - width;
	left.y = position.y;
	if ((left.x < 0) || (left.y < 0))
	{
		const char* w = "Левая вершина ромба выходит за экран";
		const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Position right;
	right.x = position.x + width;
	right.y = position.y;
	if ((right.x < 0) || (right.y < 0))
	{
		const char* w = "Правая вершина ромба выходит за экран";
		const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Vertices[0] = top;
	Vertices[1] = left;
	Vertices[2] = down;
	Vertices[3] = right;
}
long Rhombus::GetWidth() const
{
	return width;
}
long Rhombus::GetHeight() const
{
	return height;
}
void Rhombus::SetSize(long width, long height)
{
	if (width <= 0)
	{
		const char* w = "Ширина ромба отрицательна или равна нулю";
		const char* r = "Ширина ромба должна быть больше нуля";
		throw FigureException(w, r);
	}
	if (height <= 0)
	{
		const char* w = "Высота ромба отрицательна или равна нулю";
		const char* r = "Высота ромба должна быть больше нуля";
		throw FigureException(w, r);
	}
		bool vis = visible;
	if (vis) Hide();
	this->width = width;
	this->height = height;
	Figure::Position& top = Vertices[0];
	top.x = position.x;
	top.y = position.y - height;
	if ((top.x < 0) || (top.y < 0))
	{
		const char* w = "Во время изменения высоты верхняя вершина ромба вышла за экран";
			const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Figure::Position& left = Vertices[1];
	left.x = position.x - width;
	left.y = position.y;
	if ((left.x < 0) || (left.y < 0))
	{
		const char* w = "Во время изменения ширины левая вершина ромба вышла за экран";
			const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Figure::Position& down = Vertices[2];
	down.x = position.x;
	down.y = position.y + height;
	if ((down.x < 0) || (down.y < 0))
	{
		const char* w = "Во время изменения высоты нижняя вершина ромба вышла за экран";
			const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
	Figure::Position& right = Vertices[3];
	right.x = position.x + width;
	right.y = position.y;
	if ((right.x < 0) || (right.y < 0))
	{
		const char* w = "Во время изменения ширины правая вершина ромба вышла за экран";
			const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
			throw FigureException(w, r);
	}
		if (vis) Show();
}
///////////////////////////////////
// Unit tests
bool testRhombusCreate2Pos()
{
	try
	{
		Rhombus r = Rhombus(pos(-100, 100), 10, 10);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testRhombusCreate3Pos()
{
	try
	{
		Rhombus r = Rhombus(pos(100, -100), 10, 10);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testRhombusCreateNegativeWidth()
{
	try
	{
		Rhombus r = Rhombus(pos(100, 100), -10, 10);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testRhombusCreateNegativeHeight()
{
	try
	{
		Rhombus r = Rhombus(pos(100, 100), 10, -10);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
			return true;
	}
	return false;
}
bool testRhombusMove1()
{
	Rhombus r = Rhombus(pos(10, 10), 10, 10);
	try
	{
		r.Move(pos(20, 20));
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testRhombusMove2()
{
	Rhombus r = Rhombus(pos(10, 10), 10, 10);
	try
	{
		r.Move(pos(-20, -20));
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}
bool testRhombusSetSize1()
{
	Rhombus r = Rhombus(pos(10, 10), 10, 10);
	try
	{
		r.SetSize(20, 20);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return false;
	}
	return true;
}
bool testRhombusSetSize2()
{
	Rhombus r = Rhombus(pos(10, 10), 10, 10);
	try
	{
		r.SetSize(-20, -20);
	}
	catch (FigureException ex)
	{
		ex.whatHappened();
		return true;
	}
	return false;
}