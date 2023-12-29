#pragma once

#include<iostream>
#include<fstream>
#include"globalfile.h"
#include"abstract.h"

class systemmanager
{
public:
	
	void showmenu();//功能菜单
	void login();//登录功能
	void check(std::string filename,int type);//账号检查
	void managerfunction(abstract*& ab);//教务管理员功能接口//指针的引用
	void mainteafunction(abstract*& ab);//主修教师功能接口
	void assitantteafunction(abstract*& ab);//辅修教师功能接口
};
