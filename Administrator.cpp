#define _CRT_SECURE_NO_WARNINGS
#include"Administrator.h"
  /*管理员登录*/ bool Administrator::Admin_Login() {
	char temp_name[100] = { 0 };
	char temp_code[100] = { 0 };
	int num = 0;
	char s_name[6] = { 0 };
	char s_code[7] = { 0 };
	cout << "请输入管理员名称：";
	cin >> temp_name;
	int gg=getchar();
	for (int i = 0;i < 100;i++) {
		if(i<=5)
			s_name[i] = temp_name[i];
		if (temp_name[i] == '\0') { num = i;break; }
	 }
	char* q = a_name;char* p = s_name;
	if (num != 5) {
		cout << "名称错误，登陆失败，返回主菜单" << endl;
		return false;
	}
	else {
		int i = strcmp(q, p);
		if (i == 0);
		else {
			cout << "名称错误，登陆失败，返回主菜单" << endl;
			return false;
		}
	}
	num = 0;
	cout << "请输入您的密码: ";
	cin>>temp_code;
	int gg4 = getchar();
	for (int i = 0;i < 100;i++) {
		if (i <= 6)
			s_code[i] = temp_code[i];
		if (temp_code[i] == '\0') { num = i;break; }
	}
	char* u = a_code;char* v = s_code;
	if (num != 6) {
		cout << "密码错误，登陆失败，返回主菜单" << endl;
		return false;
	}
	else {
		int i = strcmp(u, v);
		if (i == 0) { 
			cout << "登陆成功" << endl;
				Admininterface(); }
		else 
		{
			cout << "密码错误，登陆失败，返回主菜单" << endl;
			return false;
		};
	}
}

  /*管理员登录界面*/bool Administrator::Admininterface() {
	  cout << "=================================================================================" << endl
		  << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看订单 5.查看用户 6.封禁用户 7.管理员注销" << endl
		  << "=================================================================================" << endl;
	  cout << "请输入指令:";
	  string order;
  L: cin >> order;
	  switch (order[0]) {
	 /*查看所有商品*/ case '1': {
		  char time[22] = { 0 };
		  Gettime(time);
		  char str[] = { "SELECT * FROM commodity" };
		  FILE* fp= fopen( "commands.txt", "at");
		  if (fp == NULL)
		  {
			  printf("当前无法进行该操作\n");
			  exit(-1);
		  }
		  fputs(time, fp);
		  fputs(str, fp);
		  fputs("\n", fp);
		  fclose(fp);
		  Check_Goods();
	  };break;
	  /*搜索商品*/case '2': {
		  char g_name[21] = { 0 };
		  cout << "请输入商品名称：";
		  int n =getchar();
		  cin >> g_name;
		  int gg1 = getchar();
		  char str[] = { "SELECT * FROM commodity WHERE 名称 CONTAINS " };
		  char time[22] = { 0 };
		  Gettime(time);
		  FILE* fp=fopen( "commands.txt", "at");
		  if (fp == NULL)
		  {
			  printf("当前无法进行该操作\n");
			  exit(-1);
		  }
		  fputs(time, fp);
		  fputs(str, fp);
		  fputs(g_name, fp);
		  fputs("\n", fp);
		  fclose(fp);
		  Search_Goods();
		 // return 1;
	  }break;
	  /*下架商品*/case '3': {
		    char g_id[5] = { 0 };
			cout << "请输入要下架的商品ID：";
			int n = getchar();
			cin >> g_id;
			int gg2 = getchar();
			cout << "确认要下架该商品吗？";
			char str[] = { "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = " };
			char time[22] = { 0 };
			Gettime(time);
			FILE* fp=fopen( "commands.txt", "at");
			if (fp == NULL)
			{
				printf("当前无法进行该操作\n");
				exit(-1);
			}
			fputs(time, fp);
			fputs(str, fp);
			fputs(g_id, fp);
			fputs("\n", fp);
			fclose(fp);
			ItemDownshelf();
		//	return 1;
	  } break;
	  /*查看订单*/case '4': {
		  char str[] = { "SELECT * FROM order" };
		  char time[22] = { 0 };
		  Gettime(time);
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
		  Check_orders();
	  } break;
	  /*查看用户*/case '5': {
		  char str[] = { "SELECT * FROM user" };
		  char time[22] = { 0 };
		  Gettime(time);
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
		  Check_Users();
		  Check_Users();
	  } break;
	  /*封禁用户*/case '6': {
		  char u_id[5] = { 0 };
		  cout << "请输入要封禁的用户ID：";
		  int n = getchar();
		  cin >> u_id;
		  int gg3 = getchar();
		  cout << "确认要封禁该用户吗？" << endl;;
		  char str[] = { "UPDATE commodity SET 商品状态 = 已下架 WHERE 卖家ID = " };
		  char str1[] = { "UPDATE user SET 用户状态 = 封禁 WHERE 用户ID = " };
		  char time[22] = { 0 };
		  Gettime(time);
		  FILE* fp=fopen( "commands.txt", "at");
		  if (fp == NULL)
		  {
			  printf("当前无法进行该操作\n");
			  Admininterface();
			  exit(-1);
		  }
		  fputs(time, fp);
		  fputs(str, fp);
		  fputs(u_id, fp);
		  fputs("\n", fp);
		  fputs(time, fp);
		  fputs(str1, fp);
		  fputs(u_id, fp);
		  fputs("\n", fp);
		  fclose(fp);
		  Ban_Users();
		  ItemDownshelf();
	  } break;
	  /*管理员注销*/case '7': {
		  return false;
	  }break;
	  default:cout << "指令错误，请重新输入" << endl;
		  getline(cin, order);
		  goto L;break;
	  }
  }

  /*查看全部商品*/void Administrator::Check_Goods(){
	  ifstream fin("goods.txt", ios::in);
	  if (!fin.is_open()) {
		  cout << "当前无法进行该操作" << endl;
		  Admininterface();
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
	  Admininterface();
  }

  /*搜索商品*/bool Administrator::Search_Goods() {
	  char good_name[100];
	  int num = 0;
	  cout << "请输入商品名称：";
	  cin >> good_name;
	  int gg99 = getchar();
	  if (strlen(good_name) > 20) {
		  cout << "商品名称错误，返回主菜单" << endl;
		  Admininterface();
	  }
	  else {
		  char line[256] = { 0 };int x = 0;
		  ifstream infile("goods.txt");
		  if (!infile)
		  {
			  cout << "当前无法进行该操作" << endl;
			  Admininterface();
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
	  }Admininterface();return true;
  }

  /*下架商品*/bool Administrator::ItemDownshelf(){
	  FILE* fp = fopen("goods.txt", "r+");
	  if (fp == NULL) {
		  cout << "当前无法进行该操作" << endl;
		  Admininterface();
	  }
	  fclose(fp);
	  char tempID[5];
	  cout << "请再次输入要下架的商品ID：";
	  cin >> tempID;
	  if (strlen(tempID) != 4) {
		  cout << "格式错误，返回主菜单" << endl;
		  Admininterface();return false;
	  }
	  else {
		  char line[256] = { 0 };
		  ifstream infile("goods.txt");
		  if (!infile)
		  {
			  cout << "当前无法进行该操作" << endl;
			  Admininterface();return false;
		  }
		  while (!infile.eof())
		  {
			  infile.getline(line, sizeof(line) - 1);
			  if (strstr(line, tempID) != NULL)
			  {
				  cout << "***********************************************************" << endl;
				  string temp = line;
				  int p = 0;
				  for (int c = 0;c < 8;p++) {
					  if (temp[p] == ',')c++;
				  }
				  cout << temp.substr(0, p - 1) << endl;
				  cout << "***********************************************************" << endl;				
			  }
		  }
		  infile.close();
	  }
	  cout << "确认下架吗？请输入Y/N:";
	  string yorn;
  T:  cin >> yorn;
	  if (yorn.length() != 1) {
		  cout << "输入错误，请重试";goto T;
	  }
	  if (yorn[0] == 'Y') {
		  char buffer[] = { "off" };
		  ifstream infile("goods.txt");
		  char line[256] = { 0 };
		  string temp[999];int t = 0;
		  while (!infile.eof())
		  {
			  infile.getline(line, sizeof(line) - 1);
			  temp[t] = line;
			  if (strstr(line, tempID) != NULL)
			  {
				  int i = 0;
				  for (int c = 0;c < 7;i++) {
					  if (temp[t][i] == ',')c++;
				  }
				  temp[t] = temp[t].substr(0, i);
				  temp[t] += buffer;temp[t]+= ",null";
			  }t++;
		  } infile.close();
		  FILE* fp = fopen("goods.txt", "w+");
		  for (int j = 0;j < t - 1;j++) {
			  fputs(temp[j].c_str(), fp);fputs("\n", fp);
		  }fclose(fp);
	  }
	  else if (yorn[0] == 'N') {
		  Admininterface();
		  return false;
	  }
	  Admininterface();
	  return true;
  }

  /*查看订单*/void Administrator::Check_orders() {
	  ifstream fin("order.txt", ios::in);
	  if (!fin.is_open()) {
		  cout << "当前无法进行该操作" << endl;
		  Admininterface();
	  }
	  string buff;
	  while (getline(fin, buff)) {
		  cout << buff << endl;
	  }
	  fin.close();
	  Admininterface();
  }

  /*查看用户*/void Administrator::Check_Users() {
	  ifstream fin("users.txt", ios::in );
	  if (!fin.is_open()) {
		  cout << "当前无法进行该操作" << endl;
		  Admininterface();
	  }
	  string buff;
	  while (getline(fin, buff)) {
		  cout << buff << endl;
	  }fin.close();
	  Admininterface();
  }

  /*封禁用户*/bool Administrator::Ban_Users() {
	  FILE* fp = fopen("users.txt", "r+");
	  if (fp == NULL) {
		  cout << "当前无法进行该操作" << endl;
		  Admininterface();
	  }
	  fclose(fp);
	  char tempID[5];
	  cout << "请再次输入要封禁的用户ID：";
	  cin >> tempID;
	  if (strlen(tempID) != 4) {
		  cout << "格式错误，返回主菜单" << endl;
		  Admininterface();return false;
	  }
	  else {
		  char line[256] = { 0 };
		  ifstream infile("users.txt");
		  if (!infile)
		  {
			  cout << "当前无法进行该操作" << endl;
			  Admininterface();return false;
		  }
		  while (!infile.eof())
		  {
			  infile.getline(line, sizeof(line) - 1);
			  if (strstr(line, tempID) != NULL)
			  {
				  cout << "***********************************************************"<<endl;
				  cout << "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态" << endl;
				  cout << line<<endl;
				  cout << "***********************************************************" << endl;
			  }
		  }
		  infile.close();
	  }
	  cout << "确认封禁吗？请输入Y/N:";
		  string yorn;
		T:  cin >> yorn;
		  if (yorn.length() != 1) {
			  cout << "输入错误，请重试";goto T;
		  }
		  if (yorn[0] == 'Y') {
			  char buffer[] = { "banning" };
			  ifstream infile("users.txt");
			  char line[256] = { 0 };
			  string temp[999];int t = 0;
			  while (!infile.eof())
			  {
				  infile.getline(line, sizeof(line) - 1);
				  temp[t] = line;
				  if (strstr(line, tempID) != NULL)
				  {
					  int i = 0;
					  for (int c = 0;c < 6;i++) {
						  if (temp[t][i] == ',')c++;
					  }
					  temp[t] = temp[t].substr(0, i);
					  temp[t] += buffer;
				  }t++;
			  } infile.close();
			  FILE* fp = fopen("users.txt", "w+");
			  for (int j = 0;j < t-1;j++) {
				  fputs(temp[j].c_str(), fp);fputs("\n", fp);
			  }fclose(fp);
		  }
		  else if (yorn[0] == 'N') {
			  Admininterface();
			  return false;
		  }
		  else{ cout << "输入错误，请重试";goto T; }
		  Admininterface();
	  return true;
  }