#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


typedef struct queue{
   int elems[SIZE];
   int front;
   int rear;

}que;

void init(que *ptr_que)
{
  ptr_que->front=-1;
  ptr_que->rear=-1;

}
int isempty(que *ptr_que)
{
   if((ptr_que->front==-1) && (ptr_que->rear==-1)){
   return 1;
   }
   else {
   return 0;
   }
}
int isfull(que *ptr_que)
{
   if((ptr_que->rear+1)%SIZE==(ptr_que->front)){
   return 1;
   }
   else {
   return 0;
   }
}
void clearque(que *ptr_que){

 ptr_que->front=-1;
 ptr_que->rear=-1;
}
int enque(int elem,que *ptr_que){

  if((ptr_que->rear+1)%SIZE==(ptr_que->front))
   return 0;
  else if((ptr_que->front==-1) && (ptr_que->rear==-1))
    ptr_que->front=  ptr_que->rear= 0;
  else
    ptr_que->rear=(ptr_que->rear+1)%SIZE;
  ptr_que->elems[ptr_que->rear]=elem;
  return 1;
}
int deque( int *ptr_elem ,que *ptr_que)
{
  if((ptr_que->front==-1) && (ptr_que->rear==-1))
    return 0;
  *ptr_elem=ptr_que->elems[ptr_que->front];
  if (ptr_que->front==ptr_que->rear)
    ptr_que->front=ptr_que->rear=-1;
  else
    ptr_que->front=(ptr_que->front+1)%SIZE;
   return 1;
}
int quesize(que *ptr_que){

    if((ptr_que->front==-1) && (ptr_que->rear==-1))
    return 0;
    else if(ptr_que->front < ptr_que->rear)
    return (ptr_que->rear-ptr_que-> front +1);
    else if(ptr_que->front > ptr_que->rear)
    return ((SIZE-ptr_que->front)+(ptr_que->rear+1));
    else
    return 1;

}
void testsize(que *ptr_que)
{
    if(isfull(ptr_que))
        printf("is full");
    else if(isempty(ptr_que))
        printf("is empty");
    else
        printf("queue size %i",quesize(ptr_que));
}
int main()
{
    que quee;
    que *ptr_que=&quee;

    int elem=0;
    int *ptr_elem=&elem;

    int x=0,temp=0;

    init(ptr_que);
    testsize(ptr_que);
    printf("plz enter\n");

    for(x=0;x<SIZE;x++)
    {
    scanf("%i",&temp);
    enque(temp,ptr_que);
    printf("\n that %i\n",temp);
    }

    printf("the que");
    while (!isempty(ptr_que)) {
        deque(ptr_elem, ptr_que);
        printf("\n elem %i", *ptr_elem);
        printf(" size %i\n", quesize(ptr_que));
    }


    return 0;
}
