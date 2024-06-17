#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 int pow;
 struct node *next;
} *head1, *head2, *head3, *temp, *node1, *node3, *k, *head, *i, *j;
struct node *create();
void sort(struct node *head);
void print(struct node *head);
void set(struct node *head);
void mult();
struct node *create()
{
 int choice = 1;
 head = 0;
 printf("enter polynomial\n");
 while (choice)
 {
 node1 = (struct node *)malloc(sizeof(struct node));
 printf("enter data:");
 scanf("%d", &node1->data);
 printf("enter power:");
 scanf("%d", &node1->pow);
 node1->next = NULL;
 if (head == 0)
 {
 head = node1;
 temp = node1;
 }
 else
 {
 temp->next = node1;
 temp = node1;
 }
 printf("do you want to continue(1/0)");
 scanf("%d", &choice);
 }
 print(head);
 return head;
}
void sort(struct node *head)
{
 struct node *n, *m;
 int d = 0, p = 0;
 n = head;
 while (n != NULL)
 {
 m = n->next;
 while (m != NULL)
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
 m = m->next;
 }
 n = n->next;
 }
}
void set(struct node *head)
{
 struct node *n, *m;
 int d = 0, p = 0;
 n = head;
 while (n != NULL)
 {
 m = n->next;
 while (m != NULL)
 {
 if (n->pow == m->pow)
 {
 n->data = n->data + m->data;
 n->next = m->next;
 }
 m = m->next;
 }
 n = n->next;
 }
}
void print(struct node *head)
{
 printf("polynomial:");
 sort(head);
 set(head);
 temp = head;
 while (temp != 0)
 {
 printf("%dx^%d", temp->data, temp->pow);
 if (temp->next != NULL)
 {
 k = temp->next;
 if (k->data > 0)
 {
 printf(" + ");
 }
 }
 temp = temp->next;
 }
 printf("\n");
}
void mult()
{
 i = head1;
 head3 = 0;
 while (i != NULL)
 {
 j = head2;
 while (j != NULL)
 {
 node3 = (struct node *)malloc(sizeof(struct node));
 node3->data = i->data * j->data;
 node3->pow = i->pow + j->pow;
 node3->next = 0;
 if (head3 == 0)
 {
 head3 = node3;
 temp = node3;
 }
 else
 {
 temp->next = node3;
 temp = node3;
 }
 j = j->next;
 }
 i = i->next;
 }
 print(head3);
}
void main()
{
 head1 = create();
 head2 = create();
 printf("\nFinal:");
 mult();
}
