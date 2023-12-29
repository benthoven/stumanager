#include"index.h"

index::index()//初始化索引
{
	recreatindex();
}
void index::recreatindex()//建立索引
{
	std::ofstream ofs;//写入
	std::ifstream ifs;//读出
	ofs.open("index.txt", std::ios::out);//写的方式打开
	for (int i = 0; i < MAX_INDEX; i++)//将学生基本信息读取到数组中，再写入到索引文件中
	{
		ifs.open("student" + std::to_string(i) + ".txt", std::ios::in);//to_string数字转字符  打开对应学生文件
		if (ifs.is_open())
		{
			ifs >> id[i] >> name[i];
			ifs.close();
			ofs << "id " << id[i] << "name " << name[i] << std::endl;
		}
		else
		{
			id[i] = 0;
			name[i] = "NULL";
			//std::cout << "creat中文件打开失败" << std::endl;
			ifs.close();
		}
	}
	ofs.close();
}
int index::searchbyid(int _id)//按学号检索，返回索引位置//即检索数组
{
	for (int i=0; i < MAX_INDEX; i++)//检索数组
	{
		if (id[i] == _id)
		{
			return i;
		}
	}
	std::cout << "索引失败" << std::endl;
	return -1;
}
int index::searchbyname(std::string _name)//按姓名检索，返回索引位置
{
	for (int i = 0; i < MAX_INDEX; i++)//检索数组
	{
		if (name[i] == _name)
		{
			return i;
		}
	}
	std::cout << "索引失败" << std::endl;
	return -1;
}
int index::selectbytype()//按类型筛选
{
	std::cout << "请输入要查找学生的学号或者姓名" << std::endl;
	int ret=0;
	int num;
	std::string name;
	if (!(std::cin >> num))//姓名
	{
		std::cin.clear();//清除错误,继续输入
		std::cin.sync();//清除缓存
		std::cin >> name;
		ret = searchbyname(name);
		if (ret == -1)
		{
			std::cout << "姓名查找失败" << std::endl;
		}
		else
		{
			std::cout << "姓名查找成功" << std::endl;
			return ret;
		}
	}
	else//id查找
	{
		ret= searchbyid(num);
		if (ret == -1)
		{
			std::cout << "学号查找失败" << std::endl;
		}
		else
		{
			std::cout << "学号查找成功" << std::endl;
			return ret;
		}
	}
}
void index::showindex()//显示索引
{
	int nums = 0;
	for (int i = 0; i <MAX_INDEX; i++)
	{
		if (id[i] == 0)continue;//排除空位置
		std::cout << "\t学号：" << id[i] << "\t姓名：" << name[i] << std::endl;
		nums++;
	}
	std::cout << "共有" << nums << "名学生" << std::endl;
}
void index::showonlyinf(int n)//显示单个学生信息
{
	std::cout << "\t学号：" << id[n] << " \t姓名：" << name[n] << std::endl;
}
int index::getid(int n)//获取学号
{
	return id[n];
}
int index::getpos()//获取有效容量
{
	int pos = 0;
	for (int i = 1; i < MAX_INDEX; i++)
	{
		pos = i;
		if (id[pos] == 0 && id[pos+ 1] == 0)return pos;
	}
}