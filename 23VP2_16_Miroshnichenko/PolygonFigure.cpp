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
			const char* w = "���������� x ��� y ����� ������������� �������� ��� ������� : " + i;
				const char* r = "�������� ��������� Vertices ��� position";
			throw FigureException(w, r);
		}
	}
}
