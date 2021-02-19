#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

void CreateStack(Node *&head);
void pop(Node *&head);
void push(Node *&head);
void Show(Node *&head);

int main()
{
    Node *head;
    CreateStack(head);
    int temp = 0;
    while (true)
    {
        cout << "push:1 pop:2 " << endl;
        cin >> temp;
        if (temp == 1)
            push(head);
        else
            pop(head);
        Show(head);
    }
}

void CreateStack(Node *&head)
{
    head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
}

void pop(Node *&head)
{
    if (head->next == NULL)
    {
        cout << "pop unsuccessfully! The stack is empty!" << endl;
        return;
    }
    Node *t = head->next->next;
    free(head->next);
    head->next = t;
}

void push(Node *&head)
{
    int data;
    cout << "Data:";
    cin >> data;
    Node *top = (Node *)malloc(sizeof(Node));
    if (top == NULL)
    {
        cout << "push unsuccessfully! There is no spare memory!" << endl;
        return;
    }
    top->data = data;
    Node *temp = head->next;
    head->next = top;
    top->next = temp;
}

void Show(Node *&head)
{
    Node *t = head->next;
    cout << "Top:";
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl
         << endl;
}
