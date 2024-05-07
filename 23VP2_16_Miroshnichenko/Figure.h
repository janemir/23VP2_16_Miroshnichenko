#pragma once
#include <iostream>
#include <windows.h>
#include <string>
class Figure
{
public:
	struct Position
	{
		Position();
		Position(long x, long y);
		long x, y;
	};
protected:
	Position position;
	bool visible = false;
	int VertexCount = 0;
	Position* Vertices = nullptr;
	POINT* ConvertVertices() const;
public:
	Position GetPosition() const;
	virtual void Move(Position pos);
	virtual void Show();
	virtual void Hide();
	~Figure();
};
class FigureException : public std::exception
{
	std::string recommendation = "";
	std::string _what = "";
public:
	FigureException(const char* what, const char* recommendation);
	void whatHappened() const;
};
Figure::Position pos(long, long);