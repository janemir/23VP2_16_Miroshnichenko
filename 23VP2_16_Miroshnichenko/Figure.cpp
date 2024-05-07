#include "Figure.h"
Figure::Position::Position()
{
	x = 0;
	y = 0;
}
Figure::Position::Position(long x, long y)
{
	this->x = x;
	this->y = y;
}
POINT* Figure::ConvertVertices() const
{
	POINT* v = new POINT[VertexCount];
	for (int i = 0; i < VertexCount; i++)
	{
			POINT p = POINT();
		p.x = Vertices[i].x;
		p.y = Vertices[i].y;
		v[i] = p;
	}
	return v;
}
Figure::Position Figure::GetPosition() const
{
	return position;
}
void Figure::Move(Position pos)
{
	bool vis = visible;
	if (vis) Hide();
	long offsetx = pos.x - position.x;
	long offsety = pos.y - position.y;
	position = pos;
	for (int i = 0; i < VertexCount; i++)
	{
		Vertices[i].x += offsetx;
		Vertices[i].y += offsety;
		if ((Vertices[i].x < 0) || (Vertices[i].y < 0))
		{
			const char* w = "Выход за пределы экрана - одна из вершин имеет отрицательные координаты";
				const char* r = "Переместите фигуру или измените координату вершины во время построения фигуры";
				throw FigureException(w, r);
		}
	}
	if (vis) Show();
}
void Figure::Show()
{
	if (visible) return;
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN hGreenBrush = CreatePen(PS_SOLID, 2, RGB(0, 250, 0));
	HBRUSH hRedBrush = CreateSolidBrush(RGB(250, 0, 0));
	SelectObject(hdc, hRedBrush);
	SelectObject(hdc, hGreenBrush);
	auto v = ConvertVertices();
	Polygon(hdc, v, VertexCount);
	visible = true;
	delete[] v;
}
void Figure::Hide()
{
	if (!visible) return;
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN hBlackPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackPen);
	SelectObject(hdc, hBlackBrush);
	auto v = ConvertVertices();
	Polygon(hdc, v, VertexCount);
	DeleteObject(hBlackBrush);
	DeleteObject(hBlackPen);
	visible = false;
	delete[] v;
}
Figure::~Figure()
{
	delete[] Vertices;
}
FigureException::FigureException(const char* what, const char* recommendation) :
	std::exception(what)
{
	this->_what = what;
	this->recommendation = recommendation;
}
void FigureException::whatHappened() const
{
	std::cout << _what << std::endl << recommendation << std::endl;
}
Figure::Position pos(long x, long y)
{
	return Figure::Position(x, y);
}