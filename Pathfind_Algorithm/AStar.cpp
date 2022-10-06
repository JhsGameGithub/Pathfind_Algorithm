#include <memory>
#include <queue>

#include "AStar.h"
#include "Point.h"
#include "Node.h"
#include "PathfindHelper.h"


//0 == ��
//1 == ��
//��ã�� �˰���.
//�������� ã���� true�� ��ȯ
bool AStar::Pathfind(std::vector<std::vector<bool>> map, Point start, Point end)
{
	//���Ǹ� ���� using ����
	using namespace std;
	using NodePtr = shared_ptr<Node>;

	//���� ��ǥ ����
	int x_limit = map.size(), y_limit = map[0].size();

	//���� ������ ����
	m_close_list = map;

	//���� ����Ʈ ����
	priority_queue<NodePtr> open_list;

	//�ӽ� ��� ����(���� ��� ����)
	NodePtr node = make_shared<Node>();

	//����� ��ǥ ����
	node.get()->m_point = start;
	
	//����� �ڽ�Ʈ ����
	node.get()->Set_Cost(0, pfh::Heuristic(start, end));

	//���۳�� Push
	open_list.push(node);

	//�ӽ���ǥ
	Point next_point;

	//���� ����� ���� ������ �ݺ�
	while (!open_list.empty())
	{
		//�ڽ�Ʈ�� ���� ���� ���� ����.
		node = open_list.top();
		open_list.pop();

		//���� ��Ͽ� �߰�.
		m_close_list[node.get()->m_point.m_x][node.get()->m_point.m_y] = 1;

		//���������� �����ϸ� true�� ��ȯ
		if (node.get()->m_point == end)
		{
			return true;
		}

		//���� ��ǥ�� �ڽ�Ʈ�� ����ؼ�
		//�켱���� ť�� �ֱ�
		for (int i = 0; i < 4; i++)
		{
			next_point = node.get()->m_point + pfh::str_dir[i];

			//���� ������ ������� �Ǵ�
			//�̵��Ϸ��� �ϴ� ���� ������ �Ǵ�
			//���� �˻��ߴ� ������ �Ǵ�
			if (pfh::Check_Limit(x_limit, y_limit, next_point) &&
				pfh::Check_Road(map, next_point) &&
				!m_close_list[next_point.m_x][next_point.m_y])
			{
				//���� ��带 ����
				NodePtr next_node = make_shared<Node>();
				//���� ����� ��ǥ�� �ʱ�ȭ
				next_node.get()->m_point = next_point;
				//���� ����� �θ� ��带 �ʱ�ȭ
				next_node.get()->m_parent_node = node.get();
				//���� ����� ����ġ�� �ʱ�ȭ
				next_node.get()->Set_Cost(node.get()->m_g_cost + 1, pfh::Heuristic(next_point, end));
				//���� ��Ͽ� �߰�
				open_list.push(next_node);
			}
		}
	}

	return false;
}