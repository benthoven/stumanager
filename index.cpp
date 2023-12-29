#include"index.h"

index::index()//��ʼ������
{
	recreatindex();
}
void index::recreatindex()//��������
{
	std::ofstream ofs;//д��
	std::ifstream ifs;//����
	ofs.open("index.txt", std::ios::out);//д�ķ�ʽ��
	for (int i = 0; i < MAX_INDEX; i++)//��ѧ��������Ϣ��ȡ�������У���д�뵽�����ļ���
	{
		ifs.open("student" + std::to_string(i) + ".txt", std::ios::in);//to_string����ת�ַ�  �򿪶�Ӧѧ���ļ�
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
			//std::cout << "creat���ļ���ʧ��" << std::endl;
			ifs.close();
		}
	}
	ofs.close();
}
int index::searchbyid(int _id)//��ѧ�ż�������������λ��//����������
{
	for (int i=0; i < MAX_INDEX; i++)//��������
	{
		if (id[i] == _id)
		{
			return i;
		}
	}
	std::cout << "����ʧ��" << std::endl;
	return -1;
}
int index::searchbyname(std::string _name)//��������������������λ��
{
	for (int i = 0; i < MAX_INDEX; i++)//��������
	{
		if (name[i] == _name)
		{
			return i;
		}
	}
	std::cout << "����ʧ��" << std::endl;
	return -1;
}
int index::selectbytype()//������ɸѡ
{
	std::cout << "������Ҫ����ѧ����ѧ�Ż�������" << std::endl;
	int ret=0;
	int num;
	std::string name;
	if (!(std::cin >> num))//����
	{
		std::cin.clear();//�������,��������
		std::cin.sync();//�������
		std::cin >> name;
		ret = searchbyname(name);
		if (ret == -1)
		{
			std::cout << "��������ʧ��" << std::endl;
		}
		else
		{
			std::cout << "�������ҳɹ�" << std::endl;
			return ret;
		}
	}
	else//id����
	{
		ret= searchbyid(num);
		if (ret == -1)
		{
			std::cout << "ѧ�Ų���ʧ��" << std::endl;
		}
		else
		{
			std::cout << "ѧ�Ų��ҳɹ�" << std::endl;
			return ret;
		}
	}
}
void index::showindex()//��ʾ����
{
	int nums = 0;
	for (int i = 0; i <MAX_INDEX; i++)
	{
		if (id[i] == 0)continue;//�ų���λ��
		std::cout << "\tѧ�ţ�" << id[i] << "\t������" << name[i] << std::endl;
		nums++;
	}
	std::cout << "����" << nums << "��ѧ��" << std::endl;
}
void index::showonlyinf(int n)//��ʾ����ѧ����Ϣ
{
	std::cout << "\tѧ�ţ�" << id[n] << " \t������" << name[n] << std::endl;
}
int index::getid(int n)//��ȡѧ��
{
	return id[n];
}
int index::getpos()//��ȡ��Ч����
{
	int pos = 0;
	for (int i = 1; i < MAX_INDEX; i++)
	{
		pos = i;
		if (id[pos] == 0 && id[pos+ 1] == 0)return pos;
	}
}