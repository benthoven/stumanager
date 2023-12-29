#include"stubase.h"
#include<fstream>

void stubase::inputinformation(int n)//输入信息
{
	if (n == 0)
	{
		std::cout << "请输入该生的学号：" <<std::endl;
		std::cin>>s_id;
	}
	else
	{
		s_id = n;//没有直接创建
	}
	std::cout << "请输入该生的姓名：" << std::endl;
	std::cin >> s_name;
	std::cout << "请输入该生的性别（0表示男，1表示女）：" << std::endl;
	std::cin>>s_sex;
	std::cout << "请输入该生的年龄：" << std::endl;
	std::cin>>s_age;
	std::cout << "请输入该生的地址：" << std::endl;
	std::cin >> s_address;
	std::cout << "请输入该生的主修专业：" << std::endl;
	std::cin >> s_mainsubject;
	std::cout << "学生" << s_name << "的基本信息录入完成\n";

		
}
void stubase::showinformation()//显示基本信息
{
	if (s_id == 0)
	{
		std::cout << "信息尚未录入！" << std::endl;
	}
	else
	{
		std::cout << " 学号：" << s_id << " 姓名：" << s_name << " 性别："<<s_sex 
			<< " 年龄：" <<s_age << " 地址：" << s_address << " 主修专业：" << s_mainsubject << std::endl;
	}
	
}
void stubase::save(std::string a)//保存信息
{
	std::ofstream outfile;
	outfile.open("student" + a + ".txt", std::ios::out );
	outfile << s_id <<"  "<< s_name <<"  " << s_sex<<"  " << s_age<<"  " << s_address<<"  " << s_mainsubject<<"  " << std::endl;
	outfile.close();
	
}
void stubase::read(std::string a)//读取信息
{
	std::ifstream ifs;
	ifs.open("student" + a + ".txt", std::ios::in );
	if (ifs.is_open())
	{
		ifs >> s_id >> s_name >> s_sex>> s_age >> s_address >> s_mainsubject ;
	}
	else
	{
		std::cout << "error" << std::endl;
		return;
	}
	
	ifs.close();
}

void mainsubject::inputscore()//录入成绩
{
	for (int i = 0; i < mainsubjectnum; i++)
	{
		std::cout << "请输入该生主修课程第" << i + 1 << "门科目的分数" << std::endl;
		std::cin >> s_mainscore[i];

	}
	std::cout << "该生全部课程成绩录入完毕" << std::endl;
}
void mainsubject::showscore()//显示主修成绩
{
	std::cout << "主修课程分数如下" << std::endl;
	for (int i = 0; i < mainsubjectnum; i++)
	{
		std::cout << s_mainscore[i] << "\t";
	}
	std::cout << std::endl;
}
int mainsubject::getscore(int a)//获取单科成绩
{
	if (a > 5)
	{
		std::cout << "输入错误，请减小输入量" << std::endl;
	}
	return s_mainscore[a];
}
void mainsubject::save(std::string a)//保存信息
{
	std::ofstream ofs;
	ofs.open("major" + a + ".txt", std::ios::out);
	if (ofs.is_open())
	{
		for (int i = 0; i < mainsubjectnum; i++)
		{
			ofs << getscore(i) << " ";//存入文件
		}
		ofs.close();
	}
	else
	{
		std::cout << "open file is failed" << std::endl;
	}
}
void mainsubject::read(std::string a)//读取信息
{
	std::ifstream ifs;
	ifs.open("major" + a + ".txt", std::ios::in);
	if (ifs.is_open())
	{
		for (int i = 0; i < mainsubjectnum; i++)
		{
			ifs >> s_mainscore[i] ;//读入数组
		}
	ifs.close();
	}
	else
	{
		std::cout << "文件读取失败" << std::endl;
		return;
	}
}
bool mainsubject::isstandard()//判断是否全部达到合格标准(三门课达到85)
{
	int m = 0;
	for (int i = 0; i < mainsubjectnum; i++)
	{
		if (s_mainscore[i] >= 85)
		{
			m++;
		}
	}
	if (m >= 3) return true;
	return false;
} 
bool mainsubject::isresit()//判断是否挂科
{
	for (int i = 0; i < mainsubjectnum; i++)
	{
		if (s_mainscore[i]!=0&& s_mainscore[i] < 60)return true;
	}
	return false;
}

void assitantsubject::setassub()//设置辅修专业名称
{
	std::cout << "请输入该生辅修专业名称" << std::endl;
	std::cin >> assitantsub;
}
void assitantsubject::inputasssubscore()//输入辅修专业成绩
{
	if (assitantsub == " ")
	{
		std::cout << "请先选择该生的辅修专业" << std::endl;
		return;
	}
	for (int i = 0; i < assitantsubnum; i++)
	{
		std::cout << "请输入该生辅修课程第" << i + 1 << "门科目的分数" << std::endl;
		std::cin >> s_assitantscore[i];
	}
}
bool assitantsubject::istesit()//判断是否挂科
{
	for (int i = 0; i < assitantsubnum; i++)
	{
		if (10<s_assitantscore[i]&& s_assitantscore[i] < 60)return true;
	}
	return false;
}
void assitantsubject::save(std::string a)//保存信息
{
	std::ofstream ofs;
	ofs.open("assitantsub" + a + ".txt", std::ios::out);
	ofs << assitantsub<<"  ";//先将专业写入
	for (int i = 0; i < assitantsubnum; i++)//再写分数
	{
		ofs << getscore(i) << " " ;//存入文件
	}
	ofs.close();
}
void assitantsubject::read(std::string a)//读取信息
{
	std::ifstream ifs;
	ifs.open("assitantsub" + a + ".txt", std::ios::in);
	ifs >> assitantsub;//先读取专业
	for (int i = 0; i < assitantsubnum; i++)
	{
		ifs >> s_assitantscore[i];//读入数组
	}
	ifs.close();
}
int assitantsubject::getscore(int b)//获取某一门课程成绩
{
	if (b > 4)
	{
		std::cout << "输入错误，请减小输入量" << std::endl;
	}
	return s_assitantscore[b];
}
void assitantsubject::showscore()//显示所有辅修课程成绩
{
	std::cout << "辅修专业：" << assitantsub << std::endl;
	std::cout << "辅修课程分数如下" << std::endl;
	for (int i = 0; i < assitantsubnum; i++)
	{
		std::cout << s_assitantscore[i] << " ";
	}
	std::cout << std::endl;
}