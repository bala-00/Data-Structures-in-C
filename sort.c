#include<stdio.h>
int a[10],b[10],i,j,n,temp;
void bubble();
void selection();
void insertion();
void print();
void bubble()
{
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
void selection()
{
int min;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[min])
{
min=j;
}
}
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
void insertion()
{
for(i=1;i<n;i++)
{
temp=a[i];
j=i-1;
while(temp<a[j] && j>=0)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;
}
}
void print()
{
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
void main()
{
int ch,c=1;
printf("Enter the size of array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter value for a[%d]:\n",i);
scanf("%d",&b[i]);
}
while(c)
{
for(i=0;i<n;i++)
{
a[i]=b[i];
}
printf("\nthe elements are: ");
print();
printf("\nchoose option:\n1.bubble sort\n2.selection 
sort\n3.insertion sort\nenter option:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
bubble();
printf("\nAfter bubble sorting:\n");
print();
break;
case 2:
selection();
printf("\nAfter selection sorting:\n");
print();
break;
case 3:
insertion();
printf("\nAfter insertion sorting:\n");
print();
break;
default:
printf("enter valid choice\n");
break;
}
printf("\ndo you want to continue(1/0):");
scanf("%d",&c);
}
}