#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"Data.h"
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Tool.h"
#include"Calculator.h"
using namespace std;

class Users {
public:
	Users() {
		User_ID[1] = '0';
		User_ID[2] = '0';
		User_ID[3] = '1';
	};
	bool User_Login();//用户登录
	bool Userinterface();//用户登录界面
	bool User_register();//用户注册
	bool User_Logout();//用户注销
	bool Check_Info();//查看个人信息
	bool Modify_info();//修改个人信息
	void Modify_money();//充值
	bool Check_hisorder();//查看历史订单
	char User_ID[5] = {'U'};//用户id
		char User_name[11];//用户名称
		char User_code[21];//用户密码
		char contactway[21];//联系方式
		char User_Addr[41];//用户地址
		string User_balance = "0";//账户余额
		char stage[8] ={ "active"};//用户状态
	
};
class Buyers :public Users
{
	friend Users;
public:
	bool Buyer_manu();//打印买家功能菜单
	bool Check_Goods1();//查看所有已上架商品
	bool Search_Goods1();//搜索所有已上架商品
	bool Buying();//购买商品
private:
};

class Sellers :public Users
{
	friend Users;
public:
	bool Seller_manu();//打印卖家功能菜单
	bool Add_Good();//上架商品
	bool Del_Good();//下架自己的商品
	bool Amend_Good();//修改商品信息
	bool Seller_Check_Goods();//卖家查看已发布商品
};
