#pragma once
#include<iostream>

class abstract 
{
public:
	virtual void showmenu()=0;//���ݲ�ͬ����Ҫ��д
	//�鿴ѧ���б�
	virtual void showstudentlist()=0;
	//�鿴ѧ����Ϣ
	virtual void showstuinf()=0;
	//��������
	virtual void setownpass()=0;
	
private:
	std::string account;//�˺�
	int password;//����
};