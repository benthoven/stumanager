#pragma once
#include<iostream>

#define mainsubjectnum 5//主修科目 五个
#define assitantsubnum 4//辅修科目 四个

class stubase
{
public:
	//stubase(int id, std::string name, bool sex,int age,std::string address,std::string mainsubject);//构造函数
	void inputinformation(int n);//输入信息
	void showinformation();//显示基本信息
	void save(std::string);//保存信息
	void read(std::string);//读取信息
private:
	int s_id;//学号
    std::string s_name;//姓名
	std::string s_sex;//性别 0女 1 男
	int s_age;//年龄
	std::string s_address;//家庭住址
	std::string s_mainsubject;//主修专业
	
};

class mainsubject:public stubase//主修科目
{
public:
	void inputscore();//录入成绩
	void showscore();//显示成绩
	int getscore(int a);//获取单科成绩
	void save(std::string a);//保存信息
	void read(std::string a);//读取信息
	bool isstandard();//判断是否全部达到合格标准(三门课达到85)
	bool isresit();//判断是否挂科

private:
	int s_mainscore[7] = {0};//主修科目分数
};

class assitantsubject:public stubase
{
public:
	void setassub();//设置辅修专业名称
	void inputasssubscore();//输入辅修专业成绩
	bool istesit();//判断是否挂科
	int getscore(int b);//获取某一门课程成绩
	void showscore();//显示所有辅修课程成绩
	void save(std::string);//保存信息
	void read(std::string);//读取信息
private:
	std::string assitantsub;//辅修专业
	int s_assitantscore[5] = {0};//辅修科目成绩

};