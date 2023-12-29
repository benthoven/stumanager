#include"mainteacher.h"
#include"index.h"
#include"stubase.h"
#include"globalfile.h"

void mainteacher::showmenu()
{
	std::cout << "*****欢迎进入 主修教师 页面*****" << std::endl;;
	std::cout << "\t***请选择功能***\t" << std::endl;
	std::cout << "\t0.查看学生列表\t" << std::endl;
	std::cout << "\t1.查看学生信息\t" << std::endl;
	std::cout << "\t2.录入主修成绩\t" << std::endl;
	std::cout << "\t3.查看成绩优秀学生\t" << std::endl;
	std::cout << "\t4.查看需要补考学生\t" << std::endl;
	std::cout << "\t5.更改密码\t" << std::endl;
	std::cout << "\t6.退出系统\t" << std::endl;
}

void mainteacher::setstuscore()//录入学生成绩
{
	index in;
	int n = in.selectbytype();//寻找学生编号
	if (n == -1)
	{
		return;//搜索失败
	}
	mainsubject major;
	major.inputscore();//录入成绩到相应数组
	major.save(std::to_string(n));//保存到文件中
}

void mainteacher::showpriorstu()//查看成绩优秀的同学
{
	index in;
	int m = 0;
	for (int i = 0; i < MAX_INDEX; i++)
	{	
		mainsubject major;
		major.read(std::to_string(i));
		if (major.isstandard())
		{
			in.showonlyinf(i);
			major.showscore();
			m++;
		}
		else
		{
			continue;
		}
	}
	if (m == 0)
	{
		std::cout << "没有成绩优秀的学生" << std::endl;
	}
	else
	{
		std::cout << "以上是成绩优秀的学生" << std::endl;
	}
}

void mainteacher::showinfiorstu()//查看需要补考的同学
{
	index in;
	int m = 0;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		mainsubject major;
		major.read(std::to_string(i));
		if (major.isresit())
		{
			in.showonlyinf(i);
			major.showscore();
			m++;
		}
		else
		{
			continue;
		}
	}
	if (m == 0)
	{
		std::cout << "没有需要补考的学生" << std::endl;
	}
	else
	{
		std::cout << "以上是需要补考的学生" << std::endl;
	}
}
//查看学生列表
void mainteacher::showstudentlist()
{
	index in;
	in.showindex();
}
//查看学生信息和主修科目分数
void mainteacher::showstuinf()
{
	index in;
	stubase stu;
	int n = in.selectbytype();
	if (n == -1)
	{
		std::cout << "此信息不存在" << std::endl;
		return;
	}
	stu.read(std::to_string(n));
	stu.showinformation();
	mainsubject major;
	major.read(std::to_string(n));//读取信息
	major.showscore();
	
}
void mainteacher::setownpass()//更改密码
{
	std::ifstream ifs;
	ifs.open(MAINTEACHER, std::ios::in);
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
	ofs.open(MAINTEACHER, std::ios::out | std::ios::trunc);//清除文档，重新写入
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
