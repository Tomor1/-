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
	bool Admininterface();//管理员面板
	bool Admin_Login();//管理员登录
	void Check_Goods();//查看所有商品
	bool Search_Goods();//搜索商品
	bool ItemDownshelf();//下架商品
	void Check_orders();//查看订单
	void Check_Users();//查看用户
	bool Ban_Users();//封禁用户
	bool Admin_Logout();//管理员注销
private:
	char a_name[6] = "admin";
	char a_code[7] = "123456";
};