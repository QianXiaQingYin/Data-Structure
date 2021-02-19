#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <ctype.h>
#include <vector>
using namespace std;

/*
    中缀转前缀：
    1.从右往左依次读取表达式
    2.当前读取运算符优先级小于栈顶运算符优先级则出栈，否则入栈
    中缀转后缀：
    1.从左往右依次读取表达式
    2.当前运算符优先级小于或等于栈顶运算符优先级则出栈，否则入栈
*/

string infixToPostfix(string &s);
int getPriority(char c);
string infixToPreFix(string &s);

int main()
{
    string s, pre, post;
    cout << "the infix: ";
    cin >> s;
    pre = infixToPreFix(s);
    post = infixToPostfix(s);
    cout << "prefix: " << pre << endl;
    cout << "postfix: " << post;
    return 0;
}
string infixToPostfix(string &s)
{
    string operators = "+-*/";
    stack<char> s1;
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            ans += s[i];
            i++;
        }
        else if (s[i] == '(')
        {
            s1.push('(');
            i++;
        }
        else if (operators.find(s[i]) != string::npos)
        {
            if (s1.size() == 0 || s1.top() == '(' ||
                getPriority(s1.top()) <= getPriority(s[i]))
            {
                s1.push(s[i]);
                i++;
            }
            else
            {
                ans += s1.top();
                s1.pop();
            }
        }
        else if (s[i] == ')')
        {
            while (s1.top() != '(')
            {
                ans += s1.top();
                s1.pop();
            }
            s1.pop();
            i++;
        }
    }
    while (s1.size() != 0)
    {
        ans += s1.top();
        s1.pop();
    }

    return ans;
}

int getPriority(char c)
{
    if (c == '+' || c == '-')
        return 0;
    else
        return 1;
}

string infixToPreFix(string &s)
{
    string operators = "+-*/";
    stack<char> s1;
    string ans = "";
    int i = s.length() - 1;
    while (i >= 0)
    {
        if (isdigit(s[i]))
        {
            ans = s[i] + ans;
            i--;
        }
        else if (s[i] == ')')
        {
            s1.push(')');
            i--;
        }
        else if (operators.find(s[i]) != string::npos)
        {
            if (s1.size() == 0 || s1.top() == ')' ||
                getPriority(s1.top()) < getPriority(s[i]))
            {
                s1.push(s[i]);
                i--;
            }
            else
            {
                ans = s1.top() + ans;
                s1.pop();
            }
        }
        else if (s[i] == '(')
        {
            while (s1.top() != ')')
            {
                ans = s1.top() + ans;
                s1.pop();
            }
            s1.pop();
            i--;
        }
    }

    while (s1.size() != 0)
    {
        ans = s1.top() + ans;
        s1.pop();
    }

    return ans;
}
