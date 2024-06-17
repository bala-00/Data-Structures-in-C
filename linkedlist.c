#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*head,*temp,*newnode,*prev,*del;
void create();
void disp();
void insertf();
void insertb();
void inserta();
void deletef();
void deleteb();
void deletea();
void create()
{
int cho=1;
head=NULL;
while(cho)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->next=0;
if(head==0)
{
head=newnode;
temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
printf("do you want to continue(1/0)\n");
scanf("%d",&cho);
}
disp();
}
void disp()
{
printf("list:");
temp =head;
while(temp!=0)
{
printf("\t%d",temp->data);
temp=temp->next;
}
printf("\n");
}
void insertf()
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->next=head;
head=newnode;
disp();
}
void insertb()
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->next=0;
temp=head;
while(temp->next!=0)
{
temp=temp->next;
}
temp->next=newnode;
disp();
}
void inserta()
{
int key;
printf("enter key:");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
temp=temp->next;
}
if(temp->next==0)
{
printf("no such element");
}
else
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->next=temp->next;
temp->next=newnode;
disp();
}
}
void deletef()
{
if (head==0)
{
printf("empty list");
}
else
{
printf("deleted node:%d\n",head->data);
del=head;
head=head->next;
free(head);
disp();
}
}
void deleteb()
{
temp=head;
while(temp->next!=0)
{
prev=temp;
temp=temp->next;
}
del=temp;
printf("deleted node:%d\n",temp->data);
prev->next=0;
free(del);
disp();
}
void deletep()
{
int key;
printf("enter key to delete:");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
prev=temp;
temp=temp->next;
}
if(temp->next==0)
{
printf("key not found");
}
else
{
printf("deleted node:%d\n",temp->data);
del=temp;
prev->next=temp->next;
}
free(del);
disp();
}
void main()
{
int z;
printf("create list:\n");
create();
int ch=1;
while(ch)
{
printf("\nEnter:\n1.Display\n2.Insert at beginning\n3.Insert at 
end\n4.Insert at specified position\n5.Delete from beginning\n\
6.Delete from end\n7.Delete specidied data\n8.exit\nEnter your choice: ");
scanf("%d",&z);
switch(z)
{
case 1:
disp();
break;
case 2:
insertf();
break;
case 3:
insertb();
break;
case 4:
inserta();
break;
case 5:
deletef();
break;
case 6:
deleteb();
break;
case 7:
deletep();
break;
case 8:
ch=0;
break;
default:
printf("enter valid choice");
break;
}
}
}
