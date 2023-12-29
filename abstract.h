#pragma once
#include<iostream>

class abstract 
{
public:
	virtual void showmenu()=0;//内容不同，需要重写
	//查看学生列表
	virtual void showstudentlist()=0;
	//查看学生信息
	virtual void showstuinf()=0;
	//更改密码
	virtual void setownpass()=0;
	
private:
	std::string account;//账号
	int password;//密码
};