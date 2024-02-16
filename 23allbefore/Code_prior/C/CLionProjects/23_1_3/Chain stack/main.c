#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct lineStack
{
    int data;
    struct lineStack* next;
}lineStack;
lineStack *pop(lineStack* stack);
lineStack *push(lineStack* stack,int a);

int main()
{
    lineStack* stack;
    stack=NULL;
    stack=push(stack,1);
    stack=push(stack,2);
    stack=push(stack,3);
    stack=push(stack,4);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}
lineStack *push(lineStack* stack,int a)
{
    lineStack * line=(lineStack*) malloc(sizeof (lineStack));
    if(!line){ printf("��ʼ��ʧ��\n");exit(0);}
    line->next=NULL;
    line->data=a;
    line->next=stack;
    stack=line;
    return stack;
}
lineStack *pop(lineStack* stack)
{
    if(stack)
    {
        lineStack * p=stack;
        printf("��ջԪ��Ϊ%d\n",p->data);
        stack=stack->next;
        if(stack){printf("�µ�ջ��Ԫ��Ϊ%d\n",stack->data);}
        else printf("�ѿ�ջ\n");
    }
    else {printf("ջ�ѿ�\n");}
    return stack;
}
