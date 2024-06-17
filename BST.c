#include <stdio.h>
#include <stdlib.h>
int flag, key;
struct node
{
 int data;
 struct node *llink;
 struct node *rlink;
} *newnode, *root, *temp, *parent, *child, *t, *suc, *anc;
void insert();
void search();
void inorder(struct node *t);
void postorder(struct node *t);
void preorder(struct node *t);
void delleaf();
void delch1();
void delch2();
void del();
s
void insert()
{
 flag = 0;
 printf("enter key:");
 scanf("%d", &key);
 newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = key;
 newnode->llink = NULL;
 newnode->rlink = NULL;
 if (root == NULL)
 {
 root = newnode;
 temp = newnode;
 }
 else
 {
 temp = root;
 flag = 0;
 while (flag != 1 && temp != NULL)
 {
 if (temp->data > key)
 {
 parent = temp;
 temp = temp->llink;
 }
 else if (temp->data < key)
 {
 parent = temp;
 temp = temp->rlink;
 }
 else
 {
 flag = 1;
 }
 }
 if (flag == 1)
 {
 printf("value exist");
 }
 else if (key > parent->data)
 {
 parent->rlink = newnode;
 }
 else
 {
 parent->llink = newnode;
 }
 }
}
void search()
{
 printf("enter key");
 scanf("%d", &key);
 temp = root;
 flag = 0;
 while (flag != 1 && temp != NULL)
 {
 if (temp->data > key)
 {
 parent = temp;
 temp = temp->llink;
 }
 else if (temp->data < key)
 {
 parent = temp;
 temp = temp->rlink;
 }
 else
 {
 flag = 1;
 }
 }
 if (flag == 1)
 {
 printf("value exist");
 }
 else
 {
 printf("value doesnt exist");
 }
}