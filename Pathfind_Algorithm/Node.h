#pragma once
#include "Point.h"

//우선순위 큐에 넣을 노드 구조체
struct Node
{
	//코스트
	int m_f_cost, m_g_cost, m_h_cost;
	//좌표
	Point m_point;
	//부모 노드
	Node* m_parent_node;

	void Set_Cost(int a_g_cost, int a_h_cost)
	{
		m_g_cost = a_g_cost;
		m_h_cost = a_h_cost;
		m_f_cost = a_g_cost + a_h_cost;
	}

	//연산자 오버로딩(코스트 적은 노드 우선)
	bool operator<(const Node* rhs) const
	{
		return m_f_cost > rhs->m_f_cost;
	}
};