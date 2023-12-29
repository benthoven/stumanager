#pragma once
#include"abstract.h"

class assitanteacher :public abstract
{
public:
	void showmenu();//重写

	void setassitansub();//设置辅修专业及录入辅修成绩

	void showinfriorstu();//查看需要补考的学生
	
	//查看学生列表
	 void showstudentlist();
	//查看学生信息
	 void showstuinf();
	//更改密码
	 void setownpass() ;
	

};