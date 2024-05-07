#pragma once
#include "Figure.h"
#include "PolygonFigure.h"
#include "Rhombus.h"
class ComplexFigure : public Figure
{
	Rhombus* inner;
	PolygonFigure* outer;
public:
	ComplexFigure(Position, long, long, Position*, int);
	void Show() override;
	void Hide() override;
	void Move(Position) override;
	~ComplexFigure();
};
////////////////////////////////////////////////////
// unit tests
bool testCompCreate1();
bool testCompCreate2();
bool testCompCreate3();
bool testCompCreate4();
bool testCompMove1();
bool testCompMove2();
bool testCompShow();
bool testCompHide();
