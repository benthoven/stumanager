#pragma once

#include<iostream>
#include<fstream>
#include"globalfile.h"
#include"abstract.h"

class systemmanager
{
public:
	
	void showmenu();//���ܲ˵�
	void login();//��¼����
	void check(std::string filename,int type);//�˺ż��
	void managerfunction(abstract*& ab);//�������Ա���ܽӿ�//ָ�������
	void mainteafunction(abstract*& ab);//���޽�ʦ���ܽӿ�
	void assitantteafunction(abstract*& ab);//���޽�ʦ���ܽӿ�
};
