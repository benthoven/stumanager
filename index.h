#pragma once
#include<iostream>
#include<fstream>
#include<string>
#define MAX_INDEX 200


class index
{
public:
	index();//���캯��
	void recreatindex();//�ؽ�����
	int searchbyid(int _id);//��ѧ�ż�������������λ��
	int searchbyname(std::string _name);//��������������������λ��
	int selectbytype();//������ɸѡ
	void showindex();//��ʾ����
	void showonlyinf(int n);//��ʾ����ѧ����Ϣ
	int getid(int n);//��ȡѧ��
	int getpos();//��ȡ��Ч����

private:
	int id[MAX_INDEX] ;//ѧ��
	std::string name[MAX_INDEX];//����
};
