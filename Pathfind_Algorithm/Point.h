#pragma once

//��ǥ ����ü
struct Point
{
	Point() : m_x(0), m_y(0) {}
	Point(int a_x, int a_y) :m_x(a_x), m_y(a_y) {}
	int m_x, m_y;

	//������ �����ε�
	//��ǥ�� ������ �Ǵ�
	bool operator==(const Point& rhs) const
	{
		return (m_x == rhs.m_x) && (m_y == rhs.m_y);
	}
	Point operator+(const Point& rhs)
	{
		return Point(m_x + rhs.m_x, m_y + rhs.m_y);
	}
};