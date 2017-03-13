#pragma once
class project_unit
{
public:
	project_unit(void);
	virtual ~project_unit(void);

protected:
	// ��ʼ�����������ʼ���Ժ󣬾Ͳ��ٱ仯������
	double					m_capital;			// ����
	unsigned int			m_circle;			// ������
	bool					m_capital_return;	// �����Ƿ񷵻�
	double					m_pre_interest;		// Ԥ������

	// ���ڱ���������Ŀ���ڱ仯���仯������
	unsigned int			m_cur_circle;		// ��ǰ����
	double					m_interest;			// ӯ��
	double					m_left_interest;	// ʣ���ʽ�

public:
	///<summary>��ʼ����Ŀ</summary>
	virtual void		vir_instance(void);

	///<summary>�ж���Ŀ�Ƿ����</summary>
	///<return>true:��Ŀ������false:��Ŀδ����</return>
	virtual bool		vir_is_over(void) = 0;

	///<summary>��Ŀ�������ɸ�����</summary>
	///<param name="circles">����������(Ĭ����1������)</param>
	virtual void		vir_run_circles(unsigned int circles = 1);

	///<summary>��ȡ��Ŀ��ǰ����</summary>
	///<return>��Ŀ����</return>
	virtual double		vir_get_interest(void);

	///<summary>��ȡ��ĿԤ������</summary>
	///<return>��ĿԤ������</return>
	virtual double		vir_get_pre_interest(void);

	///<summary>��ȡ��ĿԤ��ʣ������</summary>
	///<return>��ĿԤ��ʣ������</return>
	virtual double		vir_get_left_interest(void);

protected:
	///<summary>��Ŀ����һ������</summary>
	virtual void		_vir_run_one_circle(void) = 0;
};

