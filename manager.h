#pragma once
#include"abstract.h"
#include<fstream>

class manager :public abstract
{
public:
	void showmenu();//�˵�

	void addstu();//���ѧ��

	void changestuinf();//�޸�ѧ����Ϣ

	void delstu();//ɾ��ѧ����Ϣ
	
	//�鿴ѧ���б�
	 void showstudentlist();

	//�鿴ָ��ѧ����Ϣ
	 void showstuinf();

	//��������
	 void setownpass();
};