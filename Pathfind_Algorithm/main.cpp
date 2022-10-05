#include <iostream>
#include "Point.h"

constexpr extern int Heuristic(const Point& start, const Point& end)
{
	return abs(start.x - end.x) + abs(start.y - end.y);
}

int main()
{
	return 0;
}