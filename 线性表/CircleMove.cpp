#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

/*
    将数组a中的数循环左移p位
*/

void reverse(int a[],int left,int right,int k)
{
    for(int i=left,j=right;i<left+k&&i<j;i++,j--)
        {
            swap(a[i],a[j]);
        }
}

void moveP(int a[],int n,int p)
{
    reverse(a,0,p-1,n);
    reverse(a,p,n-1,n-p);
    reverse(a,0,n-1,n);
}

int main()
{
    int a[100],n,p;
    printf("Please enter the length of array:");
    cin>>n;
    printf("the value of p:");
    cin>>p;
    printf("the value of each element:");
    for(int i=0;i<n;i++)
        cin>>a[i];
    moveP(a,n,p);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
