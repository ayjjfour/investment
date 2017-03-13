#include "StdAfx.h"
#include "project_manager.h"

project_manager::project_manager(void)
{
	m_total_money = 0;
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

void project_manager::add_money(double money)
{
	m_total_money += money;
	_create_project_unit();
}

///<summary>创建一个项目单元</summary>
///<return>true:添加成功,false:添加失败</return>
bool project_manager::_create_project_unit(void)
{
	static int times = 0;
	unsigned int i = 0;
	while (m_total_money >= g_capital)
	{
		pro_sjhy*	pro = new pro_sjhy;
		if (nullptr == pro)
			return false;

		_add_project_unit(pro);
		m_total_money -= g_capital;
		i++;
	}

	if (times != 0)
		m_total_money += (g_capital * 0.08 * i);
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

	m_total_money = 0;
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
		for (it = m_list_project.begin(); it != m_list_project.end(); it++)
		{
			if (nullptr == (*it))
			{
				m_list_project.erase(it++);
				continue;
			}

			m_total_money += (*it)->vir_get_interest();
			pre_insterest += (*it)->vir_get_left_interest();

			if ((*it)->vir_is_over())
			{
				m_list_project.erase(it++);
			}
		}

		printf("this is run(%03lld): unit=%03d total_money=%10.0f pre_insterest = %10.0f\n", ++runs, m_list_project.size(), m_total_money, pre_insterest);
		_create_project_unit();
		//if (runs % 4 == 0)
			//add_money(g_capital * 1);
	}
}