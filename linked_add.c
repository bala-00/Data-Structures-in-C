#include <stdio.h>
#include <stdlib.h>
// linked list
struct node
{
 int data;
 int pow;
 struct node *next;
} * head_1, *head_2, *temp, *node_1, *node_3, *k,*head,*temp2;
struct node *i, *j;
void set(struct node *head);
void sort(struct node *head);
void print(struct node *head);
void add();
struct node * create();
//set
void set(struct node *head)
{
struct node *n,*m;
int d=0,p=0;
n=head;
while(n!=NULL)
{
m=n->next;
while(m!=NULL)
{
if(n->pow == m->pow)
{
n->data=n->data+m->data;
n->next=m->next;
}
m=m->next;
}
n=n->next;
}
}
//creation
struct node * create()
{
int choice = 1;
 head = 0;
 printf("enter polynomial:\n");
 while (choice)
 {
 node_1 = (struct node *)malloc(sizeof(struct node));
 printf("Enter data:");
 scanf("%d", &node_1->data);
 printf("Enter power:");
 scanf("%d", &node_1->pow);
 node_1->next = 0;
 if (head == 0)
 {
 head = node_1;
 temp = node_1;
 }
 else
 {
 temp->next = node_1;
 temp = node_1;
 }
 printf("Do you wanna continue:(0/1):");
 scanf("%d", &choice);
 }
 print(head);
 printf("\n\n");
 return head;
}
// sorting
void sort(struct node *head)
{
 int d = 0, p = 0;
 struct node *n, *m;
 for (n = head; n != NULL; n = n->next)
 {
 for (m = n->next; m != NULL; m = m->next)
 {
 if (n->pow < m->pow)
 {
 d = n->data;
 p = n->pow;
 n->data = m->data;
 n->pow = m->pow;
 m->data = d;
 m->pow = p;
 }
 }
 }
}
// printing
void print(struct node *head)
{
 printf("polynomial: \n");
 sort(head);
 set(head);
 temp = head;
 while (temp != NULL)
 {
 if (temp->data != 0)
 {
 printf("%dx^%d ", temp->data, temp->pow);
 if (temp->next != NULL)
 {
 k = temp->next;
 if ((k->data) > 0 )
 {
 printf(" + ");
 }
 }
 temp = temp->next;
 }
 else 
 {
if(temp->next!=NULL)
{
printf(" + ");
}
 temp = temp->next;
 }
 }
}
//add
void add()
{
i = head_1;
j = head_2;
temp2=i;
while(temp2->next!=0)
{
temp2=temp2->next;
}
temp2->next=j;
 printf("\nFinal ");
 print(head_1);
}
void main()
{
head_1=create();
head_2=create();
add();
}
