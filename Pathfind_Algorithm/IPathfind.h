#pragma once
#include <vector>

using namespace std;

struct Point;

class IPathfind
{
	virtual bool Pathfind(vector<bool> map, Point start, Point end) = 0;
};