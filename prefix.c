prefix
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int i, j = 0, c = 0, k, size, s2;
int top = -1;
char a[20];
char b[20];
char z[20];
char t[20];
char t2[20];
void push(char item);
char pop();
int prio(char op);
int prio(char op)
{
 if (op == ')')
 return 1;
 else if (op == '+' || op == '-')
 return 2;
 else if (op == '*' || op == '/' || op == '%')
 return 3;
 else if (op == '^')
 return 4;
 else
 return 0;
}
void push(char item)
{
 top++;
 a[top] = item;
 c++;
}
char pop()
{
 int item;
 item = a[top];
 top--;
 c--;
 return item;
}
void main()
{
 char opr;
 int ret, rett;
 k = 0;
 printf("\n");
 printf("enter the expression\n");
 gets(t);
 size = strlen(t);
 for (i = size - 1; i != -1; i--)
 {
 z[j] = t[i];
 j++;
 }
 for (i = 0; i <= size; i++)
 {
 ret = prio(z[i]);
 if (ret == 1)
 {
 push(z[i]);
 }
 else if (z[i] == '(')
 {
 for (j = top; a[j] != ')'; j--)
 {
 opr = pop();
 b[k] = opr;
 k++;
 }
 pop();
 }
 else if (z[i] == '\0')
 {
 for (j = top; j != -1; j--)
 {
 opr = pop();
 b[k] = opr;
 k++;
 }
 }
 else if (ret == 2 || ret == 3 || ret == 4)
 {
 e:
 rett = prio(a[top]);
 if (top == -1)
 {
 push(z[i]);
 }
 else if (ret > rett)
 {
 push(z[i]);
 }
 else if (ret < rett || ret == rett)
 {
 opr = pop();
 b[k] = opr;
 k++;
 goto e;
 }
 }
 else if (ret == 0)
 {
 b[k] = z[i];
 k++;
 }
 }
 s2 = strlen(b);
 j = 0;
 for (i = s2 - 1; i != -1; i--)
 {
 t2[j] = b[i];
 j++;
 }
 printf("prefix expression:");
 puts(t2);
}
