#pragma once
#include<iostream>
#include<fstream>
#include<string>
#define MAX_INDEX 200


class index
{
public:
	index();//构造函数
	void recreatindex();//重建索引
	int searchbyid(int _id);//按学号检索，返回索引位置
	int searchbyname(std::string _name);//按姓名检索，返回索引位置
	int selectbytype();//按类型筛选
	void showindex();//显示索引
	void showonlyinf(int n);//显示单个学生信息
	int getid(int n);//获取学号
	int getpos();//获取有效容量

private:
	int id[MAX_INDEX] ;//学号
	std::string name[MAX_INDEX];//姓名
};
