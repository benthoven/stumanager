#include"systemmanager.h"
#include"abstract.h"//������
#include"manager.h"
#include"assitantteacher.h"
#include"mainteacher.h"

void systemmanager::showmenu()//���ܲ˵�
{
	std::cout << "\t��ӭʹ��ѧ���������ϵͳ\t" << std::endl;
	std::cout << "\t����������������������������������\t" << std::endl;
	std::cout << "\t��ѡ���������:\t" << std::endl;
	std::cout << "\t1.���񴦹���Ա\t" << std::endl;
	std::cout << "\t2.����ϵ����Ա\t" << std::endl;
	std::cout << "\t3.����ϵ����Ա\t" << std::endl;
}
void systemmanager::login()//��¼����
{
	int choice = 0;
	std::cin >> choice;
	switch (choice)
	{
	case 1://�������Ա
		check(MANAGER,1);
		break;
	case 2://������ʦ
		check(MAINTEACHER,2);
		break;
	case 3://������ʦ
		check(ASSITANTTEACHER, 3);
		break;
	default:
		break;
	}
}
void systemmanager::check(std::string filename, int type)//�˺ż��
{
	systemmanager sm;//�������������
	std::ifstream ifs;
	ifs.open(filename, std::ios::in);//�Զ��ķ�ʽ���ļ�
	if (!ifs.is_open())
	{
		std::cout << "����ļ���ʧ�ܣ������ļ�����" << std::endl;
		return;
	}
	std::cout << "�����������û���" << std::endl;
	std::string  account ;
	std::cin >> account;
	std::cout << "��������������(��λ����)" << std::endl;
	int password ;
	std::cin >> password;

	if (type == 1)//����
	{//���ն�ȡ����
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "�˺���֤�ɹ�����ӭ���񴦹���Ա " << account << " ��¼" << std::endl;
				system("pause");
				system("cls");
				
				abstract* ab = new manager;//����ָ��ָ��������󣬵��ö�̬
				sm.managerfunction(ab);//
				delete ab;//���ٶ���
			}
			else
			{
				std::cout << "��¼ʧ�ܣ������˺ţ�����" << std::endl;
				return;
			}
		}
		
	}
	else if (type == 2)//������ʦ
	{//���ն�ȡ����
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "�˺���֤�ɹ�����ӭ������ʦ " << account << " ��¼" << std::endl;
				system("pause");
				system("cls");

				abstract* ab = new mainteacher;//����ָ��ָ��������󣬵��ö�̬
				sm.mainteafunction(ab);//
				delete ab;//���ٶ���
			}
			else
			{
				std::cout << "��¼ʧ�ܣ������˺ţ�����" << std::endl;
				return;
			}
		}
	}
	else if (type == 3)//������ʦ
	{//���ն�ȡ����
		std::string readaccount;
		int readpassword;
		while (ifs >> readaccount && ifs >> readpassword)
		{
			if (account == readaccount && password == readpassword)
			{
				std::cout << "�˺���֤�ɹ�����ӭ������ʦ " << account << " ��¼" << std::endl;
				system("pause");
				system("cls");

				abstract* ab = new assitanteacher;//����ָ��ָ��������󣬵��ö�̬
				sm.assitantteafunction(ab);//
				delete ab;//���ٶ���
			}
			else
			{
				std::cout << "��¼ʧ�ܣ������˺ţ�����" << std::endl;
				return;
			}
		}
	}
}

void systemmanager::managerfunction(abstract*& ab)//�������Ա���ܽӿ�
{
	//Ҫ��������ǹ�ͬ��������ת������
	manager* man = (manager*)ab;
	int select = 0;
	std::cout << "���������ѡ��" << std::endl;
	//ѡ���֧
	while (1)
	{
		man->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://�鿴ѧ���б�
			man->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://�鿴ѧ����Ϣ
			man->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://�޸�ѧ����Ϣ
			man->changestuinf();
			system("pause");
			system("cls");
			break;
		case 3://ɾ��ѧ����Ϣ
			man->delstu();
			system("pause");
			system("cls");
			break;
		case 4://��������
			man->setownpass();
			std::cout << "���ٳɹ�" << std::endl;
			system("pause");
			system("cls");
			break;
		case 5://�˳�ϵͳ
			return;
			break;

		default://ע��
			return;
			break;
		}
	}
}
void systemmanager::mainteafunction(abstract*& ab)//���޽�ʦ���ܽӿ�
{
	mainteacher* man = (mainteacher*)ab;
	int select = 0;
	std::cout << "���������ѡ��" << std::endl;

	//ѡ���֧
	while (1)
	{
		man->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://�鿴ѧ���б�

			man->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://�鿴ѧ����Ϣ
			man->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://¼�����޳ɼ�
			man->setstuscore();
			system("pause");
			system("cls");
			break;
		case 3://�鿴�ɼ�����ѧ��
			man->showpriorstu();
			system("pause");
			system("cls");
			break;
		case 4://�鿴��Ҫ����ѧ��
			man->showinfiorstu();
			std::cout << "���ٳɹ�" << std::endl;
			system("pause");
			system("cls");
			break;
		case 5://��������
			man->setownpass();
			system("pause");
			system("cls");
			break;
		case 6://�˳�ϵͳ
			return;
			break;
		default://�˳�ϵͳ
			return;
			break;
		}
	}
}
void systemmanager::assitantteafunction(abstract*& ab)//���޽�ʦ���ܽӿ�
{
	assitanteacher* ast = (assitanteacher*)ab;
	int select = 0;
	std::cout << "���������ѡ��" << std::endl;

	//ѡ���֧
	while (1)
	{
		ast->showmenu();
		std::cin >> select;
		switch (select)
		{
		case 0://�鿴ѧ���б�
			ast->showstudentlist();
			system("pause");
			system("cls");
			break;
		case 1://�鿴ѧ����Ϣ
			ast->showstuinf();
			system("pause");
			system("cls");
			break;
		case 2://¼�븨��רҵ������
			ast->setassitansub();
			system("pause");
			system("cls");
			break;
		case 3://�鿴��Ҫ������ѧ��
			ast->showinfriorstu();
			system("pause");
			system("cls");
			break;
		case 4://��������
			ast->setownpass();
			system("pause");
			system("cls");
			break;
		case 5://�˳�ϵͳ
			return;
			break;
		default://ע��
			return;
			break;
		}
	}

}
