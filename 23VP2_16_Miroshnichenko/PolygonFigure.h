#pragma once
#include "Figure.h"
class PolygonFigure : public Figure
{
public:
	PolygonFigure(Position position, Position* Vertices, int VertexCount);
};