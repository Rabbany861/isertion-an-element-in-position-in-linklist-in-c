
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
struct Node*createNode(int value);
struct Node*insertion(struct Node*head, int position,int data)
{
    if(position<1)return head;
    if(position==1)
    {
        struct Node*newNode=createNode(data);
        newNode->next=head;
        return newNode;
    }
    struct Node*curr=head;
    for(int i=1;i<position-1&&curr!=NULL;i++)
    {
        curr=curr->next;
    }
    if(curr==NULL)return head;
    struct Node*newNode=createNode(data);
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
};
void printList(struct Node*head)
{
    struct Node*curr=head;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
struct Node*createNode(int value)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
int main()
{
    struct Node*head=createNode(1);
   head->next=createNode(2);
   head->next->next=createNode(3);
   head->next->next->next=createNode(4);
   int data=12;
   int position=3;
    head =insertion(head,position,data);
   printList(head);
}

