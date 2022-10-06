#pragma once
#include "IPathfind.h"

//A* 알고리즘 클래스
class AStar : public IPathfind
{
public:
	//길찾기 함수
	//시작 지점에서 도착 지점까지 가는
	//최단 거리를 찾았으면 true을 반환
	bool Pathfind(std::vector<std::vector<bool>> map, Point start, Point end) override;

private:
	std::vector<std::vector<bool>> m_close_list;
};