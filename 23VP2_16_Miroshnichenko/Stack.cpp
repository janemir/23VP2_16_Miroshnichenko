#include "Stack.h"
void Stack::Push(Figure* figure)
{
	if (figure == nullptr) return;
	_stack.emplace(figure);
}
Figure* Stack::Pop()
{
	auto figure = _stack.top();
	_stack.pop();
	return figure;
}
void Stack::ShowAll()
{
	auto list = _stack._Get_container();
	for (auto it = list.cbegin(); it != list.cend(); it++)
	{
		Figure* f = *it;
		f->Show();
	}
}
Stack::~Stack()
{
}
