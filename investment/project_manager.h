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
	double						m_debet;				// ��ծ
	double						m_used;					// �����ʽ�
	double						m_total_money;			// ��Ͷ��
	unsigned int				m_total_unit;			// �ܵ���
	double						m_ret_debet;			// ��ծ���
	unsigned int				m_ret_cycle;			// ��ծ����
	unsigned int				m_ret_start;			// ��ʼ��ծ����
	bool						m_b_ret_debet;			// �Ƿ񳥻�����

	unsigned int				m_add_unit;				// ׷�ӵ���
	unsigned int				m_add_cycle;			// ׷�Ӽ������
	bool						m_b_reinv;				// �Ƿ�Ͷ
	list<project_unit*>			m_list_project;

public:
	///<summary>�ͷ���Դ</summary>
	void release(void);

	///<summary>���ø�ծ</summary>
	///<param name="debet">������ծ�����Ϊ��������ʾ��ծ��</param>
	///<return>��ծ��</return>
	///<remark>���ծ�����ˣ�������Ĳ������ӵ��ʲ���</remark>
	double add_debet(double debet);

	///<summary>���ó�ʼ���</summary>
	///<param name="money">���ӵĽ��</param>
	void add_money(double money, bool isdebet = false);

	///<summary>������������</summary>
	///<param name="cycles">������</param>
	void run_circles(unsigned int cycles = 1);

	///<summary>���û�ծ���ͻ�ծ����</summary>
	///<param name="money">��ծ���</param>
	///<param name="cycles">��ծ����</param>
	///<param name="start">��ʼ��ծ������</param>
	void set_ret_debet(double money, unsigned int cycles, unsigned int start);

	///<summary>���ø�Ͷ����</summary>
	///<param name="unit">ÿ��׷�ӵ���</param>
	///<param name="cycles">ÿ��׷�Ӽ��������</param>
	///<param name="reivn">�����Ƿ�Ͷ</param>
	void set_reinvest(unsigned int unit, unsigned int cycles, bool reinv);
protected:
	///<summary>�ͷ���Դ</summary>
	void _release(void);

	///<summary>׷��Ͷ��</summary>
	///<param name="unit">׷�ӵ���</param>
	void _add_unit(unsigned int unit);

	///<summary>�黹ծ��</summary>
	void _ret_debet(void);

	///<summary>����һ����Ŀ��Ԫ</summary>
	///<param name="isdebet">�Ƿ���ծ��</param>
	///<return>true:��ӳɹ�,false:���ʧ��</return>
	bool _create_project_unit(bool isdebet = false);

	///<summary>���һ����Ŀ��Ԫ</summary>
	///<return>true:��ӳɹ�,false:���ʧ��</return>
	bool _add_project_unit(project_unit* punit);
};

