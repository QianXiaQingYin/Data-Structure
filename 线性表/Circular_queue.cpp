#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 5

typedef struct Queue
{
    int data[MAXN] = {0};
    int front = 0, rear = 0;
} Queue;

void add(Queue &q);
int del(Queue &q);
void TraverseQueue(Queue &q);

int main()
{
    Queue q;
    int temp = 0;
    int d;
    while (true)
    {
        cout << endl
             << "add:1 del:2 exit:3" << endl;
        cin >> temp;
        switch (temp)
        {
        case 1:
            add(q);
            TraverseQueue(q);
            break;
        case 2:
            d = del(q);
            if (d != -1)
                cout << "You deleted " << d << endl;
            TraverseQueue(q);
            break;
        default:
            exit(-1);
            break;
        }
    }
}

void add(Queue &q)
{
    int tem;
    cout << "Data:";
    cin >> tem;
    if ((q.rear + 1) % MAXN == q.front)
    {
        cout << "add unsuccessfully! The queue is full." << endl;
        return;
    }
    q.rear = (q.rear + 1) % MAXN;
    q.data[q.rear] = tem;
}

int del(Queue &q)
{
    if (q.rear == q.front)
    {
        cout << "delete unsuccessfully! The queue is empty!" << endl;
        return -1;
    }
    return q.data[++q.front];
}

void TraverseQueue(Queue &q)
{
    int p = q.front;
    while (p != q.rear)
    {
        cout << q.data[++p] << " ";
    }
    cout << endl;
}
