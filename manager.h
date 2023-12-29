#pragma once
#include"abstract.h"
#include<fstream>

class manager :public abstract
{
public:
	void showmenu();//菜单

	void addstu();//添加学生

	void changestuinf();//修改学生信息

	void delstu();//删除学生信息
	
	//查看学生列表
	 void showstudentlist();

	//查看指定学生信息
	 void showstuinf();

	//更改密码
	 void setownpass();
};