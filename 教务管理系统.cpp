#include<iostream>
#include"index.h"
#include"abstract.h"
#include"manager.h"
#include"systemmanager.h"
#include"mainteacher.h"
#include"assitantteacher.h"


int main()
{
	systemmanager sm;//�������������
	sm.showmenu();//��ʾ��¼�˵�
	sm.login();//��¼����
	

	system("pause");
	return 0;
}