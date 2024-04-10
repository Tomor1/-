#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class Good {
	public:
		Good() {
			G_ID[1] = '0';
			G_ID[2] = '0';
			G_ID[3] = '1';
		}
	char G_ID[5] = { 'M' };//商品id
	char G_Name[21];//商品名称
	string price;//商品价格
	char G_Number[3];//商品数量
	char G_info[201];//商品信息
	char G_Seller_ID[4] ;//卖家id
	char G_stage[4] = "on";//商品状态
	char G_OnTime[10];//上架时间
};

class Order {
public:
	Order() {
		O_ID[1] = '0';
		O_ID[2] = '0';
		O_ID[3] = '1';
	}
	char O_ID[5] = { 'T' };//订单id
	char O_G_ID[5];//所售商品id
	char O_G_num[1000];//所购商品数
	char O_Time[11];//订单时间
	char O_Buyer_ID[5] = { 'U' };//买家id
	char O_Seller_ID[5] = { 'U' };//卖家id
};