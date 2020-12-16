#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef char ElemType;

typedef struct node
{
    ElemType data;       //数据元素
    struct node *lchild; //指向左孩子
    struct node *rchild; //指向右孩子
} BTNode;

void CreateBTNode(BTNode *&b, char *str) //由str串创建二叉链
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL; //建立的二叉树初始时为空
    ch = str[j];
    while (ch != '\0') //str未扫描完时循环
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break; //为左结点
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break; //为右结点
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) //p指向二叉树的根结点
                b = p;
            else //已建立二叉树根结点
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DispBTNode(BTNode *b) //以广义表法输出二叉树
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}

int Nodes(BTNode *b) //求二叉树b的结点个数
{
    int num1, num2;
    if (b == NULL) //???		//树b为空
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL) //???  //*b为叶子结点
        return 1;
    else
    {
        num1 = Nodes(b->lchild);
        num2 = Nodes(b->rchild);
        return (num1 + num2 + 1);
    }
}

int LeafNodes(BTNode *b) //求二叉树b的叶子结点个数
{
    int num1, num2;
    if (b == NULL) //b树为空
        return 0;
    else if (b->lchild == NULL && b->rchild == NULL) //*b为叶子结点
        return 1;
    else
    {
        num1 = LeafNodes(b->lchild);
        num2 = LeafNodes(b->rchild);
        return (num1 + num2);
    }
}

int BTNodeDepth(BTNode *b) //求二叉树b的深度
{
    int lchilddep, rchilddep;
    if (b == NULL)
        return (0); //空树的高度为0
    else
    {
        lchilddep = BTNodeDepth(b->lchild); //求左子树的高度为lchilddep
        rchilddep = BTNodeDepth(b->rchild); //求右子树的高度为rchilddep
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

void PreOrder(BTNode *b) //先序遍历的递归算法
{
    if (b != NULL)
    {
        printf("%c", b->data); //访问根结点
        PreOrder(b->lchild);   //递归遍历左子树
        PreOrder(b->rchild);   //递归遍历右子树
    }
}

void InOrder(BTNode *b) //中序遍历的递归算法
{
    if (b != NULL)
    {
        InOrder(b->lchild);    //???	//递归遍历左子树
        printf("%c", b->data); //???	//访问根结点
        InOrder(b->rchild);    //???	//递归遍历右子树
    }
}

void PostOrder(BTNode *b) //后序遍历的递归算法
{
    if (b != NULL)
    {
        PostOrder(b->lchild);  //递归遍历左子树
        PostOrder(b->rchild);  //递归遍历右子树
        printf("%c", b->data); //访问根结点
    }
}

void TravLevel(BTNode *b) //层次遍历算法
{
    BTNode *Qu[MaxSize]; //定义循环队列
    int front, rear;     //定义队首和队尾指针
    front = rear = 0;    //置队列为空队列
    if (b != NULL)
        printf("%c ", b->data);
    rear++; //结点指针进入队列
    Qu[rear] = b;
    while (rear != front) //队列不为空
    {
        front = (front + 1) % MaxSize;
        b = Qu[front];         //队头出队列
        if (b->lchild != NULL) //输出左孩子,并入队列
        {
            printf("%c ", b->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        if (b->rchild != NULL) //输出右孩子,并入队列
        {
            printf("%c ", b->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }
    }
    printf("\n");
}

void AllPath(BTNode *b, ElemType path[], int pathlen)
{
    int i;
    if (b != NULL)
    {
        if (b->lchild == NULL && b->rchild == NULL) //???	//*b为叶子结点
        {
            printf("%c到根结点路径: %c ", b->data, b->data);
            for (i = pathlen - 1; i >= 0; i--)
                printf("%c ", path[i]);
            printf("\n");
        }
        else
        {
            path[pathlen] = b->data;           //将当前结点放入路径中
            pathlen++;                         //路径长度增1
            AllPath(b->lchild, path, pathlen); //递归扫描左子树
            AllPath(b->rchild, path, pathlen); //递归扫描右子树
            pathlen--;                         //恢复环境
        }
    }
}

int main()
{
    BTNode *b;
    ElemType path[MaxSize];
    CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf(" 二叉树b: ");
    DispBTNode(b);
    printf("\n\n");

    printf("二叉树b的结点个数: %d\n", Nodes(b));
    printf("二叉树b的叶子结点个数: %d\n", LeafNodes(b));
    printf("二叉树b的深度: %d\n", BTNodeDepth(b));
    printf("\n");

    printf("先序遍历序列: ");
    PreOrder(b);
    printf("\n");

    printf("中序遍历序列: ");
    InOrder(b);
    printf("\n");

    printf("后序遍历序列: ");
    PostOrder(b);
    printf("\n");

    printf("层次遍历序列: ");
    TravLevel(b);
    printf("\n");

    printf("叶子结点路径: \n");
    AllPath(b, path, 0);
    printf("\n");

    return 0;
}