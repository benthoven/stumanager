#include"systemmanager.h"
#include"abstract.h"//抽象类
#include"manager.h"
#include"assitantteacher.h"
#include"mainteacher.h"

void systemmanager::showmenu()//功能菜单
{
	std::cout << "\t欢迎使用学生教务管理系统\t" << std::endl;
	std::cout << "\t—————————————————\t" << std::endl;
	std::cout << "\t请选择您的身份:\t" << std::endl;
	std::cout << "\t1.教务处管理员\t" << std::endl;
	std::cout << "\t2.主修系教务员\t" << std::endl;
	std::cout << "\t3.辅修系教务员\t" << std::endl;
}
void systemmanager::login()//登录功能
{
	int choice = 0;
	std::cin >> choice;
	switch (choice)
	{
	case 1://教务管理员
		check(MANAGER,1);
		break;
	case 2://主修老师
		check(MAINTEACHER,2);
		break;
	case 3://辅修老师
		check(ASSITANTTEACHER, 3);
		break;
	default:
		break;
	}
}
void systemmanager::check(std::string filename, int type)//账号检查
{
	systemmanager sm;//创建管理类对象
	std::ifstream ifs;
	ifs.open(filename, std::ios::in);//以读的方式打开文件
	if (!ifs.is_open())
	{
		std::cout << "检查文件打开失败，请检查文件名称" << std::endl;
		return;
	}
	std::cout << "请输入您的用户名" << std::endl;
	std::string  account ;
	std::cin >> account;
	std::cout << "请输入您的密码(三位数字)" << std::endl;
	int password ;
	std::cin >> password;

	if (type == 1)//教务
	{//接收读取内容
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "账号验证成功，欢迎教务处管理员 " << account << " 登录" << std::endl;
				system("pause");
				system("cls");
				
				abstract* ab = new manager;//父类指针指向子类对象，调用多态
				sm.managerfunction(ab);//
				delete ab;//销毁对象
			}
			else
			{
				std::cout << "登录失败，请检查账号，密码" << std::endl;
				return;
			}
		}
		
	}
	else if (type == 2)//主修老师
	{//接收读取内容
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "账号验证成功，欢迎主修老师 " << account << " 登录" << std::endl;
				system("pause");
				system("cls");

				abstract* ab = new mainteacher;//父类指针指向子类对象，调用多态
				sm.mainteafunction(ab);//
				delete ab;//销毁对象
			}
			else
			{
				std::cout << "登录失败，请检查账号，密码" << std::endl;
				return;
			}
		}
	}
	else if (type == 3)//辅修老师
	{//接收读取内容
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "账号验证成功，欢迎辅修老师 " << account << " 登录" << std::endl;
				system("pause");
				system("cls");

				abstract* ab = new assitanteacher;//父类指针指向子类对象，调用多态
				sm.assitantteafunction(ab);//
				delete ab;//销毁对象
			}
			else
			{
				std::cout << "登录失败，请检查账号，密码" << std::endl;
				return;
			}
		}
	}
}

void systemmanager::managerfunction(abstract*& ab)//教务管理员功能接口
{
	//要调用子类非共同函数必须转回子类
	manager* man = (manager*)ab;
	int select = 0;
	std::cout << "请输入你的选择" << std::endl;
	//选择分支
	while (1)
	{
		man->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://查看学生列表
			man->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://查看学生信息
			man->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://修改学生信息
			man->changestuinf();
			system("pause");
			system("cls");
			break;
		case 3://删除学生信息
			man->delstu();
			system("pause");
			system("cls");
			break;
		case 4://更改密码
			man->setownpass();
			std::cout << "销毁成功" << std::endl;
			system("pause");
			system("cls");
			break;
		case 5://退出系统
			return;
			break;

		default://注销
			return;
			break;
		}
	}
}
void systemmanager::mainteafunction(abstract*& ab)//主修教师功能接口
{
	mainteacher* man = (mainteacher*)ab;
	int select = 0;
	std::cout << "请输入你的选择" << std::endl;

	//选择分支
	while (1)
	{
		man->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://查看学生列表

			man->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://查看学生信息
			man->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://录入主修成绩
			man->setstuscore();
			system("pause");
			system("cls");
			break;
		case 3://查看成绩优秀学生
			man->showpriorstu();
			system("pause");
			system("cls");
			break;
		case 4://查看需要补考学生
			man->showinfiorstu();
			std::cout << "销毁成功" << std::endl;
			system("pause");
			system("cls");
			break;
		case 5://更改密码
			man->setownpass();
			system("pause");
			system("cls");
			break;
		case 6://退出系统
			return;
			break;
		default://退出系统
			return;
			break;
		}
	}
}
void systemmanager::assitantteafunction(abstract*& ab)//辅修教师功能接口
{
	assitanteacher* ast = (assitanteacher*)ab;
	int select = 0;
	std::cout << "请输入你的选择" << std::endl;

	//选择分支
	while (1)
	{
		ast->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://查看学生列表
			ast->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://查看学生信息
			ast->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://录入辅修专业及分数
			ast->setassitansub();
			system("pause");
			system("cls");
			break;
		case 3://查看需要补考的学生
			ast->showinfriorstu();
			system("pause");
			system("cls");
			break;
		case 4://更改密码
			ast->setownpass();
			system("pause");
			system("cls");
			break;
		case 5://退出系统
			return;
			break;
		default://注销
			return;
			break;
		}
	}

}
