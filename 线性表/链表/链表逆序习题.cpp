#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

/*
    有一个线性表，采用带头结点的单链表L来存储。设计一个算法将其逆置。
    要求不能建立新头结点，能通过表中已有结点的重新组合来完成。
*/

typedef struct Node
{
    int data;
    Node* next;
}Node;

void ReverseLink(Node* &head);
void CreateLink(Node* &head,int length);
void TraverseLink(Node* &head);

int main()
{
    int length;
    cin>>length;
    Node* head;
    CreateLink(head,length);
    ReverseLink(head);
    TraverseLink(head);
    return 0;
}

void CreateLink(Node* &head,int length)
{
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->data=0;
    Node* r=head;
    for(int i=0;i<length;i++)
    {
        Node* p=(Node*)malloc(sizeof(Node));
        cin>>p->data;
        p->next=r->next;
        r->next=p;
        r=p;
    }
}

void ReverseLink(Node* &head)
{
   Node* p=head->next;
   Node* q=p;
   head->next=NULL;
   while (p!=NULL)
   {
       q=p->next;
       p->next=head->next;
       head->next=p;
       p=q;
   }
}

void TraverseLink(Node* &head)
{
    Node* p=head->next;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
