#pragma once
#include<iostream>

#define mainsubjectnum 5//���޿�Ŀ ���
#define assitantsubnum 4//���޿�Ŀ �ĸ�

class stubase
{
public:
	//stubase(int id, std::string name, bool sex,int age,std::string address,std::string mainsubject);//���캯��
	void inputinformation(int n);//������Ϣ
	void showinformation();//��ʾ������Ϣ
	void save(std::string);//������Ϣ
	void read(std::string);//��ȡ��Ϣ
private:
	int s_id;//ѧ��
    std::string s_name;//����
	std::string s_sex;//�Ա� 0Ů 1 ��
	int s_age;//����
	std::string s_address;//��ͥסַ
	std::string s_mainsubject;//����רҵ
	
};

class mainsubject:public stubase//���޿�Ŀ
{
public:
	void inputscore();//¼��ɼ�
	void showscore();//��ʾ�ɼ�
	int getscore(int a);//��ȡ���Ƴɼ�
	void save(std::string a);//������Ϣ
	void read(std::string a);//��ȡ��Ϣ
	bool isstandard();//�ж��Ƿ�ȫ���ﵽ�ϸ��׼(���ſδﵽ85)
	bool isresit();//�ж��Ƿ�ҿ�

private:
	int s_mainscore[7] = {0};//���޿�Ŀ����
};

class assitantsubject:public stubase
{
public:
	void setassub();//���ø���רҵ����
	void inputasssubscore();//���븨��רҵ�ɼ�
	bool istesit();//�ж��Ƿ�ҿ�
	int getscore(int b);//��ȡĳһ�ſγ̳ɼ�
	void showscore();//��ʾ���и��޿γ̳ɼ�
	void save(std::string);//������Ϣ
	void read(std::string);//��ȡ��Ϣ
private:
	std::string assitantsub;//����רҵ
	int s_assitantscore[5] = {0};//���޿�Ŀ�ɼ�

};