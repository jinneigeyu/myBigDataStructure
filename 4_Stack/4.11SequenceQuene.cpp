#include <iostream>

typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int QElenmType;
struct SqQuene
{
    QElenmType data[MAXSIZE];
    int front; //头指针
    int rear;  //尾指针 若队列不空 指向队尾元素的下一个位置
};

Status visit(QElenmType e)
{
    printf("%d", e);
    return OK;
}

Status Init(SqQuene *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status QueneEmpty(SqQuene Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

int QueneLength(SqQuene Q)
{
    return (Q.rear - Q.front);
}

Status GetHead(SqQuene Q, QElenmType *e)
{
    if (QueneEmpty(Q))
        return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

Status EnQuene(SqQuene *Q, QElenmType e)
{
    if (Q->rear + 1 == MAXSIZE)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1);
    
    return OK;
}

Status DeQuene(SqQuene *Q, QElenmType *e)
{
    if (Q->rear == Q->front)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front++;
    return OK;
}

Status QueneTraverse(SqQuene Q)
{
    for (int i = Q.front ; i < Q.rear; i++)
    {
        printf("%d ", Q.data[i]);
    }
}

int main()
{
    SqQuene *quene;
    Init(quene);
    for (int i = 0; i < 10; i++)
    {
        EnQuene(quene, i);
    }

    QueneTraverse(*quene);
}