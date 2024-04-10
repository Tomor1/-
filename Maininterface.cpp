#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Administrator.h"
#include"Users.h"
using namespace std;
extern void Logininterface() {
	cout << "欢迎使用本交易平台" << endl;
	cout << "==================================================" << endl
		<< "1.管理员登陆   2.用户登录   3.用户注册   4.退出程序" << endl;
	cout << "==================================================" << endl;
	string choice;
	cout << "请输入指令：";
L:cin >> choice;
	if(choice.length()>1){
		cout << "指令错误，请重新输入" << endl;
		getline(cin, choice);
		goto L;
	}
	switch (choice[0]) {
	case '1':
	{Administrator A;
		extern bool Admin_Login();
		getline(cin, choice);
		bool x=A.Admin_Login();
		if(x==0)Logininterface();
 }
 ;break;
	case '3': {
		Users U;
		extern bool User_register();
		int n = getchar();
		bool x = U.User_register();
		if (x == 0)Logininterface();
	};break;
	case '2': {
		Users U;
		extern bool User_Login();
		int n = getchar();
 		bool x = U.User_Login();
		if (x == 0)Logininterface();
	};break;
	case '4':cout << "欢迎下次使用" << endl;
		return;
	default:cout << "指令错误，请重新输入" << endl;
		getline(cin,choice );
		goto L;break;
	}
}
int main() {
  Logininterface();
}