#pragma once

#include "pro_sjhy.h"

#include <list>

using namespace std;

class project_manager
{
public:
	project_manager(void);
	virtual ~project_manager(void);

protected:
	double						m_total_money;
	list<project_unit*>			m_list_project;

public:
	///<summary>�ͷ���Դ</summary>
	void release(void);

	///<summary>���ó�ʼ���</summary>
	///<param name="money">���ӵĽ��</param>
	void add_money(double money);

	///<summary>������������</summary>
	///<param name="cycles">������</param>
	void run_circles(unsigned int cycles = 1);
protected:
	///<summary>�ͷ���Դ</summary>
	void _release(void);

	///<summary>����һ����Ŀ��Ԫ</summary>
	///<return>true:��ӳɹ�,false:���ʧ��</return>
	bool _create_project_unit(void);

	///<summary>���һ����Ŀ��Ԫ</summary>
	///<return>true:��ӳɹ�,false:���ʧ��</return>
	bool _add_project_unit(project_unit* punit);
};

