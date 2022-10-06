#pragma once
#include "Point.h"

//�켱���� ť�� ���� ��� ����ü
struct Node
{
	//�ڽ�Ʈ
	int m_f_cost, m_g_cost, m_h_cost;
	//��ǥ
	Point m_point;
	//�θ� ���
	Node* m_parent_node;

	void Set_Cost(int a_g_cost, int a_h_cost)
	{
		m_g_cost = a_g_cost;
		m_h_cost = a_h_cost;
		m_f_cost = a_g_cost + a_h_cost;
	}

	//������ �����ε�(�ڽ�Ʈ ���� ��� �켱)
	bool operator<(const Node* rhs) const
	{
		return m_f_cost > rhs->m_f_cost;
	}
};