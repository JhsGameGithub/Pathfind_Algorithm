#pragma once
#include <vector>

//��ǥ ����ü ���� ����
struct Point;

//��ã�� �˰��� �������̽�
class IPathfind
{
	virtual bool Pathfind(std::vector<std::vector<bool>> map, Point start, Point end) = 0;
};