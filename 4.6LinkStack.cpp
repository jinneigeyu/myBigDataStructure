#include <iostream>

typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElenmType;

typedef struct StackNode
{
    SElenmType data;
    StackNode *next;
} StackNode;

typedef StackNode *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
};

//空指针为 栈底  所以是  从栈顶指向栈底
Status push(LinkStack *S, SElenmType e)
{
    StackNode *p = new StackNode();
    p->data = e;
    p->next = S->top; //将当前的栈顶 赋值给 新节点，然后将链栈的栈顶赋值给p
    S->top = p;
    S->count++;
    return OK;
}

bool EmptyStack(LinkStack *S)
{
    return S->count <= 0 ? true : false;
}

Status pop(LinkStack *S, SElenmType *e)
{
    if (EmptyStack(S))
        return ERROR;

    *e = S->top->data;
    LinkStackPtr p;
    p = S->top;
    S->top = p->next;
    delete p;
    S->count--;
    return OK;
}

Status visit(SElenmType c)
{
    std::cout << c;
    return OK;
}

Status InitStack(LinkStack *S)
{
    S = new LinkStack();
    if (nullptr != S->top)
        return ERROR;
    S->count = 0;
    S->top = nullptr;
    return OK;
}

Status DestroyStack(LinkStack *S)
{
    LinkStackPtr p, q;
    p = S->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

int main()
{
    int j;
    LinkStack s;
    int e;
    if (InitStack(&s) == OK)
        for (j = 1; j <= 10; j++)
            push(&s, j);

    DestroyStack(&s);
}