#pragma once
#include"abstract.h"

class mainteacher :public abstract
{
public:
	void showmenu();

	void setstuscore();//录入学生成绩

	void showpriorstu();//查看成绩优秀的同学

	void showinfiorstu();//查看需要补考的同学

	
	//查看学生列表
	 void showstudentlist();

	//查看学生信息和主修科目分数
	 void showstuinf() ;

	//更改密码
	 void setownpass();

	
};