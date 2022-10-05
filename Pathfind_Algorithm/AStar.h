#pragma once
#include "IPathfind.h"

class AStar : public IPathfind
{
	bool Pathfind(vector<bool> map, Point start, Point end) override;
};