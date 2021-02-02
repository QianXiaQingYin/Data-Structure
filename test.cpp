#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct Node
{
    int data;
    Node* next;
}Node;

void CreateLinkR(Node* &head);
void CreateLinkH5(Node* &head);
void TraverseLink(Node* &head);

int main()
{
    printf("Please enter the length of link that you want to create:");
    Node* headR;
    CreateLinkR(headR);
    TraverseLink(headR);

    printf("Please enter the length of link that you want to create:");
    Node* headH;
    CreateLinkH(headH);
    TraverseLink(headH);
    return 0;
}


void CreateLinkR(Node* &head)
{
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->data=0;
    Node* p,*r;
    r=head;
    int n;        //the length of link
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        cin>>p->data;
        p->next=r->next;
        r->next=p;
        r=p;
    }
}

void CreateLinkH(Node* &head)
{
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->data=0;
    Node *p; 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        cin>>p->data;
        p->next=head->next;
        head->next=p;
    }
}

void TraverseLink(Node* &head)
{
    Node* p=head->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}