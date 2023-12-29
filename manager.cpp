#include"manager.h"
#include"index.h"
#include"stubase.h"
#include<fstream>
#include"globalfile.h"

void manager::showmenu() //内容不同，需要重写
{
	std::cout << "*****欢迎进入教务管理员页面*****" << std::endl;
	std::cout << "\t***请选择功能***\t" << std::endl;
	std::cout << "\t0.查看学生列表\t" << std::endl;
	std::cout << "\t1.查看学生信息\t" << std::endl;
	std::cout << "\t2.修改学生信息\t" << std::endl;
	std::cout << "\t3.删除学生信息\t" << std::endl;
	std::cout << "\t4.更改密码\t" << std::endl;
	std::cout << "\t5.退出系统\t" << std::endl;
}

void manager::addstu()//添加学生
{
	index in;
	int pos = in.getpos();
	std::cout << "请按要求输入以下信息" << std::endl;
	std::ofstream ofs;
	for (int i = pos; i <= MAX_INDEX; i++)
	{
		ofs.open("student" + std::to_string(i) + ".txt", std::ios::out);
		if (ofs.is_open())
		{
			int id;
			std::string name;
			std::string sex;
			int age;
			std::string address;
			std::string subject;
			std::cout << "请输入学号(数字)" << std::endl;
			std::cin >> id;
			std::cout << "请输入姓名" << std::endl;
			std::cin >> name;
			std::cout << "请输入性别(男/女)" << std::endl;
			std::cin >> sex;
			std::cout << "请输入年龄" << std::endl;
			std::cin >> age;
			std::cout << "请输入家庭住址" << std::endl;
			std::cin >> address;
			std::cout << "请输入主修专业" << std::endl;
			std::cin >> subject;
			//写入
			ofs << id << "  " << name << "  " << sex << "  " << age << "  "  << address << "  " << subject << "  " << std::endl;
			std::cout << "添加学生信息成功" << std::endl;
			ofs.close();
			std::cout << "是否继续添加学生信息(0.是  1.否)" << std::endl;
			int choice;
			std::cin >> choice;
			if (choice)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		else
		{
			std::cout << "文件打开失败" << std::endl;
			return;
		}
		
	}
}
//查看学生列表
void manager::showstudentlist()
{
	index in;
	in.showindex();
}
//查看指定学生信息
void manager::showstuinf()
{
	index in;
	stubase stu;
	int n=in.selectbytype();
	if (n == -1)
	{
		std::cout << "此信息不存在" << std::endl;
		return;
	}
	stu.read(std::to_string(n));
	stu.showinformation();

}

void manager::setownpass()//更改密码
{
	std::ifstream ifs;
	ifs.open(MANAGER, std::ios::in);
	std::string readaccount;//准备接收
	int readpassword;
	if (ifs.is_open())
	{
		ifs >> readaccount && ifs >> readpassword;
	}
	else
	{
		std::cout << "open error" << std::endl;
		return;
	}

	std::ofstream ofs;
	ofs.open(MANAGER, std::ios::out | std::ios::trunc);//清除文档，重新写入
	if (ofs.is_open())
	{
		std::cout << "请输入您的新密码(三位数字)" << std::endl;
		std::cin >> readpassword;
		ofs << readaccount << "  " << readpassword << std::endl;;
		std::cout << "密码修改成功！" << std::endl;
	}
	else
	{
		std::cout << "open error" << std::endl;
		return;
	}
}

void manager::changestuinf()//修改学生信息
{
	index in;
	std::cout << "你正在修改学生信息···" << std::endl;
	int n = in.selectbytype();
	stubase stu;
	stu.read(std::to_string(n));
	std::cout << "请重新输入该学生的基本信息" << std::endl;
	stu.inputinformation(n);
	stu.save(std::to_string(n));
	in.recreatindex();//重新初始化数据索引
}

void manager::delstu()//删除学生信息
{
	index in;
	std::cout << "你正在删除学生信息···" << std::endl;
	int n = in.selectbytype();
	std::ofstream ofs;
	ofs.open("student" + std::to_string(n) + ".txt",std::ios::out|std::ios::trunc);
	if (ofs.is_open())
	{
		ofs << 0 << " " << "NULL" << std::endl;
		std::cout << "删除成功" << std::endl;
		in.recreatindex();//重建索引
	}
	ofs.close();
}