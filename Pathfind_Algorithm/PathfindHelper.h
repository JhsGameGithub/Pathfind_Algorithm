#pragma once
#include <iostream>

#include "Point.h"

//길찾기 관련 비멤버 함수들
//path find helper
namespace pfh
{
	//straight direction
	Point str_dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

	//diagonal direction
	Point dia_dir[4] = { {1,1},{-1,-1},{1,-1},{-1,1} };

	//휴리스틱 함수
	int Heuristic(const Point& start, const Point& end)
	{
		return abs(start.m_x - end.m_x) + abs(start.m_y - end.m_y);
	}

	//이동 가능여부 판단
	bool Check_Road(const std::vector<std::vector<bool>>& map,const Point& current)
	{
		//0(false)이 길이고 1(true)이 벽이기 때문에
		//반대로 반환하면 가능여부 판단이 가능
		return !map[current.m_x][current.m_y];
	}

	//크기 제한여부 판단
	bool Check_Limit(int x_limit, int y_limit, const Point& current)
	{
		//x,y 값이 각각 0보다는 크거나 같고, 제한 값보다는 작아야 함.
		return current.m_x >= 0 && current.m_x < x_limit&& current.m_y >= 0 && current.m_y < y_limit;
	}
}