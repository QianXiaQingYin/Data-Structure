#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

void CreateLink(Node *&head, int length);
void TraverseLink(Node *&head);
void MergePositive(Node *A, Node *B, Node *&C);

int main()
{
    Node *p1, *p2, *p3;
    CreateLink(p1, 5);
    CreateLink(p2, 5);
    MergeNegative(p1, p2, p3);
    TraverseLink(p3);

    return 0;
}

void CreateLink(Node *&head, int length)
{
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
    Node *r = head;
    for (int i = 0; i < length; i++)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        cin >> p->data;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

void TraverseLink(Node *&head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void MergePositive(Node *A, Node *B, Node *&C)
{
    printf("...");
    Node *p1 = A->next;
    Node *p2 = B->next;
    Node *r = A;
    C = A;
    free(B);
    r->next = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        printf("...");
        if (p1->data <= p2->data)
        {
            r->next = p1;
            p1 = p1->next;
            r = r->next;
            r->next = NULL;
        }
        else
        {
            r->next = p2;
            p2 = p2->next;
            r = r->next;
            r->next = NULL;
        }
    }
    if (p1 != NULL)
        r->next = p1;
    if (p2 != NULL)
        r->next = p2;
}

void MergeNegative(Node *A, Node *B, Node *&C)
{
    Node *p1 = A->next;
    Node *p2 = B->next;
    Node *r;
    C = A;
    A->next = NULL;
    free(B);

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            r = C->next;
            C->next = p1;
            p1 = p1->next;
            C->next->next = r;
        }
        else
        {
            r = C->next;
            C->next = p2;
            p2 = p2->next;
            C->next->next = r;
        }
    }

    while (p1 != NULL)
    {
        r = p1;
        p1 = p1->next;
        r->next = C->next;
        C->next = r;
    }

    while (p2 != NULL)
    {
        r = p2;
        p2 = p2->next;
        r->next = C->next;
        C->next = r;
    }
}
