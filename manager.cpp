#include"manager.h"
#include"index.h"
#include"stubase.h"
#include<fstream>
#include"globalfile.h"

void manager::showmenu() //���ݲ�ͬ����Ҫ��д
{
	std::cout << "*****��ӭ����������Աҳ��*****" << std::endl;
	std::cout << "\t***��ѡ����***\t" << std::endl;
	std::cout << "\t0.�鿴ѧ���б�\t" << std::endl;
	std::cout << "\t1.�鿴ѧ����Ϣ\t" << std::endl;
	std::cout << "\t2.�޸�ѧ����Ϣ\t" << std::endl;
	std::cout << "\t3.ɾ��ѧ����Ϣ\t" << std::endl;
	std::cout << "\t4.��������\t" << std::endl;
	std::cout << "\t5.�˳�ϵͳ\t" << std::endl;
}

void manager::addstu()//���ѧ��
{
	index in;
	int pos = in.getpos();
	std::cout << "�밴Ҫ������������Ϣ" << std::endl;
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
			std::cout << "������ѧ��(����)" << std::endl;
			std::cin >> id;
			std::cout << "����������" << std::endl;
			std::cin >> name;
			std::cout << "�������Ա�(��/Ů)" << std::endl;
			std::cin >> sex;
			std::cout << "����������" << std::endl;
			std::cin >> age;
			std::cout << "�������ͥסַ" << std::endl;
			std::cin >> address;
			std::cout << "����������רҵ" << std::endl;
			std::cin >> subject;
			//д��
			ofs << id << "  " << name << "  " << sex << "  " << age << "  "  << address << "  " << subject << "  " << std::endl;
			std::cout << "���ѧ����Ϣ�ɹ�" << std::endl;
			ofs.close();
			std::cout << "�Ƿ�������ѧ����Ϣ(0.��  1.��)" << std::endl;
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
			std::cout << "�ļ���ʧ��" << std::endl;
			return;
		}
		
	}
}
//�鿴ѧ���б�
void manager::showstudentlist()
{
	index in;
	in.showindex();
}
//�鿴ָ��ѧ����Ϣ
void manager::showstuinf()
{
	index in;
	stubase stu;
	int n=in.selectbytype();
	if (n == -1)
	{
		std::cout << "����Ϣ������" << std::endl;
		return;
	}
	stu.read(std::to_string(n));
	stu.showinformation();

}

void manager::setownpass()//��������
{
	std::ifstream ifs;
	ifs.open(MANAGER, std::ios::in);
	std::string readaccount;//׼������
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
	ofs.open(MANAGER, std::ios::out | std::ios::trunc);//����ĵ�������д��
	if (ofs.is_open())
	{
		std::cout << "����������������(��λ����)" << std::endl;
		std::cin >> readpassword;
		ofs << readaccount << "  " << readpassword << std::endl;;
		std::cout << "�����޸ĳɹ���" << std::endl;
	}
	else
	{
		std::cout << "open error" << std::endl;
		return;
	}
}

void manager::changestuinf()//�޸�ѧ����Ϣ
{
	index in;
	std::cout << "�������޸�ѧ����Ϣ������" << std::endl;
	int n = in.selectbytype();
	stubase stu;
	stu.read(std::to_string(n));
	std::cout << "�����������ѧ���Ļ�����Ϣ" << std::endl;
	stu.inputinformation(n);
	stu.save(std::to_string(n));
	in.recreatindex();//���³�ʼ����������
}

void manager::delstu()//ɾ��ѧ����Ϣ
{
	index in;
	std::cout << "������ɾ��ѧ����Ϣ������" << std::endl;
	int n = in.selectbytype();
	std::ofstream ofs;
	ofs.open("student" + std::to_string(n) + ".txt",std::ios::out|std::ios::trunc);
	if (ofs.is_open())
	{
		ofs << 0 << " " << "NULL" << std::endl;
		std::cout << "ɾ���ɹ�" << std::endl;
		in.recreatindex();//�ؽ�����
	}
	ofs.close();
}