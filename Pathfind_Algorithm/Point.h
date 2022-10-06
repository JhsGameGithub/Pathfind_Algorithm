#pragma once

//좌표 구조체
struct Point
{
	Point() : m_x(0), m_y(0) {}
	Point(int a_x, int a_y) :m_x(a_x), m_y(a_y) {}
	int m_x, m_y;

	//연산자 오버로딩
	//좌표가 같은지 판단
	bool operator==(const Point& rhs) const
	{
		return (m_x == rhs.m_x) && (m_y == rhs.m_y);
	}
	Point operator+(const Point& rhs)
	{
		return Point(m_x + rhs.m_x, m_y + rhs.m_y);
	}
};