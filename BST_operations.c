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
void inorder(struct node *t)
{
 if (t == NULL)
 {
 return;
 }
 inorder(t->llink);
 printf("%d\t", t->data);
 inorder(t->rlink);
}
void postorder(struct node *t)
{
 if (t == NULL)
 {
 return;
 }
 postorder(t->llink);
 postorder(t->rlink);
 printf("%d\t", t->data);
}
void preorder(struct node *t)
{
 if (t == NULL)
 {
 return;
 }
 printf("%d\t", t->data);
 preorder(t->llink);
 preorder(t->rlink);
}
void delleaf()
{
 if (parent->data > key)
 {
 parent->llink = NULL;
 }
 else
 {
 parent->rlink = NULL;
 }
}
void delch1()
{
 if (temp->rlink == NULL)
 {
 child = temp->llink;
 }
 else
 {
 child = temp->rlink;
 }
 if (parent->data > temp->data)
 {
 parent->llink = child;
 }
 else
 {
 parent->rlink = child;
 }
}
void delch2()
{
 suc = temp->llink;
 while (suc->rlink != NULL)
 {
 anc = suc;
 suc = suc->rlink;
 }
 if (suc->llink == NULL)
 {
 temp->data = suc->data;
 if (anc != NULL)
 {
 anc->rlink = NULL;
 }
 else
 {
 temp->llink = NULL;
 }
 }
 else
 {
 temp->data = suc->data;
 anc->rlink = suc->llink;
 }
}
void del()
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
 if (flag == 0)
 {
 printf("element doesnt exist");
 }
 else
 {
 if (temp->rlink == NULL && temp->llink == NULL)
 {
 delleaf();
 }
 else if (temp->rlink == NULL || temp->llink == NULL)
 {
 delch1();
 }
 else if (temp->rlink != NULL && temp->llink != NULL)
 {
 delch2();
 }
 }
}
void main()
{
 int z, z1, c = 1;
 root = NULL;
 temp = NULL;
 while (c)
 {
 printf("\nenter 
choice:\n1.insert\n2.delete\n3.serach\n4.display\n5.exit\n:");
 scanf("%d", &z);
 switch (z)
 {
 case 1:
 insert();
 break;
 case 2:
 del();
 break;
 case 3:
 search();
 break;
 case 4:
 
printf("\n\tchoose:\n\t1.inorder\n\t2.postorder\n\t3.preorder\n\t:");
 scanf("%d", &z1);
 switch (z1)
 {
 case 1:
 inorder(root);
 break;
 case 2:
 postorder(root);
 break;
 case 3:
 preorder(root);
 break;
 default:
 printf("enter valid choice\n");
 break;
 }
 break;
 case 5:
 c = 0;
 break;
 default:
 printf("enter valid choice\n");
 break;
 }
 }
}
