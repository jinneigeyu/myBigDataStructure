#define MAXSIZE 20

typedef  int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef struct 
{
    int top;//  stack top pointer
    SElemType data[MAXSIZE];
} QqStack;

/*压栈 O1*/
Status push(QqStack* S,SElemType e)
{
    if(S->top==MAXSIZE-1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}
/*弹栈  O1*/
Status pop(QqStack* S,SElemType* e)
{
    if(S->top==0){
        return ERROR;
    }
    *e=S->data[S->top];
    S->top--;

    return OK;
}

