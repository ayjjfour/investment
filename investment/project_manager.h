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
	///<summary>释放资源</summary>
	void release(void);

	///<summary>设置初始金额</summary>
	///<param name="money">增加的金额</param>
	void add_money(double money);

	///<summary>运行若干周期</summary>
	///<param name="cycles">周期数</param>
	void run_circles(unsigned int cycles = 1);
protected:
	///<summary>释放资源</summary>
	void _release(void);

	///<summary>创建一个项目单元</summary>
	///<return>true:添加成功,false:添加失败</return>
	bool _create_project_unit(void);

	///<summary>添加一个项目单元</summary>
	///<return>true:添加成功,false:添加失败</return>
	bool _add_project_unit(project_unit* punit);
};

