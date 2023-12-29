#include"assitantteacher.h"
#include"index.h"
#include"stubase.h"
#include"globalfile.h"

void  assitanteacher::showmenu()//��д
{
	std::cout << "*****��ӭ���� ���޽�ʦ ҳ��*****" << std::endl;
	std::cout << "\t***��ѡ����***\t" << std::endl;
	std::cout << "\t0.�鿴ѧ���б�\t" << std::endl;
	std::cout << "\t1.�鿴ѧ����Ϣ\t" << std::endl;
	std::cout << "\t2.���ø���רҵ��¼�븨�޳ɼ�\t" << std::endl;
	std::cout << "\t3.�鿴��Ҫ����ѧ��\t" << std::endl;
	std::cout << "\t4.��������\t" << std::endl;
	std::cout << "\t5.�˳�ϵͳ\t" << std::endl;
}

void  assitanteacher::setassitansub()//���ø���רҵ
{
	index in;
	int n = in.selectbytype();//Ѱ��ѧ�����
	if (n == -1)
	{
		return;//����ʧ��
	}
	assitantsubject asub;
	asub.setassub();
	asub.save(std::to_string(n));

	asub.inputasssubscore();//¼��ɼ�����Ӧ����
	asub.save(std::to_string(n));//���浽�ļ���
	std::cout << "ѧ����Ϣ¼��ɹ�" << std::endl;
}

void  assitanteacher::showinfriorstu()//�鿴��Ҫ������ѧ��
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
		std::cout << "û����Ҫ������ѧ��" << std::endl;
	}
	else
	{
		std::cout << "��������Ҫ������ѧ��" << std::endl;
	}

}
//�鿴ѧ���б�
void assitanteacher::showstudentlist()
{
	index in;
	in.showindex();
}
//�鿴ѧ����Ϣ
void assitanteacher::showstuinf()//�鿴ѧ������רҵ�����޿�Ŀ�ɼ�
{
	index in;
	stubase stu;
	int n = in.selectbytype();
	
	stu.read(std::to_string(n));
	stu.showinformation();
	assitantsubject assub;
	assub.read(std::to_string(n));//��ȡ��Ϣ
	assub.showscore();
}

void assitanteacher::setownpass()//��������
{
	std::ifstream ifs;
	ifs.open(ASSITANTTEACHER, std::ios::in);
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
	ofs.open(ASSITANTTEACHER, std::ios::out | std::ios::trunc);//����ĵ�������д��
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
