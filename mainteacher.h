#pragma once
#include"abstract.h"

class mainteacher :public abstract
{
public:
	void showmenu();

	void setstuscore();//¼��ѧ���ɼ�

	void showpriorstu();//�鿴�ɼ������ͬѧ

	void showinfiorstu();//�鿴��Ҫ������ͬѧ

	
	//�鿴ѧ���б�
	 void showstudentlist();

	//�鿴ѧ����Ϣ�����޿�Ŀ����
	 void showstuinf() ;

	//��������
	 void setownpass();

	
};