#pragma once

struct Node
{
	int m_f_cost, m_g_cost, m_h_cost;
	Node* m_parent_node;

	bool operator<(const Node* a_node) const
	{
		return m_f_cost > a_node->m_f_cost;
	}
};