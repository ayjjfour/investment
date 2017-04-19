// investment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "project_manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	project_manager		mg;

	/*
	mg.add_money(g_capital * 10);
	mg.run_circles(1);
	mg.add_money(g_capital * 10);
	mg.run_circles(52 * 0.5);
	*/

	mg.add_money(g_capital * 22, false);
	mg.add_money(g_capital * 18, true);
	mg.set_ret_debet(20000, 4, 4);
	mg.set_reinvest(1, 4, true);
	//mg.add_debet(g_capital * 24);
	mg.run_circles(52 * 2);

	return 0;
}