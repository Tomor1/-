#pragma once
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <string.h>
#include<string>
#include<vector>
using namespace std;
class Calculator {
public:
	string jisuan();
	Calculator(string line);
private:
	void trans();
	string line;
	vector<string> ex; /*存储后缀表达式*/
	stack<char> opeators;/*符号栈*/
	stack<double>temp_num;//未使用的操作数
	string answer;/*返回值*/
};
