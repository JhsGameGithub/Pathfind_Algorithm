#pragma once
#include <vector>

//좌표 구조체 전방 선언
struct Point;

//길찾기 알고리즘 인터페이스
class IPathfind
{
	virtual bool Pathfind(std::vector<std::vector<bool>> map, Point start, Point end) = 0;
};