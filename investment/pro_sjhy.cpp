#include "StdAfx.h"
#include "pro_sjhy.h"

pro_sjhy::pro_sjhy(void)
{
	m_circle			= g_circle;
	m_capital			= g_capital;
	m_pre_interest		= g_pre_interest;
	m_left_interest		= g_pre_interest;
}

pro_sjhy::~pro_sjhy(void)
{
}

bool pro_sjhy::vir_is_over(void)
{
	return (m_cur_circle >= m_circle);
}

double pro_sjhy::vir_get_interest(void)
{
	double interest = m_interest;

	m_left_interest -= m_interest;
	m_interest = 0;

	return interest;
}

void pro_sjhy::_vir_run_one_circle(void)
{
	m_cur_circle++;

	if (m_cur_circle < g_capital_circle)
		m_interest += 300;
	else
		m_interest += 350;
}