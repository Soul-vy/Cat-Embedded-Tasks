#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
  char *arr;
  int top;
  int capacity;
}stack;

void init(stack *ptr_stack)
{
  ptr_stack->top=-1;
  ptr_stack->arr =(char*)malloc(sizeof(char));
  ptr_stack->capacity=1;
   if (!ptr_stack->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void inc_size(stack *ptr_stack)
{
   ptr_stack->capacity++;
    char *temp = (char*)realloc(ptr_stack->arr, ptr_stack->capacity * sizeof(char));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    ptr_stack->arr = temp;
    printf("Stack increased to %d\n", ptr_stack->capacity);
}

int isfull(stack *ptr_stack)
{
    if (ptr_stack->top==ptr_stack->capacity-1)
        return 1;
    else
        return 0;
}

int isempty(stack *ptr_stack)
{
    if (ptr_stack->top==-1)
        return 1;
    else
        return 0;
}

int push(char element,stack *ptr_stack)
{
    if (ptr_stack->top==ptr_stack->capacity-1)
    return 0;
    inc_size(ptr_stack);
    ptr_stack->top++;
    ptr_stack->arr[ptr_stack->top] = element;
    return 1;
}

int pop(char *ptr_ele,stack *ptr_stack)
{
    if (ptr_stack->top==-1)
        return 0;
     *ptr_ele=ptr_stack->arr[ptr_stack->top];
     ptr_stack->top--;
    return 1;
}

void clear_stack(stack *ptr_stack)
{
  free(ptr_stack->arr);
    ptr_stack->arr = NULL;
    ptr_stack->top = -1;
    ptr_stack->capacity = 0;
}

int stack_size(stack *ptr_stack) {
    return ptr_stack->top + 1;
}


int ismatch (char ele,char exp)
{
    if ( (ele=='{' && exp=='}') || (ele=='[' && exp==']') || (ele=='(' && exp==')') )
    return 1;
    else
    return 0;
}

int isbalance(char exp[])
{
  int x=0;
  char ele='\0';
  stack s;
  stack *ptr_stack=&s;
  init(ptr_stack);
  for (x=0;x<strlen(exp);x++)
  {
   if (exp[x]=='{' || exp[x]=='(' || exp[x]=='[')
   push(exp[x],ptr_stack);
   else
   {
    if (exp[x]=='}'|| exp[x]==')' || exp[x]==']')
    {
    if (isempty(ptr_stack))
    return 0;
    else
    {
     pop(&ele,ptr_stack);
     if (!ismatch(ele,exp[x]))
     return 0;
    }
    }
   }
  }
  if (isempty(ptr_stack))
    return 1;
  else
    return 0;
}

int main()
{
    stack s;
    stack *ptr_stack=&s;

    char element;
    char *ptr_ele=&element;

    int i=1,x=0;
    char ch;
    char word[30]={0};
    init(ptr_stack);

    printf("what operation you want reverse or {} balancing\n");
    printf("if reverse -> 0 and if {} -> 1\n");
    scanf("%i",&x);

    switch (x)
    {

    case 0:
    printf("the reverse\n\n");
    char take=0;
    while(i!=0)
    {
      scanf("%*c");    // to cancel the skip of the scanf
      printf("what is the new char\n");
      scanf("%c",&take);
      push(take,ptr_stack);
      printf("if you end write 0\n");
      scanf("%i",&i);
    }

    if (isfull(ptr_stack))
        printf("\n stack is full");
    else if (isempty(ptr_stack))
        printf("\n stack is empty");
    else
        printf("\n stack size -> %i",stack_size(ptr_stack));

    while(1)
    {
     pop(ptr_ele,ptr_stack);
     printf("\n element -> %c",*ptr_ele);
     if (stack_size(ptr_stack)==0)
        break;
    }
    break;
    case 1:
    printf("give me the expression\n");
    scanf("%*c");
    printf("Give me the expression:\n");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';
     if(isbalance(word))
     printf("\n is balanced ");
     else
     printf("\n is not balanced");

    }

    return 0;
}
