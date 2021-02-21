#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXSIZE 100

bool parenthesisMatched(char *str);
int isSameClass(char left, char right);

int main()
{
    char str[MAXSIZE];
    gets(str);
    if (parenthesisMatched(str))
        cout << "MATCHED!";
    else
        cout << "NOT MATCHED!";
    return 0;
}

bool parenthesisMatched(char *str)
{
    char stk[MAXSIZE];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            stk[++top] = str[i];
        else if (!isSameClass(stk[top--], str[i]))
            return false;
    }
    if (top != -1)
        return false;
    else
        return true;
}

int isSameClass(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}
