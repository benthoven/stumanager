#include"mainteacher.h"
#include"index.h"
#include"stubase.h"
#include"globalfile.h"

void mainteacher::showmenu()
{
	std::cout << "*****��ӭ���� ���޽�ʦ ҳ��*****" << std::endl;;
	std::cout << "\t***��ѡ����***\t" << std::endl;
	std::cout << "\t0.�鿴ѧ���б�\t" << std::endl;
	std::cout << "\t1.�鿴ѧ����Ϣ\t" << std::endl;
	std::cout << "\t2.¼�����޳ɼ�\t" << std::endl;
	std::cout << "\t3.�鿴�ɼ�����ѧ��\t" << std::endl;
	std::cout << "\t4.�鿴��Ҫ����ѧ��\t" << std::endl;
	std::cout << "\t5.��������\t" << std::endl;
	std::cout << "\t6.�˳�ϵͳ\t" << std::endl;
}

void mainteacher::setstuscore()//¼��ѧ���ɼ�
{
	index in;
	int n = in.selectbytype();//Ѱ��ѧ�����
	if (n == -1)
	{
		return;//����ʧ��
	}
	mainsubject major;
	major.inputscore();//¼��ɼ�����Ӧ����
	major.save(std::to_string(n));//���浽�ļ���
}

void mainteacher::showpriorstu()//�鿴�ɼ������ͬѧ
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
		std::cout << "û�гɼ������ѧ��" << std::endl;
	}
	else
	{
		std::cout << "�����ǳɼ������ѧ��" << std::endl;
	}
}

void mainteacher::showinfiorstu()//�鿴��Ҫ������ͬѧ
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
		std::cout << "û����Ҫ������ѧ��" << std::endl;
	}
	else
	{
		std::cout << "��������Ҫ������ѧ��" << std::endl;
	}
}
//�鿴ѧ���б�
void mainteacher::showstudentlist()
{
	index in;
	in.showindex();
}
//�鿴ѧ����Ϣ�����޿�Ŀ����
void mainteacher::showstuinf()
{
	index in;
	stubase stu;
	int n = in.selectbytype();
	if (n == -1)
	{
		std::cout << "����Ϣ������" << std::endl;
		return;
	}
	stu.read(std::to_string(n));
	stu.showinformation();
	mainsubject major;
	major.read(std::to_string(n));//��ȡ��Ϣ
	major.showscore();
	
}
void mainteacher::setownpass()//��������
{
	std::ifstream ifs;
	ifs.open(MAINTEACHER, std::ios::in);
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
	ofs.open(MAINTEACHER, std::ios::out | std::ios::trunc);//����ĵ�������д��
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
