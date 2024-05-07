#pragma once
#include "Figure.h"
#include <stack>
#include <list>
using namespace std;
class Stack
{
	stack<Figure*, list<Figure*>> _stack;
public:
	void Push(Figure*);
	Figure* Pop();
	void ShowAll();
	~Stack();
};
