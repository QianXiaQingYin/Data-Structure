#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <ctype.h>
using namespace std;

#define MIN 1e-5

float calInfix(string s);
bool calStackTopTwo(stack<float> &stk1, stack<char> &stk2);
bool calSub(float opnd1, float opnd2, char opr, float &result);
int getPriority(char op);

int main()
{
    string s;
    cin >> s;
    cout << calInfix(s);

    return 0;
}

float calInfix(string s)
{
    string operators = "+-*/";

    stack<float> stk1;
    stack<char> stk2;
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i])) //判断是否是数字
        {
            string num = "";
            while (isdigit(s[i]) || s[i] == '.') //如果下一个仍为数字或小数点，则直接拼接到字符串后边
            {
                num += s[i];
                i++;
            }
            float temp;
            sscanf(num.c_str(), "%f", &temp); //将字符串读入到临时变量中
            stk1.push(temp);
        }
        else if (s[i] == '(')
        {
            stk2.push(s[i++]);
        }
        else if (operators.find(s[i]) != string::npos)
        {
            if (stk2.size() == 0 || stk2.top() == '(' ||
                getPriority(stk2.top()) < getPriority(s[i]))
            {
                stk2.push(s[i++]);
            }
            else
            {
                if (calStackTopTwo(stk1, stk2) == -1)
                {
                    cout << "ERROR!" << endl;
                    exit(-1);
                }
            }
        }
        else if (s[i] == ')')
        {
            while (stk2.top() != '(')
            {
                if (calStackTopTwo(stk1, stk2) == -1)
                {
                    cout << "ERROR!" << endl;
                    exit(-1);
                }
            }
            stk2.pop();
            i++;
        }
    }

    while (stk2.size() != 0)
    {
        if (calStackTopTwo(stk1, stk2) == -1)
        {
            cout << "ERROR!" << endl;
            exit(-1);
        }
    }

    return stk1.top();
}

bool calStackTopTwo(stack<float> &stk1, stack<char> &stk2)
{
    float opnd1, opnd2;
    char opr;
    opnd2 = stk1.top();
    stk1.pop();
    opnd1 = stk1.top();
    stk1.pop();
    opr = stk2.top();
    stk2.pop();
    float result;
    if (calSub(opnd1, opnd2, opr, result) != -1)
    {
        stk1.push(result);
        return 0;
    }
    else
        return -1;
}

bool calSub(float opnd1, float opnd2, char opr, float &result)
{
    if (opr == '*')
        result = opnd1 * opnd2;
    else if (opr == '/')
    {
        if (opnd2 < MIN)
            return -1;
        else
            result = opnd1 / opnd2;
    }
    else if (opr == '+')
        result = opnd1 + opnd2;
    else
        result = opnd1 - opnd2;
    return 0;
}

int getPriority(char op)
{
    if (op == '-' || op == '+')
        return 0;
    else
        return 1;
}
