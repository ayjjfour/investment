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
	double						m_debet;				// 负债
	double						m_used;					// 可用资金
	double						m_total_money;			// 总投资
	unsigned int				m_total_unit;			// 总单数
	double						m_ret_debet;			// 还债金额
	unsigned int				m_ret_cycle;			// 还债周期
	unsigned int				m_ret_start;			// 开始还债周期
	bool						m_b_ret_debet;			// 是否偿还负责

	unsigned int				m_add_unit;				// 追加单数
	unsigned int				m_add_cycle;			// 追加间隔周期
	bool						m_b_reinv;				// 是否复投
	list<project_unit*>			m_list_project;

public:
	///<summary>释放资源</summary>
	void release(void);

	///<summary>设置负债</summary>
	///<param name="debet">新增负债（如果为负数，表示还债）</param>
	///<return>总债务</return>
	///<remark>如果债务还清了，多出来的部分增加到资产中</remark>
	double add_debet(double debet);

	///<summary>设置初始金额</summary>
	///<param name="money">增加的金额</param>
	void add_money(double money, bool isdebet = false);

	///<summary>运行若干周期</summary>
	///<param name="cycles">周期数</param>
	void run_circles(unsigned int cycles = 1);

	///<summary>设置还债金额和还债周期</summary>
	///<param name="money">还债金额</param>
	///<param name="cycles">还债周期</param>
	///<param name="start">开始还债的周期</param>
	void set_ret_debet(double money, unsigned int cycles, unsigned int start);

	///<summary>设置复投参数</summary>
	///<param name="unit">每次追加单数</param>
	///<param name="cycles">每次追加间隔周期数</param>
	///<param name="reivn">获利是否复投</param>
	void set_reinvest(unsigned int unit, unsigned int cycles, bool reinv);
protected:
	///<summary>释放资源</summary>
	void _release(void);

	///<summary>追加投单</summary>
	///<param name="unit">追加单数</param>
	void _add_unit(unsigned int unit);

	///<summary>归还债务</summary>
	void _ret_debet(void);

	///<summary>创建一个项目单元</summary>
	///<param name="isdebet">是否考虑债务</param>
	///<return>true:添加成功,false:添加失败</return>
	bool _create_project_unit(bool isdebet = false);

	///<summary>添加一个项目单元</summary>
	///<return>true:添加成功,false:添加失败</return>
	bool _add_project_unit(project_unit* punit);
};

