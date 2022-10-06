#pragma once
#include <iostream>

#include "Point.h"

//��ã�� ���� ���� �Լ���
//path find helper
namespace pfh
{
	//straight direction
	Point str_dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

	//diagonal direction
	Point dia_dir[4] = { {1,1},{-1,-1},{1,-1},{-1,1} };

	//�޸���ƽ �Լ�
	int Heuristic(const Point& start, const Point& end)
	{
		return abs(start.m_x - end.m_x) + abs(start.m_y - end.m_y);
	}

	//�̵� ���ɿ��� �Ǵ�
	bool Check_Road(const std::vector<std::vector<bool>>& map,const Point& current)
	{
		//0(false)�� ���̰� 1(true)�� ���̱� ������
		//�ݴ�� ��ȯ�ϸ� ���ɿ��� �Ǵ��� ����
		return !map[current.m_x][current.m_y];
	}

	//ũ�� ���ѿ��� �Ǵ�
	bool Check_Limit(int x_limit, int y_limit, const Point& current)
	{
		//x,y ���� ���� 0���ٴ� ũ�ų� ����, ���� �����ٴ� �۾ƾ� ��.
		return current.m_x >= 0 && current.m_x < x_limit&& current.m_y >= 0 && current.m_y < y_limit;
	}
}