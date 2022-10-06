#include <memory>
#include <queue>

#include "AStar.h"
#include "Point.h"
#include "Node.h"
#include "PathfindHelper.h"


//0 == 길
//1 == 벽
//길찾기 알고리즘.
//목적지를 찾으면 true를 반환
bool AStar::Pathfind(std::vector<std::vector<bool>> map, Point start, Point end)
{
	//편의를 위한 using 선언
	using namespace std;
	using NodePtr = shared_ptr<Node>;

	//맵의 좌표 제한
	int x_limit = map.size(), y_limit = map[0].size();

	//맵의 정보를 복사
	m_close_list = map;

	//오픈 리스트 선언
	priority_queue<NodePtr> open_list;

	//임시 노드 선언(시작 노드 지정)
	NodePtr node = make_shared<Node>();

	//노드의 좌표 지정
	node.get()->m_point = start;
	
	//노드의 코스트 지정
	node.get()->Set_Cost(0, pfh::Heuristic(start, end));

	//시작노드 Push
	open_list.push(node);

	//임시좌표
	Point next_point;

	//열린 목록이 없을 때까지 반복
	while (!open_list.empty())
	{
		//코스트가 가장 낮은 것을 뺀다.
		node = open_list.top();
		open_list.pop();

		//닫힌 목록에 추가.
		m_close_list[node.get()->m_point.m_x][node.get()->m_point.m_y] = 1;

		//도착지점에 도달하면 true를 반환
		if (node.get()->m_point == end)
		{
			return true;
		}

		//다음 좌표의 코스트를 계산해서
		//우선순위 큐에 넣기
		for (int i = 0; i < 4; i++)
		{
			next_point = node.get()->m_point + pfh::str_dir[i];

			//맵의 영역을 벗어나는지 판단
			//이동하려고 하는 곳이 길인지 판단
			//전에 검사했던 길인지 판단
			if (pfh::Check_Limit(x_limit, y_limit, next_point) &&
				pfh::Check_Road(map, next_point) &&
				!m_close_list[next_point.m_x][next_point.m_y])
			{
				//다음 노드를 생성
				NodePtr next_node = make_shared<Node>();
				//다음 노드의 좌표를 초기화
				next_node.get()->m_point = next_point;
				//다음 노드의 부모 노드를 초기화
				next_node.get()->m_parent_node = node.get();
				//다음 노드의 가중치를 초기화
				next_node.get()->Set_Cost(node.get()->m_g_cost + 1, pfh::Heuristic(next_point, end));
				//열린 목록에 추가
				open_list.push(next_node);
			}
		}
	}

	return false;
}