#include"assitantteacher.h"
#include"index.h"
#include"stubase.h"
#include"globalfile.h"

void  assitanteacher::showmenu()//重写
{
	std::cout << "*****欢迎进入 辅修教师 页面*****" << std::endl;
	std::cout << "\t***请选择功能***\t" << std::endl;
	std::cout << "\t0.查看学生列表\t" << std::endl;
	std::cout << "\t1.查看学生信息\t" << std::endl;
	std::cout << "\t2.设置辅修专业并录入辅修成绩\t" << std::endl;
	std::cout << "\t3.查看需要补考学生\t" << std::endl;
	std::cout << "\t4.更改密码\t" << std::endl;
	std::cout << "\t5.退出系统\t" << std::endl;
}

void  assitanteacher::setassitansub()//设置辅修专业
{
	index in;
	int n = in.selectbytype();//寻找学生编号
	if (n == -1)
	{
		return;//搜索失败
	}
	assitantsubject asub;
	asub.setassub();
	asub.save(std::to_string(n));

	asub.inputasssubscore();//录入成绩到相应数组
	asub.save(std::to_string(n));//保存到文件中
	std::cout << "学生信息录入成功" << std::endl;
}

void  assitanteacher::showinfriorstu()//查看需要补考的学生
{
	index in;
	int m = 0;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		assitantsubject asub;;
		asub.read(std::to_string(i));
		if (asub.istesit())
		{
			in.showonlyinf(i);
			asub.showscore();
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
void assitanteacher::showstudentlist()
{
	index in;
	in.showindex();
}
//查看学生信息
void assitanteacher::showstuinf()//查看学生辅修专业及辅修科目成绩
{
	index in;
	stubase stu;
	int n = in.selectbytype();
	
	stu.read(std::to_string(n));
	stu.showinformation();
	assitantsubject assub;
	assub.read(std::to_string(n));//读取信息
	assub.showscore();
}

void assitanteacher::setownpass()//更改密码
{
	std::ifstream ifs;
	ifs.open(ASSITANTTEACHER, std::ios::in);
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
	ofs.open(ASSITANTTEACHER, std::ios::out | std::ios::trunc);//清除文档，重新写入
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
