#include "StdAfx.h"
#include "project_manager.h"

project_manager::project_manager(void)
{
	m_ret_cycle = 4;
	m_ret_debet = 20000;
	m_b_ret_debet = false;
	m_total_money = 0;
	m_total_unit = 0;
	m_debet = 0;
	m_used = 0;

	m_add_unit = 0;
	m_add_cycle = 0;
	m_b_reinv = false;
	m_list_project.clear();
}

project_manager::~project_manager(void)
{
	_release();
}

void project_manager::release(void)
{
	_release();
}

double project_manager::add_debet(double debet)
{
	m_debet += debet;
	if (m_debet < 0)
	{
		m_used -= m_debet;
		m_debet = 0;
	}

	return m_debet;
}

void project_manager::add_money(double money, bool isdebet)
{
	m_used += money;
	_create_project_unit();

	if (isdebet)
		m_debet += money;
}

bool project_manager::_create_project_unit(bool isdebet)
{
	static int times = 0;
	double rate = 0.0f;
	unsigned int i = 0;
	double debet = 0.0f;

	if (isdebet)
		debet = m_ret_debet;

	while (m_used - debet>= g_capital)
	{
		pro_sjhy*	pro = new pro_sjhy;
		if (nullptr == pro)
			return false;

		m_total_money += g_capital;
		m_total_unit++;
		_add_project_unit(pro);
		m_used -= g_capital;
		i++;
	}

	if (m_total_money < 300000)
		rate = 0.08;
	else
		rate = 0.1;

	if (times != 0)
		m_used += (g_capital * rate * i);
	else
		times = 1;
	
	return true;
}

bool project_manager::_add_project_unit(project_unit* punit)
{
	m_list_project.push_back(punit);
	return true;
}

void project_manager::_release(void)
{
	list<project_unit*>::iterator		it;

	for (it = m_list_project.begin(); it != m_list_project.end(); it++)
	{
		if (nullptr != (*it))
			delete (*it);
	}

	m_list_project.clear();

	m_used = 0;
}

void project_manager::_add_unit(unsigned int unit)
{
	double rate = 0.0f;

	for (unsigned int i = 0; i < unit; i++)
	{
		pro_sjhy*	pro = new pro_sjhy;
		if (nullptr == pro)
			return;

		m_total_money += g_capital;
		m_total_unit++;
		_add_project_unit(pro);
	}

	if (m_total_money < 300000)
		rate = 0.08;
	else
		rate = 0.1;

	m_used += (g_capital * rate * unit);
}

void project_manager::_ret_debet(void)
{
	double	ret_debet;
	if (m_debet <= 0)
		return;

	if (m_used > m_ret_debet)
	{
		m_used -= m_ret_debet;
		ret_debet = m_ret_debet;
	}
	else
	{
		ret_debet = m_used;
		m_used = 0;
	}

	add_debet(-ret_debet);
}

void project_manager::set_ret_debet(double money, unsigned int cycles, unsigned int start)
{
	m_ret_debet = money;
	m_ret_cycle = cycles;
	m_ret_start = start;
}

void project_manager::set_reinvest(unsigned int unit, unsigned int cycles, bool reinv)
{
	m_add_unit = unit;
	m_add_cycle = cycles;
	m_b_reinv = reinv;
}

void project_manager::run_circles(unsigned int cycles)
{
	static unsigned long long			runs = 0;
	list<project_unit*>::iterator		it;

	while(cycles-- > 0)
	{
		for (it = m_list_project.begin(); it != m_list_project.end(); it++)
		{
			if (nullptr != (*it))
				(*it)->vir_run_circles(1);
		}

		double pre_insterest = 0;
		for (it = m_list_project.begin(); it != m_list_project.end(); )
		{
			if (nullptr == (*it))
			{
				m_list_project.erase(it++);
				continue;
			}

			m_used += (*it)->vir_get_interest();
			pre_insterest += (*it)->vir_get_left_interest();

			if ((*it)->vir_is_over())
			{
				m_list_project.erase(it++);
				continue;
			}

			it++;
		}

		runs ++;

		if (runs > m_ret_start)
			m_b_ret_debet = true;

		if (m_b_ret_debet && ((runs - m_ret_start) % m_ret_cycle == 0))
			_ret_debet();
		
		printf("run(%03lld): units=%d, used=%.0f insterest=%.0f debet=%.0f all=%.3f\n", 
					runs, m_total_unit, m_used, pre_insterest, m_debet, (m_used + pre_insterest - m_debet) / 10000);

		if (runs % m_add_cycle == 0)
		{
			printf("\n");
			_add_unit(m_add_unit);
		}

		if (m_b_reinv)
			_create_project_unit(m_b_ret_debet);
	}
}