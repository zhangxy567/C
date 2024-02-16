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
    if(!line){ printf("初始化失败\n");exit(0);}
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
        printf("出栈元素为%d\n",p->data);
        stack=stack->next;
        if(stack){printf("新的栈顶元素为%d\n",stack->data);}
        else printf("已空栈\n");
    }
    else {printf("栈已空\n");}
    return stack;
}
