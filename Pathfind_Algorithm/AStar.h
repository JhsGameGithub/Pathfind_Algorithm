#pragma once
#include "IPathfind.h"

//A* �˰��� Ŭ����
class AStar : public IPathfind
{
public:
	//��ã�� �Լ�
	//���� �������� ���� �������� ����
	//�ִ� �Ÿ��� ã������ true�� ��ȯ
	bool Pathfind(std::vector<std::vector<bool>> map, Point start, Point end) override;

private:
	std::vector<std::vector<bool>> m_close_list;
};