#include"stubase.h"
#include<fstream>

void stubase::inputinformation(int n)//������Ϣ
{
	if (n == 0)
	{
		std::cout << "�����������ѧ�ţ�" <<std::endl;
		std::cin>>s_id;
	}
	else
	{
		s_id = n;//û��ֱ�Ӵ���
	}
	std::cout << "�����������������" << std::endl;
	std::cin >> s_name;
	std::cout << "������������Ա�0��ʾ�У�1��ʾŮ����" << std::endl;
	std::cin>>s_sex;
	std::cout << "��������������䣺" << std::endl;
	std::cin>>s_age;
	std::cout << "����������ĵ�ַ��" << std::endl;
	std::cin >> s_address;
	std::cout << "���������������רҵ��" << std::endl;
	std::cin >> s_mainsubject;
	std::cout << "ѧ��" << s_name << "�Ļ�����Ϣ¼�����\n";

		
}
void stubase::showinformation()//��ʾ������Ϣ
{
	if (s_id == 0)
	{
		std::cout << "��Ϣ��δ¼�룡" << std::endl;
	}
	else
	{
		std::cout << " ѧ�ţ�" << s_id << " ������" << s_name << " �Ա�"<<s_sex 
			<< " ���䣺" <<s_age << " ��ַ��" << s_address << " ����רҵ��" << s_mainsubject << std::endl;
	}
	
}
void stubase::save(std::string a)//������Ϣ
{
	std::ofstream outfile;
	outfile.open("student" + a + ".txt", std::ios::out );
	outfile << s_id <<"  "<< s_name <<"  " << s_sex<<"  " << s_age<<"  " << s_address<<"  " << s_mainsubject<<"  " << std::endl;
	outfile.close();
	
}
void stubase::read(std::string a)//��ȡ��Ϣ
{
	std::ifstream ifs;
	ifs.open("student" + a + ".txt", std::ios::in );
	if (ifs.is_open())
	{
		ifs >> s_id >> s_name >> s_sex>> s_age >> s_address >> s_mainsubject ;
	}
	else
	{
		std::cout << "error" << std::endl;
		return;
	}
	
	ifs.close();
}

void mainsubject::inputscore()//¼��ɼ�
{
	for (int i = 0; i < mainsubjectnum; i++)
	{
		std::cout << "������������޿γ̵�" << i + 1 << "�ſ�Ŀ�ķ���" << std::endl;
		std::cin >> s_mainscore[i];

	}
	std::cout << "����ȫ���γ̳ɼ�¼�����" << std::endl;
}
void mainsubject::showscore()//��ʾ���޳ɼ�
{
	std::cout << "���޿γ̷�������" << std::endl;
	for (int i = 0; i < mainsubjectnum; i++)
	{
		std::cout << s_mainscore[i] << "\t";
	}
	std::cout << std::endl;
}
int mainsubject::getscore(int a)//��ȡ���Ƴɼ�
{
	if (a > 5)
	{
		std::cout << "����������С������" << std::endl;
	}
	return s_mainscore[a];
}
void mainsubject::save(std::string a)//������Ϣ
{
	std::ofstream ofs;
	ofs.open("major" + a + ".txt", std::ios::out);
	if (ofs.is_open())
	{
		for (int i = 0; i < mainsubjectnum; i++)
		{
			ofs << getscore(i) << " ";//�����ļ�
		}
		ofs.close();
	}
	else
	{
		std::cout << "open file is failed" << std::endl;
	}
}
void mainsubject::read(std::string a)//��ȡ��Ϣ
{
	std::ifstream ifs;
	ifs.open("major" + a + ".txt", std::ios::in);
	if (ifs.is_open())
	{
		for (int i = 0; i < mainsubjectnum; i++)
		{
			ifs >> s_mainscore[i] ;//��������
		}
	ifs.close();
	}
	else
	{
		std::cout << "�ļ���ȡʧ��" << std::endl;
		return;
	}
}
bool mainsubject::isstandard()//�ж��Ƿ�ȫ���ﵽ�ϸ��׼(���ſδﵽ85)
{
	int m = 0;
	for (int i = 0; i < mainsubjectnum; i++)
	{
		if (s_mainscore[i] >= 85)
		{
			m++;
		}
	}
	if (m >= 3) return true;
	return false;
} 
bool mainsubject::isresit()//�ж��Ƿ�ҿ�
{
	for (int i = 0; i < mainsubjectnum; i++)
	{
		if (s_mainscore[i]!=0&& s_mainscore[i] < 60)return true;
	}
	return false;
}

void assitantsubject::setassub()//���ø���רҵ����
{
	std::cout << "�������������רҵ����" << std::endl;
	std::cin >> assitantsub;
}
void assitantsubject::inputasssubscore()//���븨��רҵ�ɼ�
{
	if (assitantsub == " ")
	{
		std::cout << "����ѡ������ĸ���רҵ" << std::endl;
		return;
	}
	for (int i = 0; i < assitantsubnum; i++)
	{
		std::cout << "������������޿γ̵�" << i + 1 << "�ſ�Ŀ�ķ���" << std::endl;
		std::cin >> s_assitantscore[i];
	}
}
bool assitantsubject::istesit()//�ж��Ƿ�ҿ�
{
	for (int i = 0; i < assitantsubnum; i++)
	{
		if (10<s_assitantscore[i]&& s_assitantscore[i] < 60)return true;
	}
	return false;
}
void assitantsubject::save(std::string a)//������Ϣ
{
	std::ofstream ofs;
	ofs.open("assitantsub" + a + ".txt", std::ios::out);
	ofs << assitantsub<<"  ";//�Ƚ�רҵд��
	for (int i = 0; i < assitantsubnum; i++)//��д����
	{
		ofs << getscore(i) << " " ;//�����ļ�
	}
	ofs.close();
}
void assitantsubject::read(std::string a)//��ȡ��Ϣ
{
	std::ifstream ifs;
	ifs.open("assitantsub" + a + ".txt", std::ios::in);
	ifs >> assitantsub;//�ȶ�ȡרҵ
	for (int i = 0; i < assitantsubnum; i++)
	{
		ifs >> s_assitantscore[i];//��������
	}
	ifs.close();
}
int assitantsubject::getscore(int b)//��ȡĳһ�ſγ̳ɼ�
{
	if (b > 4)
	{
		std::cout << "����������С������" << std::endl;
	}
	return s_assitantscore[b];
}
void assitantsubject::showscore()//��ʾ���и��޿γ̳ɼ�
{
	std::cout << "����רҵ��" << assitantsub << std::endl;
	std::cout << "���޿γ̷�������" << std::endl;
	for (int i = 0; i < assitantsubnum; i++)
	{
		std::cout << s_assitantscore[i] << " ";
	}
	std::cout << std::endl;
}