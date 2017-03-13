#include "StdAfx.h"
#include "project_unit.h"

///<summary></summary>
///<return></return>
project_unit::project_unit(void)
{
	m_capital = 0;				// ����
	m_circle = 0;				// ������
	m_cur_circle = 0;			// ��ǰ����
	m_interest = 0;				// ӯ��
	m_capital_return = false;	// �����Ƿ񷵻�
	m_pre_interest = 0;			// Ԥ������
}

project_unit::~project_unit(void)
{
	m_capital = 0;				// ����
	m_circle = 0;				// ������
	m_cur_circle = 0;			// ��ǰ����
	m_interest = 0;				// ӯ��
	m_capital_return = false;	// �����Ƿ񷵻�
	m_pre_interest = 0;			// Ԥ������
}

void project_unit::vir_instance(void)
{
	return;
}

void project_unit::vir_run_circles(unsigned int circles)
{
	if (m_cur_circle + circles > m_circle)
		circles = m_circle - m_cur_circle;

	for (unsigned int i = 0; i < circles; i++)
	{
		_vir_run_one_circle();
	}
}

double project_unit::vir_get_interest(void)
{
	return m_interest;
}

double project_unit::vir_get_pre_interest(void)
{
	return m_pre_interest;
}

double project_unit::vir_get_left_interest(void)
{
	return m_left_interest;
}