#pragma once
#include<iostream>
#include<string>
#include <stdio.h>
#include"Data.h"
#include"Tool.h"
#include<fstream>
using namespace std;
class Administrator
{
public:
	bool Admininterface();//����Ա���
	bool Admin_Login();//����Ա��¼
	void Check_Goods();//�鿴������Ʒ
	bool Search_Goods();//������Ʒ
	bool ItemDownshelf();//�¼���Ʒ
	void Check_orders();//�鿴����
	void Check_Users();//�鿴�û�
	bool Ban_Users();//����û�
	bool Admin_Logout();//����Աע��
private:
	char a_name[6] = "admin";
	char a_code[7] = "123456";
};