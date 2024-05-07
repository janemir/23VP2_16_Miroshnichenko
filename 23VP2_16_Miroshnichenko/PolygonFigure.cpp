#include "PolygonFigure.h"
PolygonFigure::PolygonFigure(Position position, Position* Vertices, int VertexCount)
{
	this->VertexCount = VertexCount;
	this->position = position;
	this->Vertices = new Position[VertexCount];
	for (int i = 0; i < VertexCount; i++)
	{
		this->Vertices[i] = Vertices[i];
	}
	for (int i = 0; i < VertexCount; i++)
	{
		auto p = &(this->Vertices[i]);
			p->x = p->x + position.x;
		p->y = p->y + position.y;
		if ((p->x < 0) || (p->y < 0))
		{
			const char* w = "Координата x или y имеет отрицательное значение под номером : " + i;
				const char* r = "измените параметры Vertices или position";
			throw FigureException(w, r);
		}
	}
}
