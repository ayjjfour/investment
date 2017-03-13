#pragma once
#include "project_unit.h"

const int		g_capital = 7200;
const int		g_pre_interest = 10000;

const int		g_circle = 32;				// �ɻ���ҵ��Ŀ������
const int		g_capital_circle = 24;		// ���ر�������� 

class pro_sjhy :
	public project_unit
{
public:
	pro_sjhy(void);
	~pro_sjhy(void);

public:
	bool		vir_is_over(void);
	double		vir_get_interest(void);

protected:
	void		_vir_run_one_circle(void);
};

