#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXSIZE 100

int calM(int m);

int main()
{
    int m;
    cin >> m;
    cout << "ans:" << calM(m);

    return 0;
}

int calM(int m)
{
    int stk[MAXSIZE];
    int top = -1;
    int ans = 1;

    while (m != 0)
    {
        stk[++top] = m;
        m /= 3;
    }

    while (top != -1)
    {
        ans = ans * stk[top--];
    }

    return ans;
}
