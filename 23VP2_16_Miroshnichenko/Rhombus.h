#pragma once
#include "Figure.h"
class Rhombus : public Figure
{
	long width, height;
public:
	Rhombus(Position position, long width, long height);
	long GetWidth() const;
	long GetHeight() const;
	void SetSize(long, long);
};
///////////////////////////////////////////////////
// unit tests
bool testRhombusCreate1Pos();
bool testRhombusCreate2Pos();
bool testRhombusCreate3Pos();
bool testRhombusCreateNegativeWidth();
bool testRhombusCreateNegativeHeight();
bool testRhombusMove1();
bool testRhombusMove2();
bool testRhombusSetSize1();
bool testRhombusSetSize2();
