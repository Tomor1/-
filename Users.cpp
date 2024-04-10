#include"Users.h"
string nowusersid = "";
/*用户注册*/bool Users::User_register() {
	FILE* fp = fopen("users.txt", "r+");
	if (fp == NULL)//此时没有用户（文件未创建）
	{		
		FILE* fp = fopen("users.txt", "at");
		char title[] = { "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态" };
		Users user;		
		char User_name[11] = { 0 };
		cout << "请输入您的名称：";
		cin>>User_name;
		int gg = getchar();
		for (int i = 0, j = 0;;) {
			//用户名不超十个字符
			while (User_name[i] != '\0')i++;
			if (i > 0 && i <= 10)i = 0;
			else {
				cout << "用户名格式错误，返回主菜单" << endl;return false;
			}
			//用户名英文字母
			while (User_name[i] != '\0' && (User_name[i] < 'A' || (User_name[i] > 'Z' && User_name[i] < 'a') || (User_name[i] > 'z' && User_name[i] <= '~')))
			{
				i++;j++;
			}
			if (j > 0) { cout << "用户名格式错误，返回主菜单" << endl;return false; }
			else if (j == 0);
			break;
		}//判断用户名格式是否正确
		char User_code[21] = { 0 };
		cout << "请输入您的密码：";
		cin>>User_code;
		int gg7 = getchar();
		for (int i = 0, j = 0;;) {
			//用户密码不超20个字符
			while (User_code[i] != '\0')i++;
			if (i > 0 && i <= 20);
			else {
				cout << "密码格式错误，返回主菜单" << endl;return false;
			}
			//密码仅为小写英文字母和数字
			int k = 0;
			while (User_code[k] != '\0' && ((((User_code[k] >= 'a') && (User_code[k] <= 'z'))) || (((User_code[k] >= '0') && (User_code[k] <= '9')))))
			{
				k++;j++;
			}
			if (j != i) { cout << "密码格式错误，返回主菜单" << endl;return false; }
			else ;
			break;
		}//判断用户密码格式是否正确
		//联系方式检验
		char contactway[21] = { 0 };
		cout << "请输入您的联系方式:";
		cin>>contactway;
		int gg9 = getchar();
		/*检验联系格式*/for (int i = 0, j = 0;;) {
			for (i = 0;contactway[i] != '\0';i++);
			if (i > 0 && i <= 20) {
				int k = 0;
				for (;contactway[k] >= '0' && contactway[k] <= '9';k++);
				if (k != i) { cout << "联系方式格式错误，返回主菜单" << endl;return false; }
				else break;
			}
			else {
				cout << "联系方式格式错误，返回主菜单" << endl;return false;
			}break;
		}
			char User_Addr[41] = { 0 };
			cout << "请输入您的地址:";
			cin>>User_Addr;
			int gg13 = getchar();
		/*检验地址格式*/for (int i = 0, j = 0;;) {
			for (j = 0;User_Addr[j] != '\0';j++);
			if (j > 0 && i <= 40) {
				for (int k = 0;(User_Addr[k] >= '0' && User_Addr[k] <= '9') || (User_Addr[k] >= 'a' && User_Addr[k] <= 'z') || (User_Addr[k] >= 'A' && User_Addr[k] <= 'Z');k++) {
					if (k != i) { cout << "地址格式错误，返回主菜单" << endl;return false; }
					else break;;
				}
			}
			else {
				cout << "地址格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char User_balance[9] = { '0' };
		char stage[8] = { "active"};
		fputs(title, fp);fputs("\n", fp);
		fputs(user.User_ID, fp);fputs(",", fp);
		fputs(User_name, fp);fputs(",", fp);
		fputs(User_code, fp);fputs(",", fp);
		fputs(contactway, fp);fputs(",", fp);
		fputs(User_Addr, fp);fputs(",", fp);
		fputs(User_balance, fp);fputs(",", fp);
		fputs(stage, fp);fputs("\n", fp);
		fclose(fp);
		cout << "注册成功，正在返回主界面" << endl;
		return 0;
	}
	else { 
		int x = 0;
		char line[256] = { 0 };
		while (fgets(line, 255, fp))
		{
			x++;
		}x -= 2;
		Users user;
		/*生成有序ID*/for (;x >= 0;x--) {
			user.User_ID[3] += 1;
			if (user.User_ID[3] > '9') {
				user.User_ID[3] = '0';
				user.User_ID[2] += 1;
				if (user.User_ID[2] > '9') {
					user.User_ID[2] = '0';
					user.User_ID[1] += 1;
					if (user.User_ID[1] > '9') { 
						cout << "用户人数已满，无法注册。";
							return false;
					}
				}
			}
		}
		fclose(fp);
		fp=fopen( "users.txt", "at");
		char User_name[11] = { 0 };
		cout << "请输入您的名称：";
		cin>>User_name;
		int gg8 = getchar();
		for (int i = 0, j = 0;;) {
			//用户名不超十个字符
			while (User_name[i] != '\0')i++;
			if (i > 0 && i <= 10)i = 0;
			else {
				cout << "用户名格式错误，返回主菜单" << endl;return false;
			}
			//用户名英文字母
			while (User_name[i] != '\0' && (User_name[i] < 'A' || (User_name[i] > 'Z' && User_name[i] < 'a') || (User_name[i] > 'z' && User_name[i] <= '~')))
			{
				i++;j++;
			}
			if (j > 0) { cout << "用户名格式错误，返回主菜单" << endl;return false; }
			else if (j == 0);
			break;
		}//判断用户名格式是否正确
		char User_code[21] = { 0 };
		cout << "请输入您的密码：";
		cin>>User_code;
		int gg10 = getchar();
		for (int i = 0, j = 0;;) {
			//用户密码不超20个字符
			while (User_code[i] != '\0')i++;
			if (i > 0 && i <= 20);
			else {
				cout << "密码格式错误，返回主菜单" << endl;return false;
			}
			//密码仅为小写英文字母和数字
			int k = 0;
			while (User_code[k] != '\0' && ((((User_code[k] >= 'a') && (User_code[k] <= 'z'))) || (((User_code[k] >= '0') && (User_code[k] <= '9')))))
			{
				k++;j++;
			}
			if (j != i) { cout << "密码格式错误，返回主菜单" << endl;return false; }
			else ;
			break;
		}//判断用户密码格式是否正确
		//联系方式检验
		char contactway[21] = { 0 };
		cout << "请输入您的联系方式:";
		cin >> contactway;
			int gg14 = getchar();
		/*检验联系格式*/for (int i = 0, j = 0;;) {
			for (i = 0;contactway[i] != '\0';i++);
			if (i > 0 && i <= 20) {
				int k = 0;
				for (;contactway[k] >= '0' && contactway[k] <= '9';k++);
					if (k != i) { cout << "联系方式格式错误，返回主菜单" << endl;return false; }
					else break;
			}
			else {
				cout << "联系方式格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char User_Addr[41] = { 0 };
		cout << "请输入您的地址:";
		cin>>User_Addr;
		int gg17 = getchar();
		/*检验地址格式*/for (int i = 0, j = 0;;) {
			for (j = 0;User_Addr[j] != '\0';j++);
			if (j > 0 && i <= 40) {
				for (int k = 0;(User_Addr[k] >= '0' && User_Addr[k] <= '9') || (User_Addr[k] >= 'a' && User_Addr[k] <= 'z') || (User_Addr[k] >= 'A' && User_Addr[k] <= 'Z');k++) {
					if (k != i) { cout << "地址格式错误，返回主菜单" << endl;return false; }
					else break;
				}
			}
			else {
				cout << "地址格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char User_balance[9] = { '0' };//默认初始余额为零
		char stage[8] = { "active"};//默认状态为在线
		fputs(user.User_ID, fp);
		fputs(",", fp);
		fputs(User_name, fp);fputs(",", fp);
		fputs(User_code, fp);fputs(",", fp);
		fputs(contactway, fp);fputs(",", fp);
		fputs(User_Addr, fp);fputs(",", fp);
		fputs(User_balance, fp);fputs(",", fp);
		fputs(stage, fp);fputs("\n", fp);
		fclose(fp);
		cout << "注册成功，正在返回主界面" << endl;
		return 0;
	}
}
int dijihang=0;
/*买家模式*/ bool Buyers::Buyer_manu() {

R1:	cout << "*********************************************************************************" << endl
		<< " 1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品描述 6.返回用户界面 " << endl
		<< "*********************************************************************************" << endl;
V:cout << "请输入指令:";
	string border;
	cin >> border;
	switch (border[0]) {
	/*查看商品列表*/case '1': {
		Check_Goods1();
		getline(cin, border);
		Buyer_manu();
	}break;
	/*购买商品*/case '2': {
		Buying();
		getline(cin, border);
		Buyer_manu();
	}break;
	/*搜索商品*/case '3':{
		Search_Goods1();
		getline(cin, border);
		Buyer_manu();
	}break;
	/*查看历史订单*/case '4': {Check_hisorder();
		getline(cin, border);
		Buyer_manu();}break;
	/*查看商品描述*/case '5': {
		getline(cin, border);
		cout << "请输入要查看的商品ID：";
		char tgID[5];
		cin >> tgID;

		char time[22] = { 0 };
		Gettime(time);
		char str[] = { "SELECT * FROM commodity WHERE 商品ID CONTAINS " };
		FILE* fp=fopen( "commands.txt", "at");
		if (fp == NULL)
		{
			printf("当前无法进行该操作\n");
			exit(-1);
		}
		fputs(time, fp);
		fputs(str, fp);fputs(tgID, fp);
		fputs("\n", fp);
		fclose(fp);

		if (strlen(tgID) != 4) {
			cout << "商品ID格式错误，返回选择菜单" << endl;
			goto R1;
		}
		else if( (tgID[0]!='M')||((tgID[1]<'0'||tgID[1]>'9'))|| ((tgID[2] < '0' || tgID[2]>'9'))|| ((tgID[3] <= '0' || tgID[3]>'9'))) {
			cout << "商品ID格式错误，返回选择菜单" << endl;
			goto R1;
		}
		else {
			ifstream fin("goods.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				goto R1;
			}
			else{
				fin.close();
				ifstream infile("goods.txt");
				char line[256] = { 0 };
				string temp;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					if (strstr(line, tgID) != NULL)
					{
						int i = 0;
						temp = line;int p = 0;
						for (int c = 0;c < 4;i++) {
							if (temp[i] == ',')c++;
						}
						for (int c = 0;c < 5;p++) {
							if (temp[p] == ',')c++;
						}
						string mof = temp;
						temp = mof.substr(i, p-i-1);
					}
				} infile.close();
				cout << temp << endl;
				getline(cin, border);
				Buyer_manu();
			}
		}
	}break;
	/*返回用户界面*/case '6': {Userinterface();}break;
	default: {
		cout << "指令错误，请重新输入" << endl;
		getline(cin, border);
		goto V;
	}
	};return true;
}

/*卖家模式*/ bool Sellers::Seller_manu() {
R:	cout << "*********************************************************************************" << endl
		<< " 1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户界面 " << endl
		<< "*********************************************************************************" << endl;
X:cout << "请输入指令:";
	string border;
	cin >> border;
	switch (border[0]) {
	/*发布商品*/case '1': {
		getline(cin, border);
		Add_Good();
		getline(cin, border);
		Seller_manu();
}break;
	/*查看发布商品*/case '2': {
		Seller_Check_Goods();
			getline(cin, border);
			Seller_manu();
		}break;
	/*修改商品信息*/case '3': {
		Amend_Good();
		getline(cin, border);
		Seller_manu();
	}break;
	/*下架商品*/case '4': {	
		Del_Good();
		getline(cin, border);
		Seller_manu();
	}break;
	/*查看历史订单*/case '5': {
		Check_hisorder();
		getline(cin, border);
		Seller_manu();
	}break;
	/*返回用户界面*/case '6': {Userinterface();}break;
	default: {
		cout << "指令错误，请重新输入" << endl;
		getline(cin, border);
		goto X;
	}
	};return true;
}

/*用户登录界面*/bool Users::Userinterface() {
	cout << "===============================================" << endl
		<< " 1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录 " << endl
		<< "================================================" << endl;
	cout << "请输入指令:";
	string order;
M:cin >> order;
	if (order.length() > 1) {
		cout << "指令错误，请重新输入" << endl;
		getline(cin, order);
		goto M;
	}
	switch (order[0]) {
	/*买家模式*/case '1': {
		Buyers b;
		getline(cin, order);
		b.Buyer_manu();
		break;}break;
	/*卖家模式*/case '2': {
		Sellers s;
		getline(cin, order);
		s.Seller_manu();
		break;}break;
	/*个人信息管理*/case '3': {
	H:	cout << "==============================================" << endl
		<< " 1.查看信息 2.修改信息 3.充值 4.返回用户主界面 " << endl
		<< "===============================================" << endl;
	cout << "请输入指令:";
	string order1;
	cin >> order1;
	if (order1.length() > 1) {
		cout << "指令错误，请重新输入" << endl;
		getline(cin, order1);
		goto H;
	}
	switch (order1[0]) {
	/*查看信息*/case '1': {
		Check_Info();
		goto H;
	}break;
	/*修改信息*/case '2': {
		Modify_info();
		goto H;
	}
	/*充值*/case '3': {
		Modify_money();
		goto H;
	}break;
	/*返回用户主界面*/case '4': {Userinterface();}break;
	default: {cout << "指令错误，请重新输入" << endl;
		getline(cin, order1);
		goto H;
	}
	}
	};break;
	/*注销登录*/case '4': {
		extern void Logininterface();
		Logininterface();
	}break;
	default:cout << "指令错误，请重新输入" << endl;
		getline(cin, order);
		goto M;break;
	}return true;
}

/*用户登录*/ bool Users::User_Login() {
	char temp_name[100];
		char temp_code[100];
		int num = 0;
		cout << "请输入用户名称：";
		cin >> temp_name;
		cout << "请输入您的密码: ";
		cin >> temp_code;
		if (strlen(temp_name) > 10) {
			cout << "名称错误，登陆失败，返回主菜单" << endl;
			return false;
		}
		else {
			char line[256] = { 0 };int x = 0;
			ifstream infile("users.txt");
			if (!infile)
			{
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			while (!infile.eof())
			{   
				infile.getline(line, sizeof(line) - 1);x++;
				if (strstr(line, temp_name) != NULL)
				{
					infile.close();
					ifstream infile("users.txt");int x1 = x;
					while (!infile.eof() && x1 >= 0)
					{
						x1--;
						infile.getline(line, sizeof(line) - 1);
						if (x1 == 0) {
							if (strstr(line, temp_code) != NULL)
							{								
									string a= line;
									nowusersid = a.substr(0, 4);
								cout << "登陆成功" << endl;dijihang = x;
								Userinterface();
								return true;
							}
						}
					}
				     cout << "密码错误，请重试" << endl;
					 infile.close();
				    return false;
				}
			}
               cout << "名称错误，请重试" << endl;
			   return false;
		}
	}

/*查看个人信息*/bool Users::Check_Info() {
	ifstream fin("users.txt", ios::in);
	if (!fin.is_open()) {
		cout << "当前无法进行该操作" << endl;
		return false;
	}int k = dijihang;
	string buff;
	while (getline(fin, buff) && k >= 0) {
		k--;
		if (k == 0) {
			cout << "用户ID, 用户名, 密码, 联系方式, 地址, 钱包余额, 用户状态" << endl;
			cout << buff << endl;
		}
	}
	fin.close();
}

/*修改个人信息*/bool Users::Modify_info(){
G:	cout << "请选择要修改的信息： 1.用户名 2.联系方式 3.地址" << endl;
	string order2;
	cin >> order2;
	if (order2.length() > 1) {
		cout << "指令错误，请重新输入" << endl;
		getline(cin, order2);
		goto G;
	}
	switch (order2[0]) {
	/*改用户名*/case'1': {
		char tempname[11];
		cout << "请输入要修改的用户名：";
		cin >> tempname;
		if (strlen(tempname) > 10) {
			cout << "用户名格式错误，返回选择菜单" << endl;
			goto G;return false;
		}
		else {
			ifstream fin("users.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			int k = dijihang;
		T:	cout << "确认修改吗？请输入Y/N:";
			string yorn;
			cin >> yorn;
			if (yorn.length() != 1) {
				cout << "输入错误，请重试";goto T;
			}
			if (yorn[0] == 'Y') {
				fin.close();
				ifstream infile("users.txt");
				char line[256] = { 0 };
				string temp[999];int t = dijihang;int u = 0;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					temp[u] = line;
					if (t == 1)
					{
						int i = 0;
						for (int c = 0;c < 2;i++) {
							if (temp[u][i] == ',')c++;
						}string mof = temp[u];
						temp[u] = mof.substr(0, 5);
						temp[u] += tempname;
						temp[u] += mof.substr(i - 1, mof.length());
					}u++;t--;
				} infile.close();
				FILE* fp = fopen("users.txt", "w+");
				for (int j = 0;j < u - 1;j++) {
					fputs(temp[j].c_str(), fp);fputs("\n", fp);
				}fclose(fp);return true;
			}
			else if (yorn[0] == 'N') {
				goto G;
				return false;
			}
			else { cout << "输入错误，请重试";goto T; }
		}
	};break;
	/*联系方式*/case'2': {
		char cway[21];
		cout << "请输入要修改的联系方式：";
		cin >> cway;
		if (strlen(cway) > 20) {
			cout << "联系方式格式错误，返回选择菜单" << endl;
			goto G;return false;
		}
		else {
			ifstream fin("users.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			int k = dijihang;
		R:	cout << "确认修改吗？请输入Y/N:";
			string yorn;
			cin >> yorn;
			if (yorn.length() != 1) {
				cout << "输入错误，请重试";goto R;
			}
			if (yorn[0] == 'Y') {
				fin.close();
				ifstream infile("users.txt");
				char line[256] = { 0 };
				string temp[999];int t = dijihang;int u = 0;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					temp[u] = line;
					if (t == 1)
					{
						int i = 0;int p = 0;
						for (int c = 0;c < 3;p++) {
							if (temp[u][p] == ',')c++;
						}
						for (int c = 0;c < 4;i++) {
							if (temp[u][i] == ',')c++;
						}string mof = temp[u];
						temp[u] = mof.substr(0, p);
						temp[u] += cway;
						temp[u] += mof.substr(i - 1, mof.length());
					}u++;t--;
				} infile.close();
				FILE* fp = fopen("users.txt", "w+");
				for (int j = 0;j < u - 1;j++) {
					fputs(temp[j].c_str(), fp);fputs("\n", fp);
				}fclose(fp);return true;
			}
			else if (yorn[0] == 'N') {
				goto G;
				return false;
			}
			else { cout << "输入错误，请重试";goto R; }
		}
	};break;
	/*地址*/case'3': {
		char taddr[41];
		cout << "请输入要修改的地址：";
		cin >> taddr;
		if (strlen(taddr) > 40) {
			cout << "地址格式错误，返回选择菜单" << endl;
			goto G;return false;
		}
		else {
			ifstream fin("users.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			int k = dijihang;
		U:	cout << "确认修改吗？请输入Y/N:";
			string yorn;
			cin >> yorn;
			if (yorn.length() != 1) {
				cout << "输入错误，请重试";goto U;
			}
			if (yorn[0] == 'Y') {
				fin.close();
				ifstream infile("users.txt");
				char line[256] = { 0 };
				string temp[999];int t = dijihang;int u = 0;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					temp[u] = line;
					if (t == 1)
					{
						int i = 0;int p = 0;
						for (int c = 0;c < 4;p++) {
							if (temp[u][p] == ',')c++;
						}
						for (int c = 0;c < 5;i++) {
							if (temp[u][i] == ',')c++;
						}string mof = temp[u];
						temp[u] = mof.substr(0, p);
						temp[u] += taddr;
						temp[u] += mof.substr(i - 1, mof.length());
					}u++;t--;
				} infile.close();
				FILE* fp = fopen("users.txt", "w+");
				for (int j = 0;j < u - 1;j++) {
					fputs(temp[j].c_str(), fp);fputs("\n", fp);
				}fclose(fp);return true;
			}
			else if (yorn[0] == 'N') {
				goto G;
				return false;
			}
			else { cout << "输入错误，请重试";goto U; }
		}
	};break;
	};
}

/*充值*/void Users::Modify_money() {
	string tblanc;
	cout << "请输入您要充值的金额：";
	cin >> tblanc;
	if (tblanc.length() > 8) {
		cout << "金额错误，返回选择菜单" << endl;
	}
	else {
		ifstream fin("users.txt", ios::in);
		if (!fin.is_open()) {
			cout << "当前无法进行该操作" << endl;
		}
		int k = dijihang;
	E:	cout << "确认充值吗？请输入Y/N:";
		string yorn;
		cin >> yorn;
		if (yorn.length() != 1) {
			cout << "输入错误，请重试";goto E;
		}
		if (yorn[0] == 'Y') {
			fin.close();
			ifstream infile("users.txt");
			char line[256] = { 0 };
			string temp[999];int t = dijihang;int u = 0;
			while (!infile.eof())
			{
				infile.getline(line, sizeof(line) - 1);
				temp[u] = line;
				if (t == 1)
				{
					int p = 0;
					for (int c = 0;c < 5;p++) {
						if (temp[u][p] == ',')c++;
					}
					int i = 0;
					for (int c = 0;c < 6;i++) {
						if (temp[u][i] == ',')c++;
					}string mof = temp[u];
					string shizi = temp[u].substr(p, i - p - 1);
					shizi += '+';shizi += tblanc;
					Calculator a(shizi);
					
					temp[u] = mof.substr(0, p);
					temp[u] += a.jisuan();
					temp[u] += mof.substr(i - 1, mof.length());
				}u++;t--;
			} infile.close();
			FILE* fp = fopen("users.txt", "w+");
			for (int j = 0;j < u - 1;j++) {
				fputs(temp[j].c_str(), fp);fputs("\n", fp);
			}fclose(fp);cout << "充值成功。" << endl;
		}
		else if (yorn[0] == 'N') {
		}
		else { cout << "输入错误，请重试";goto E; }
	}
}

/*查看历史订单*/bool Users::Check_hisorder() {
	char time[22] = { 0 };
	Gettime(time);
	char str[] = { "SELECT * FROM order " };
	FILE* fp=fopen( "commands.txt", "at");
	if (fp == NULL)
	{
		printf("当前无法进行该操作\n");
		exit(-1);
	}
	fputs(time, fp);
	fputs(str, fp);
	fputs("\n", fp);
	fclose(fp);

	ifstream fin("users.txt", ios::in);
	if (!fin.is_open()) {
		cout << "当前无法进行该操作" << endl;
		exit(-1);
	}int k1 = dijihang;
	string buff;
	char G_Seller_ID[5] = { 0 };
	while (getline(fin, buff) && k1 >= 0) {
		k1--;
		if (k1 == 0) {
			buff = buff.substr(0, 4);
			strcpy(G_Seller_ID, buff.c_str());
		}
	}
	char line[256] = { 0 };int x = 0;
	ifstream infile("orders.txt");
	if (!infile)
	{
		cout << "当前无法进行该操作" << endl;
		return false;
	}
	while (!infile.eof())
	{
		infile.getline(line, sizeof(line) - 1);
		if (strstr(line, G_Seller_ID) != NULL)
		{
			string temp = line;
			int p = 0;
			for (int c = 0;c < 8;p++) {
				if (temp[p] == ',')c++;
			}
			cout << temp.substr(0, p - 1) << endl;
		}
	}infile.close();
}

/*买家查看所有已上架商品*/bool Buyers::Check_Goods1() {

	char time[22] = { 0 };
	Gettime(time);
	char str[] = { "SELECT * FROM commodity" };
	FILE* fp=fopen( "commands.txt", "at");
	if (fp == NULL)
	{
		printf("当前无法进行该操作\n");
		exit(-1);
	}
	fputs(time, fp);
	fputs(str, fp);
	fputs("\n", fp);
	fclose(fp);

	ifstream fin("goods.txt", ios::in);
	if (!fin.is_open()) {
		cout << "当前无法进行该操作" << endl;
		return false;
	}
	string buff;
	while (getline(fin, buff)) {
		string temp = buff;
		int p = 0;
		for (int c = 0;c < 8;p++) {
			if (temp[p] == ',')c++;
		}

		cout << temp.substr(0, p - 1) << endl;
	}
	fin.close();
}

/*买家搜索所有已上架商品*/bool Buyers::Search_Goods1() {
	char time[22] = { 0 };
	Gettime(time);
	char str[] = { "SELECT * FROM commodity WHERE 名称 CONTAINS " };
	FILE* fp=fopen( "commands.txt", "at");
	if (fp == NULL)
	{
		printf("当前无法进行该操作\n");
		exit(-1);
	}
	fputs(time, fp);
	fputs(str, fp);
	
	char good_name[100];
	int num = 0;
	cout << "请输入商品名称：";
	cin >> good_name;
	if (strlen(good_name) > 20) {
		cout << "商品名称错误，返回主菜单" << endl;
		return false;
	}
	else {
		fputs(good_name, fp);
		fputs("\n", fp);
		fclose(fp);

		char line[256] = { 0 };int x = 0;
		ifstream infile("goods.txt");
		if (!infile)
		{
			cout << "当前无法进行该操作" << endl;
			return false;
		}
		while (!infile.eof())
		{
			infile.getline(line, sizeof(line) - 1);
			if (strstr(line, good_name) != NULL)
			{
				string temp = line;
				int p = 0;
				for (int c = 0;c < 8;p++) {
					if (temp[p] == ',')c++;
				}
				cout << temp.substr(0, p - 1) << endl;
			}
		}infile.close();
	}
}

/*购买商品*/bool Buyers::Buying() {
	char good_id[100];
	int num = 0;int h = 0;string ttt;string gid;string gpri;string gbid;string gzt;
	cout << "请输入商品ID：";
	cin >> good_id;
	if (strlen(good_id) != 4) {
		cout << "商品ID错误，返回主菜单" << endl;
		return false;
	}
	else {
		char line[256] = { 0 };int x = 0;
		ifstream infile("goods.txt");
		if (!infile)
		{
			cout << "当前无法进行该操作" << endl;
			return false;
		}
		while (!infile.eof())
		{
			infile.getline(line, sizeof(line) - 1);
			if (strstr(line, good_id) != NULL)
			{
				string temp = line;
				int p = 0;int q = 0;int w = 0;int x = 0, y = 0, z = 0,u = 0;
				for (int c = 0;c < 1;x++) {
					if (temp[x] == ',')c++;
				}
				gid = temp.substr(0, x-1);
				for (int c = 0;c < 2;y++) {
					if (temp[y] == ',')c++;
				}
				for (int c = 0;c < 3;q++) {
					if (temp[q] == ',')c++;
				}
				gpri = temp.substr(y,q-1-y);
				for (int c = 0;c < 4;w++) {
					if (temp[w] == ',')c++;
				}
				ttt = temp.substr(q,w-1-q);
				for (int c = 0;c < 5;z++) {
					if (temp[z] == ',')c++;
				}
				gbid = temp.substr(z, 4);
				for (int c = 0;c < 7;u++) {
					if (temp[u] == ',')c++;
				}
				for (int c = 0;c < 8;p++) {
					if (temp[p] == ',')c++;
				}
				gzt = temp.substr(u, p-u-1);
				cout << temp.substr(0, p - 1) << endl;h++;
			}
		}infile.close();
	}
	if (h == 0) {
		cout << "无该商品,无法购买" << endl;
		return false;
	}
	else {
		cout << "请确认是否购买该商品，输入（Y.购买 N.不购买）：";
	T3:	string yorn;
		cin >> yorn;
		if (yorn.length() != 1) {
			cout << "输入错误，请重试";goto T3;
		}
		if (yorn[0] == 'Y') {
			if (gzt == "off") {
				cout << "该商品已无法购买。" << endl;
				return false;
			}
			else if (gzt == "on");
			string num;
			cout << "请输入要购买的商品数量:";
			cin >> num;
			if (num.length() > ttt.length()) { cout<<"商品数量不足" << endl; }
			else   {
				if (num == ttt || num < ttt) {
					//修改商品数量
					char* a = new char[1000];
					string shi1 = ttt + '-';shi1 += num;
					strcpy(a, shi1.c_str());
					
			//修改购买后余额
					char *b = new char[1000];string now$;
					ifstream fin1("users.txt", ios::in);
					if (!fin1.is_open()) {
						cout << "当前无法进行该操作" << endl;
						return false;
					}int k = dijihang;
					string buff;int z = 0,u=0;
					while (getline(fin1, buff) && k >= 0) {
						k--;
						if (k == 0) {
							for (int c = 0;c < 5;z++) {
								if (buff[z] == ',')c++;
							}
							for (int c = 0;c < 6;u++) {
								if (buff[u] == ',')c++;
							}
							now$ = buff.substr(z, u - z - 1);
						}
					}
					fin1.close();
					string shi2 = now$;shi2 += "-(";shi2 += num;shi2 += '*'; shi2 += gpri;shi2+=')';
					Calculator c2(shi2);
					if (c2.jisuan()[0] == '-') {
						cout << "余额不足，无法购买。" << endl;
						return false;
					}
					ifstream infile("users.txt");
					char line[256] = { 0 };
					string temp[999];int t = dijihang;int u1 = 0;
					while (!infile.eof())
					{
						infile.getline(line, sizeof(line) - 1);
						temp[u1] = line;
						if (t == 1)
						{
							int i = 0;
							for (int c = 0;c < 6;i++) {
								if (temp[u1][i] == ',')c++;
							}string mof = temp[u1];
							temp[u1] = mof.substr(0, z);
							temp[u1] += c2.jisuan();
							temp[u1] += mof.substr(i - 1, mof.length());
						}u1++;t--;
					} infile.close();
					FILE* fp3 = fopen("users.txt", "w+");
					for (int j = 0;j < u - 1;j++) {
						fputs(temp[j].c_str(), fp3);fputs("\n", fp3);
					}fclose(fp3);delete[]b;
					Calculator c1(a);
					ifstream fin("goods.txt", ios::in);
					if (!fin.is_open()) {
						cout << "当前无法进行该操作" << endl;
						return false;
					}
					else {
						ifstream infile("goods.txt");
						char line[256] = { 0 };
						string temp[999];int t = 0;int r = 0;
						while (!infile.eof())
						{
							infile.getline(line, sizeof(line) - 1);
							temp[t] = line;
							if (strstr(line, good_id) != NULL)
							{
								int i = 0;int p = 0;
								for (int c = 0;c < 3;p++) {
									if (temp[t][p] == ',')c++;
								}
								for (int c = 0;c < 4;i++) {
									if (temp[t][i] == ',')c++;
								}
								string mof = temp[t];
								temp[t] = mof.substr(0, p);
								temp[t] += c1.jisuan().substr(0, c1.jisuan().length() - 2);
								temp[t] += mof.substr(i - 1, mof.length());
							}t++;r++;
						} infile.close();
						FILE* fp2 = fopen("goods.txt", "w+");
						for (int j = 0;j < r - 1;j++) {
							fputs(temp[j].c_str(), fp2);
							//fputs("\n", fp2);
						}fclose(fp2);
					}delete[]a;


					FILE* fp = fopen("orders.txt", "r+");//生成订单
					char time[22] = { 0 };
					Gettime(time);string time1 = time;
					if (fp == NULL)//此时没有订单（文件未创建）
					{
						FILE* fp=fopen( "orders.txt", "at");
						char title[] = { "订单ID,商品ID,交易单价,数量,交易时间,卖家ID,买家ID" };
						Order ord;									
						fputs(title, fp);fputs("\n", fp);
						fputs(ord.O_ID, fp);fputs(",", fp);
						fputs(gid.c_str(), fp);fputs(",", fp);
						fputs(gpri.c_str(), fp);fputs(",", fp);
						fputs(num.c_str(), fp);fputs(",", fp);
						fputs(time1.substr(0,10).c_str(), fp);fputs(",", fp);
						fputs(gbid.c_str(), fp);fputs(",", fp);
						fputs(nowusersid.c_str(), fp);fputs("\n", fp);
						fclose(fp);		
						cout << "订单生成成功" << endl;
					}
					else {
						int v = 0;
						char line[256] = { 0 };
						while (fgets(line, 255, fp))
						{
							v++;
						}v -= 2;
						Order ord;
						/*生成有序ID*/for (;v >= 0;v--) {
							ord.O_ID[3] += 1;
							if (ord.O_ID[3] > '9') {
								ord.O_ID[3] = '0';
								ord.O_ID[2] += 1;
								if (ord.O_ID[2] > '9') {
									ord.O_ID[2] = '0';
									ord.O_ID[1] += 1;
									if (ord.O_ID[1] > '9') {
										cout << "订单数已满，无法下单。";
										return false;
									}
								}
							}
						}
						fclose(fp);
						fp=fopen( "orders.txt", "at");
						fputs(ord.O_ID, fp);fputs(",", fp);
						fputs(gid.c_str(), fp);fputs(",", fp);
						fputs(gpri.c_str(), fp);fputs(",", fp);
						fputs(num.c_str(), fp);fputs(",", fp);
						fputs(time1.substr(0, 10).c_str(), fp);fputs(",", fp);
						fputs(gbid.c_str(), fp);fputs(",", fp);
						fputs(nowusersid.c_str(), fp);fputs("\n", fp);
						fclose(fp);
						cout << "订单生成成功" << endl;						
					}
					cout << "购买成功"<<endl;
				}
				else if(num>ttt) { cout << "商品数量不足" << endl; }
			}
		}
		else if (yorn[0] == 'N') { return false; }
		else {
			cout << "输入错误，请重新输入";
			goto T3;
		}
	}
}

/*卖家上架商品*/bool Sellers::Add_Good() {
	FILE* fp = fopen("goods.txt", "r+");
	if (fp == NULL)//此时没有商品（文件未创建）
	{
		Good good;
		FILE* fp = fopen("goods.txt", "at");
		char title[] = { "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态,其余" };
		char G_Name[21] = { 0 };
		cout << "请输入商品的名称：";
		cin>>G_Name;
		int g8 = getchar();
		for (int i = 0, j = 0;;) {
			//good名不超20个字符
			while (G_Name[i] != '\0')i++;
			if (i > 0 && i <= 20)i = 0;
			else {
				cout << "商品名格式错误，返回主菜单" << endl;return false;
			}
			//商品名英文字母
			while (G_Name[i] != '\0' && (G_Name[i] < 'A' || (G_Name[i] > 'Z' && G_Name[i] < 'a') || (G_Name[i] > 'z' && G_Name[i] <= '~')))
			{
				i++;j++;
			}
			if (j > 0) { cout << "商品名格式错误，返回主菜单" << endl;return false; }
			else if (j == 0);
			break;
		}//判断用户名格式是否正确
		cout << "请输入商品价格：";
		getline(cin, good.price);
		//价格带一位小数
		int k = 0;int d = 0;
		while (k < good.price.length() - 1 && (((good.price[k] >= '0') && (good.price[k] <= '9')) || good.price[k] == '.'))
		{
			k++;
			if (good.price[k] == '.')d++;
		}
		if (k != good.price.length() - 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
		else if (d != 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
		else if (good.price[good.price.length() - 2] != '.') {
			cout << "价格格式错误，返回主菜单" << endl;return false;
		}
		//商品数量检验
		char G_Number[3] = { 0 };
		cout << "请输入商品数量:";
		cin>>G_Number;
		int gg11 = getchar();
		for (int i = 0, j = 0;;) {
			for (i = 0;G_Number[i] != '\0';i++);
			if (i > 0 && i <= 2) {
				int k = 0;
				for (;G_Number[k] >= '0' && G_Number[k] <= '9';k++);
				if (k != i) { cout << "商品数量格式错误，返回主菜单" << endl;return false; }
				else break;
			}
			else {
				cout << "商品数量格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char G_info[201] = { 0 };
		cout << "请输入商品描述（数字或字母）:";
		cin>>G_info;
		int gg15 = getchar();
		/*检验描述格式*/for (int i = 0, j = 0;;) {
			for (j = 0;G_info[j] != '\0';j++);
			if (j > 0 && i <= 200) {
				for (int k = 0;(G_info[k] >= '0' && G_info[k] <= '9') || (G_info[k] >= 'a' && G_info[k] <= 'z') || (G_info[k] >= 'A' && G_info[k] <= 'Z');k++) {
					if (k != i) { cout << "描述格式错误，返回主菜单" << endl;return false; }
					else break;;
				}
			}
			else {
				cout << "描述格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char G_Seller_ID[4];
		ifstream fin("users.txt", ios::in);
		if (!fin.is_open()) {
			cout << "当前无法进行该操作" << endl;
			return false;
		}int k1 = dijihang;
		string buff;
		while (getline(fin, buff) && k1 >= 0) {
			k1--;
			if (k1 == 0) {
				buff = buff.substr(0, 4);
				strcpy(G_Seller_ID, buff.c_str());
			}
		};
		fin.close();
		char G_stage[4] = { "on" };
		char G_OnTime[11] = { 0 };
		Gettime1(G_OnTime);
		char Bid[5] = { "null" };
		fputs(title, fp);fputs("\n", fp);
		fputs(good.G_ID, fp);fputs(",", fp);
		fputs(G_Name, fp);fputs(",", fp);
		fputs(good.price.c_str(), fp);fputs(",", fp);
		fputs(G_Number, fp);fputs(",", fp);
		fputs(G_info, fp);fputs(",", fp);
		fputs(G_Seller_ID, fp);fputs(",", fp);
		fputs(G_OnTime, fp);fputs(",", fp);
		fputs(G_stage, fp);fputs(",", fp);
		fputs(Bid, fp);fputs("\n", fp);
		fclose(fp);
		cout << "上架成功，正在返回" << endl;
	}
	else {
		int x = 0;
		char line[256] = { 0 };
		while (fgets(line, 255, fp))
		{
			x++;
		}x -= 2;
		Good g;
		/*生成有序ID*/for (;x >= 0;x--) {
			g.G_ID[3] += 1;
			if (g.G_ID[3] > '9') {
				g.G_ID[3] = '0';
				g.G_ID[2] += 1;
				if (g.G_ID[2] > '9') {
					g.G_ID[2] = '0';
					g.G_ID[1] += 1;
					if (g.G_ID[1] > '9') {
						cout << "商品数量已满，无法上新";
						return false;
					}
				}
			}
		}
		fclose(fp);
		fp=fopen( "goods.txt", "at");
		char G_Name[21] = { 0 };
		cout << "请输入商品的名称：";
		cin >> G_Name;
		int g9 = getchar();
		for (int i = 0, j = 0;;) {
			//good名不超20个字符
			while (G_Name[i] != '\0')i++;
			if (i > 0 && i <= 20)i = 0;
			else {
				cout << "商品名格式错误，返回主菜单" << endl;return false;
			}
			//商品名英文字母
			while (G_Name[i] != '\0' && (G_Name[i] < 'A' || (G_Name[i] > 'Z' && G_Name[i] < 'a') || (G_Name[i] > 'z' && G_Name[i] <= '~')))
			{
				i++;j++;
			}
			if (j > 0) { cout << "商品名格式错误，返回主菜单" << endl;return false; }
			else if (j == 0);
			break;
		}//判断用户名格式是否正确
		cout << "请输入商品价格：";
		getline(cin, g.price);
		//价格带一位小数
		int k = 0;int d = 0;
		while (k < g.price.length() - 1 && (((g.price[k] >= '0') && (g.price[k] <= '9')) || g.price[k] == '.'))
		{
			k++;
			if (g.price[k] == '.')d++;
		}
		if (k != g.price.length() - 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
		else if (d != 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
		else if (g.price[g.price.length() - 2] != '.') {
			cout << "价格格式错误，返回主菜单" << endl;return false;
		}
		//商品数量检验
		char G_Number[3] = { 0 };
		cout << "请输入商品数量:";
		cin>>G_Number;
		int gg12 = getchar();
		for (int i = 0, j = 0;;) {
			for (i = 0;G_Number[i] != '\0';i++);
			if (i > 0 && i <= 2) {
				int k = 0;
				for (;G_Number[k] >= '0' && G_Number[k] <= '9';k++);
				if (k != i) { cout << "商品数量格式错误，返回主菜单" << endl;return false; }
				else break;
			}
			else {
				cout << "商品数量格式错误，返回主菜单" << endl;return false;
			}break;
		}
		char G_info[201] = { 0 };
		cout << "请输入商品描述（数字或字母）:";
		cin>>G_info;
		int gg16 = getchar();
		/*检验描述格式*/for (int i = 0, j = 0;;) {
			for (j = 0;G_info[j] != '\0';j++);
			if (j > 0 && i <= 200) {
				for (int k = 0;(G_info[k] >= '0' && G_info[k] <= '9') || (G_info[k] >= 'a' && G_info[k] <= 'z') || (G_info[k] >= 'A' && G_info[k] <= 'Z');k++) {
					if (k != i) { cout << "描述格式错误，返回主菜单" << endl;return false; }
					else break;;
				}
			}
			else {
				cout << "描述格式错误，返回主菜单" << endl;return false;
			}break;
		}

		char time[22] = { 0 };
		Gettime(time);
		char str[] = { "INSERT INTO commodity VALUES" };
		FILE* fp1=fopen( "commands.txt", "at");
		if (fp1 == NULL)
		{
			printf("当前无法进行该操作\n");
			exit(-1);
		}
		fputs(time, fp1);
		fputs(str, fp1);
		fputs("(", fp1);
		fputs(G_Name, fp1);
		fputs(",", fp1);
		fputs(g.price.c_str(), fp1);
		fputs(",", fp1);
		fputs(G_Number, fp1);
		fputs(",", fp1);
		fputs(G_info, fp1);
		fputs(")", fp1);
		fputs("\n", fp1);
		fclose(fp1);


		char G_Seller_ID[5];
		ifstream fin("users.txt", ios::in);
		if (!fin.is_open()) {
			cout << "当前无法进行该操作" << endl;
			return false;
		}int k1 = dijihang;
		string buff;
		while (getline(fin, buff) && k1 >= 0) {
			k1--;
			if (k1 == 0) {
				buff = buff.substr(0, 4);
				strcpy(G_Seller_ID, buff.c_str());
				break;
			}
		};
		fin.close();
		char G_stage[4] = { "on" };
		char G_OnTime[11];
		Gettime1(G_OnTime);
		char Bid[5] = { "null" };
		fputs(g.G_ID, fp);fputs(",", fp);
		fputs(G_Name, fp);fputs(",", fp);
		fputs(g.price.c_str(), fp);fputs(",", fp);
		fputs(G_Number, fp);fputs(",", fp);
		fputs(G_info, fp);fputs(",", fp);
		fputs(G_Seller_ID, fp);fputs(",", fp);
		fputs(G_OnTime, fp);fputs(",", fp);
		fputs(G_stage, fp);fputs(",", fp);
		fputs(Bid, fp);fputs("\n", fp);
		fclose(fp);
		cout << "上架成功，正在返回主界面" << endl;
		return true;
	}
}

/*卖家下架商品*/bool Sellers::Del_Good() {
	cout << "请输入要下架的商品ID：";
	char tgID[5];
	cin >> tgID;
	if (strlen(tgID) > 4) {
		cout << "商品ID格式错误，返回选择菜单" << endl;
		return false;
	}
	else {
		ifstream fin("goods.txt", ios::in);
		if (!fin.is_open()) {
			cout << "当前无法进行该操作" << endl;
			return false;
		}
		string gs = "off";
	T1:	cout << "确认下架吗？请输入Y/N:";
		string yorn;
		cin >> yorn;
		if (yorn.length() != 1) {
			cout << "输入错误，请重试";goto T1;
		}
		if (yorn[0] == 'Y') {
			fin.close();

			char time[22] = { 0 };
			Gettime(time);
			char str[] = { "UPDATE commodity SET 描述 = " };
			FILE* fp=fopen( "commands.txt", "at");
			if (fp == NULL)
			{
				printf("当前无法进行该操作\n");
				exit(-1);
			}
			fputs(time, fp);
			fputs("UPDATE commodity SET 商品状态 = banning WHERE 商品ID = ",fp);
			fputs(tgID, fp);
			fputs("\n", fp);
			fclose(fp);

			ifstream infile("goods.txt");
			char line[256] = { 0 };
			string temp[999];int t = 0;
			while (!infile.eof())
			{
				infile.getline(line, sizeof(line) - 1);
				temp[t] = line;
				if (strstr(line, tgID) != NULL)
				{
					int i = 0;
					for (int c = 0;c < 7;i++) {
						if (temp[t][i] == ',')c++;
					}
					string mof = temp[t];
					temp[t] = mof.substr(0, i);
					temp[t] += gs;
					temp[t] += ",null";
				}t++;
			} infile.close();
			FILE* fp1 = fopen("goods.txt", "w+");
			for (int j = 0;j < t - 1;j++) {
				fputs(temp[j].c_str(), fp1);fputs("\n", fp1);
			}fclose(fp1);
			cout << "下架成功" << endl;
		}
		else if (yorn[0] == 'N') {
			return false;
		}
		else { cout << "输入错误，请重试";goto T1; }
	}
}

/*卖家修改商品信息*/bool Sellers::Amend_Good() {
	cout << "请输入要修改的商品ID：";
	char tgID[5];
	cin >> tgID;
	if (strlen(tgID) > 4) {
		cout << "商品ID格式错误，返回选择菜单" << endl;
		return false;
	}
	else {
		cout << "请输入被修改的商品属性（1.价格 2.描述）";
		int s = 0;cin >> s;
		if (s == 1) {
			ifstream fin("goods.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			cout << "请输入被修改商品的价格";
			string g_price;
			cin >> g_price;
			//价格带一位小数
			int k = 0;int d = 0;
			while (k < g_price.length() - 1 && (((g_price[k] >= '0') && (g_price[k] <= '9')) || g_price[k] == '.'))
			{
				k++;
				if (g_price[k] == '.')d++;
			}
			if (k != g_price.length() - 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
			else if (d != 1) { cout << "价格格式错误，返回主菜单" << endl;return false; }
			else if (g_price[g_price.length() - 2] != '.') {
				cout << "价格格式错误，返回主菜单" << endl;return false;
			}
		T:	cout << "确认修改吗？请输入Y/N:";
			string yorn;
			cin >> yorn;
			if (yorn.length() != 1) {
				cout << "输入错误，请重试";goto T;
			}
			if (yorn[0] == 'Y') {
				fin.close();

				char time[22] = { 0 };
				Gettime(time);
				char str[] = { "UPDATE commodity SET 价格 = " };
				FILE* fp=fopen( "commands.txt", "at");
				if (fp == NULL)
				{
					printf("当前无法进行该操作\n");
					exit(-1);
				}
				fputs(time, fp);
				fputs(str, fp);fputs(g_price.c_str(), fp); fputs("WHERE 商品ID = ", fp);
				fputs(tgID, fp);
				fputs("\n", fp);
				fclose(fp);

				ifstream infile("goods.txt");
				char line[256] = { 0 };
				string temp[999];int t = 0;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					temp[t] = line;
					if (strstr(line, tgID) != NULL)
					{
						int i = 0;int p = 0;
						for (int c = 0;c < 2;p++) {
							if (temp[t][p] == ',')c++;
						}
						for (int c = 0;c < 3;i++) {
							if (temp[t][i] == ',')c++;
						}
						string mof = temp[t];
						temp[t] = mof.substr(0, p);
						temp[t] += g_price;
						temp[t] += mof.substr(i - 1, mof.length());
					}t++;
				} infile.close();
				FILE* fp2 = fopen("goods.txt", "w+");
				for (int j = 0;j < t - 1;j++) {
					fputs(temp[j].c_str(), fp2);fputs("\n", fp2);
				}fclose(fp2);
			}
			else if (yorn[0] == 'N') {
				return false;
			}
			else { cout << "输入错误，请重试";goto T; }
		}
		else if (s == 2) {
			ifstream fin("goods.txt", ios::in);
			if (!fin.is_open()) {
				cout << "当前无法进行该操作" << endl;
				return false;
			}
			cout << "请输入被修改商品的描述";
			string g_info;
			cin >> g_info;
			int k = 0;int d = 0;
			if (g_info.length() > 40) { cout << "描述格式错误，返回主菜单" << endl;return false;
			}
			while (k < g_info.length() - 1 && (((g_info[k] >= 'a') && (g_info[k] <= 'z')) || ((g_info[k] >= 'A') && (g_info[k] <= 'Z'))))
			{
				k++;
				if (g_info[k] == '.')d++;
			}
			if (k != g_info.length() - 1) { cout << "描述格式错误，返回主菜单" << endl;return false;
			}
		A:	cout << "确认修改吗？请输入Y/N:";
			string yorn;
			cin >> yorn;
			if (yorn.length() != 1) {
				cout << "输入错误，请重试";goto A;
			}
			if (yorn[0] == 'Y') {
				fin.close();

				char time[22] = { 0 };
				Gettime(time);
				char str[] = { "UPDATE commodity SET 描述 = " };
				FILE* fp=fopen( "commands.txt", "at");
				if (fp == NULL)
				{
					printf("当前无法进行该操作\n");
					exit(-1);
				}
				fputs(time, fp);
				fputs(str, fp);fputs(g_info.c_str(), fp); fputs("WHERE 商品ID = ", fp);
				fputs(tgID, fp);
				fputs("\n", fp);
				fclose(fp);

				ifstream infile("goods.txt");
				char line[256] = { 0 };
				string temp[999];int t = 0;
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);
					temp[t] = line;
					if (strstr(line, tgID) != NULL)
					{
						int i = 0;int p = 0;
						for (int c = 0;c < 4;p++) {
							if (temp[t][p] == ',')c++;
						}
						for (int c = 0;c < 5;i++) {
							if (temp[t][i] == ',')c++;
						}
						string mof = temp[t];
						temp[t] = mof.substr(0, p);
						temp[t] += g_info;
						temp[t] += mof.substr(i - 1, mof.length());
					}t++;
				} infile.close();
				FILE* fp3 = fopen("goods.txt", "w+");
				for (int j = 0;j < t - 1;j++) {
					fputs(temp[j].c_str(), fp3);fputs("\n", fp3);
				}fclose(fp3);
			}
			else if (yorn[0] == 'N') {
				return false;
			}
			else { cout << "输入错误，请重试";goto A; }
		}
		else { cout << "输入错误，正在返回";return false; }
	}
}

/*卖家查看已发布商品*/bool Sellers::Seller_Check_Goods() {
	char time[22] = { 0 };
	Gettime(time);
	char str[] = { "SELECT * FROM commodity" };
	FILE* fp=fopen( "commands.txt", "at");
	if (fp == NULL)
	{
		printf("当前无法进行该操作\n");
		exit(-1);
	}
	fputs(time, fp);
	fputs(str, fp);
	fputs("\n", fp);
	fclose(fp);

	ifstream fin("users.txt", ios::in);
	if (!fin.is_open()) {
		cout << "当前无法进行该操作" << endl;
		return false;
	}int k1 = dijihang;
	string buff;
	char G_Seller_ID[5] = { 0 };
	while (getline(fin, buff) && k1 >= 0) {
		k1--;
		if (k1 == 0) {
			buff = buff.substr(0, 4);
			strcpy(G_Seller_ID, buff.c_str());
		}
	}
	char line[256] = { 0 };int x = 0;
	ifstream infile("goods.txt");
	if (!infile)
	{
		cout << "当前无法进行该操作" << endl;
		return false;
	}
	while (!infile.eof())
	{
		infile.getline(line, sizeof(line) - 1);
		string temp = line;
		string temp2 = line;
		if (temp.size() == 0)break;
		int i = 0;int p = 0;
		for (int c = 0;c < 5;p++) {
			if (temp[p] == ',')c++;
		}
		for (int c = 0;c < 6;i++) {
			if (temp[i] == ',')c++;
		}
		string mof = temp;
		temp = mof.substr(p, i - 1 - p);
		if (strcmp(temp.c_str(), G_Seller_ID) == 0)
		{
			int p = 0;
			for (int c = 0;c < 8;p++) {
				if (temp2[p] == ',')c++;
			}
			cout << "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态" << endl;
			cout << temp2.substr(0, p - 1) << endl;
		}
	}infile.close();
}