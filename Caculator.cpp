#include"Calculator.h"

int get_front(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return 3;
}
Calculator::Calculator(string line) {
	this->line = line;
	this->trans();
}
void Calculator::trans()
{                   /*将算术表达式转化为后缀表达式*/
	int a = 0, c = 0, d = 0;//a为左括弧数量 c为判断是否操作符重复 d判断小数点是否连用
	//检查表达式
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ') {
			if (i != 0 && i != line.length() - 1) {
				if (line[i - 1] == '.' || line[i + 1] == '.') {
					answer = "小数点错误";
					ex[0] = answer;
					return;
				}
			}
			if (i != line.length() - 1)
				line = line.substr(0, i) + line.substr(i + 1);
			else
				line = line.substr(0, i);
		}
	}
	int i = 0;
	for (; i < line.length(); i++) {
		if (line[i] == '-') {
			if (i == 0 || line[i - 1] == '(') {
				line = line.substr(0, i) + "0" + line.substr(i);//处理负号
				continue;
			}
		}
		if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {
			if (i == 0 || line[i - 1] == '(' || c == 1) {//运算符开头报错和连用报错
				answer = "操作符误用";
				ex.push_back(answer);
				return;
			}
			if (d > 0 && (i != 0) && line[i] == '.') {
				answer = "数字错误";
				ex.push_back(answer);
				return;
			}
			d = 0;
			c++;
			continue;
		}
		else if (line[i] == '(') {
			if (d > 0 && (i != 0) && line[i] == '.') {
				answer = "数字错误";
				ex.push_back(answer);
				return;
			}
			c = 0; d = 0;
			a++; continue;
		}
		else if (line[i] == ')') {
			if (d > 0 && (i != 0) && line[i] == '.') {
				answer = "数字错误";
				ex.push_back(answer);
				return;
			}
			c = 0; d = 0;
			a--;
			if (a < 0) {
				answer = "圆括号不匹配";
				ex.push_back(answer);
				return;
			}
			continue;
		}

		else if (line[i] == '.') {
			if (i == 0 || (line[i - 1] > '9' || line[i - 1] < '0') || d > 0) {
				answer = "小数点误用";
				ex.push_back(answer);
				return;
			}
			d++;
			c = 0;
		}
		else if (line[i] > '9' || line[i] < '0') {
			answer = "发现未识别符号";
			ex.push_back(answer);
			return;
		}
		else {
			c = 0;
		}
	}
	//变为后缀表达式
	string temp = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '(') {
			opeators.push(line[i]);
			continue;
		}
		if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') {
			if (opeators.empty() || opeators.top() == '(') {
				opeators.push(line[i]);
			}
			else {
				while (!opeators.empty() && (get_front(opeators.top()) >= get_front(line[i])) && opeators.top() != '(') {
					temp += opeators.top();
					ex.push_back(temp);
					opeators.pop();
					temp = "";
				}
				opeators.push(line[i]);
			}
		}
		if (line[i] == ')') {
			while (opeators.top() != '(')
			{
				temp += opeators.top();
				ex.push_back(temp);
				opeators.pop();
			}
			opeators.pop();
			continue;
		}
		else if (line[i] >= '0' && line[i] <= '9') {
			while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
			{ /*判定为数字*/
				temp += line[i];
				i++;
			}
			i--;
			ex.push_back(temp);
		}
		temp = "";
	}
	temp = "";
	while (!opeators.empty())
	{
		temp += opeators.top();
		ex.push_back(temp);
		opeators.pop();
		temp = "";
	}
	return;
}
string Calculator::jisuan()
{
	//报错信息输出
	if (ex[0][0] > '9' || ex[0][0] < '0')
		return ex[0];
	//进行运算
	double op1 = 0, op2 = 0, temp;
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[i][0] <= '9' && ex[i][0] >= '0') {
			temp_num.push(stof(ex[i]));
		}
		else if (ex[i] == "+") {
			op1 = temp_num.top();
			temp_num.pop();
			op2 = temp_num.top();
			temp_num.pop();
			temp = op1 + op2;
			temp_num.push(temp);
		}
		else if (ex[i] == "-") {
			op2 = temp_num.top();
			temp_num.pop();
			op1 = temp_num.top();
			temp_num.pop();
			temp = op1 - op2;
			temp_num.push(temp);
		}
		else if (ex[i] == "*") {
			op1 = temp_num.top();
			temp_num.pop();
			op2 = temp_num.top();
			temp_num.pop();
			temp = op1 * op2;
			temp_num.push(temp);
		}
		else if (ex[i] == "/") {
			op2 = temp_num.top();
			temp_num.pop();
			op1 = temp_num.top();
			temp_num.pop();
			if (op2 == 0)
				return "除数为0";//除0报错
			temp = op1 / op2;
			temp_num.push(temp);
		}
	}
	//得到一位小数
	answer = to_string(temp_num.top());
	for (int i = 0; i < answer.length(); i++)
	{
		if (answer[i] == '.') {
			if (i + 2 < answer.length()) {
				if (answer[i + 2] >= '5') {
					if (answer[i + 1] == '9') {
						answer[i + 1] = '0';
						answer[i - 1] += 1;
						for (int j = i - 1; j >= 0; j--)
						{
							if (answer[j] > '9') {
								answer[j] = answer[j] - 10;
								if (j != 0) {
									answer[j - 1] += 1;
								}
								else {
									answer = "1" + answer;
								}
							}
						}
					}
					else {
						answer[i + 1] += 1;
					}
				}
			}
			answer = answer.substr(0, i + 2);
			break;
		}
	}
	return answer;
}