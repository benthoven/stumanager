#include<iostream>
#include"index.h"
#include"abstract.h"
#include"manager.h"
#include"systemmanager.h"
#include"mainteacher.h"
#include"assitantteacher.h"


int main()
{
	systemmanager sm;//创建管理类对象
	sm.showmenu();//显示登录菜单
	sm.login();//登录函数
	

	system("pause");
	return 0;
}