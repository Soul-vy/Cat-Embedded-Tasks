#include <stdio.h>
#include <stdlib.h>

typedef struct node{

int element;
struct node *next;

}Node;


Node* Append (Node *head,int element){
Node *new_node=NULL;

new_node=(Node* )malloc(sizeof (Node));

if(new_node==NULL){

    return NULL;
}

new_node->element=element;
new_node->next=NULL;

if(head !=NULL){
 Node *temp=head;

 while(temp->next !=NULL){

  temp=temp->next;
 }
 temp->next=new_node;
}
return new_node;
}

int Length (Node *head){

int len=1;

if (head==NULL){

    return 0;
}

Node *temp=head;

while(temp->next !=NULL){
   len++;
   temp=temp->next;
}

return len;
}

int Get_element(Node *head,int node_number,int *element){

if(head==NULL){
    return 0;
}

if((node_number>Length(head))||(node_number<1)){

    return -1;
}
Node *temp=head;
int x=1;

while(x<node_number){

  temp=temp->next;
  x++;
}

*element =temp->element;

return 1;
}

Node* Delete_First_Node(Node *head){

if(head==NULL){

    return 0;
}

if(Length(head==1)){

free(head);
return NULL;
}
else {

Node *second_node;
second_node=head->next;
free(head);
return second_node;
}

}

int Delete_Node(Node *head,int node_number){

if((head==NULL)){

    return 0;
}

if((node_number>Length(head))||(node_number<2)){

    return -1;
}

Node *prev=head,*current;
int x=1;

while(x<node_number-1){

    prev=prev->next;
    x++;
}

current=prev->next;
prev->next=current->next;
free(current);

return 1;
}

Node* Insert_Frist(Node *head,int element){

if(head==NULL){
    return NULL;
}

Node *first_node;

first_node =(Node*)malloc(sizeof(Node));

if(first_node==NULL){

    return head;
}

first_node->element=element;
first_node->next=head;

head=first_node;

return head;
}

int Insert_After(Node *head,int node_number,int element){

if((head==NULL)){

    return 0;
}

if((node_number>Length(head))||(node_number<1)){

    return -1;
}

Node *prev=head,*current;

int x=1;

current=(Node* )malloc(sizeof(Node));

if(current==NULL){

    return 0;
}

while(x<node_number){

    prev=prev->next;
    x++;
}

current->element=element;
current->next=prev->next;

prev->next=current;

return 1;
}



int main()
{
    Node *ptr_head=NULL;
    int len,x;
    int element;
    int *ptr_element=&element;

    ptr_head=Append(ptr_head,1);
    Append(ptr_head,4);
    Append(ptr_head,5);
    Append(ptr_head,6);
    Append(ptr_head,33);
    Append(ptr_head,22);

    len =Length(ptr_head);
    for(x=1;x<=len;++x){

     Get_element(ptr_head,x,ptr_element);
      printf("\n &d --> %d",x,*ptr_element);
    }
    printf("\n______");
    ptr_head =Delete_First_Node(ptr_head);

    len=Length(ptr_head);

    for(x=1;x<=len;++x){

      Get_element(ptr_head,x,ptr_element);
      printf("\n &d --> %d",x,*ptr_element);
    }
    printf("\n______");
    Delete_Node(ptr_head,3);
    len=Length(ptr_head);

    for(x=1;x<=len;++x){

      Get_element(ptr_head,x,ptr_element);
      printf("\n &d --> %d",x,*ptr_element);
    }
     printf("\n______");
    ptr_head=Insert_Frist(ptr_head,20);
    len=Length(ptr_head);
    for(x=1;x<=len;++x){

      Get_element(ptr_head,x,ptr_element);
      printf("\n &d --> %d",x,*ptr_element);
    }
    printf("\n______");
    Insert_After(ptr_head,3,100);
    len=Length(ptr_head);
    for(x=1;x<=len;++x){

      Get_element(ptr_head,x,ptr_element);
      printf("\n &d --> %d",x,*ptr_element);
    }

    return 0;
}
