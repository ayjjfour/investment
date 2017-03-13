#pragma once
class project_unit
{
public:
	project_unit(void);
	virtual ~project_unit(void);

protected:
	// 初始变量（对象初始化以后，就不再变化的量）
	double					m_capital;			// 本金
	unsigned int			m_circle;			// 周期数
	bool					m_capital_return;	// 本金是否返还
	double					m_pre_interest;		// 预期收益

	// 周期变量（随项目周期变化而变化的量）
	unsigned int			m_cur_circle;		// 当前周期
	double					m_interest;			// 盈亏
	double					m_left_interest;	// 剩余资金

public:
	///<summary>初始化项目</summary>
	virtual void		vir_instance(void);

	///<summary>判断项目是否结束</summary>
	///<return>true:项目结束，false:项目未结束</return>
	virtual bool		vir_is_over(void) = 0;

	///<summary>项目运行若干个周期</summary>
	///<param name="circles">运行周期数(默认是1个周期)</param>
	virtual void		vir_run_circles(unsigned int circles = 1);

	///<summary>获取项目当前收益</summary>
	///<return>项目收益</return>
	virtual double		vir_get_interest(void);

	///<summary>获取项目预期收益</summary>
	///<return>项目预期收益</return>
	virtual double		vir_get_pre_interest(void);

	///<summary>获取项目预期剩余收益</summary>
	///<return>项目预期剩余收益</return>
	virtual double		vir_get_left_interest(void);

protected:
	///<summary>项目运行一个周期</summary>
	virtual void		_vir_run_one_circle(void) = 0;
};

