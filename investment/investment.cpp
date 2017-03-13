// investment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "project_manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	project_manager		mg;

	mg.add_money(g_capital * 50);
	mg.run_circles(52 * 0.5);

	return 0;
}