#include<stdio.h>
void linear();
void binary();
void disp();
void bubble();
int a[10],b[10],i,j,n;
void bubble()
{
int temp;
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
void disp()
{
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
void linear()
{
int k,key,flag=0;
printf("\nenter element to search:\n");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(key==b[i])
{
k=i;
flag=1;
}
}
if(flag==1)
{
printf("element found at a[%d]\n",k);
}
else
{
printf("element not found\n");
}
}
void binary()
{
bubble();
printf("\nafter sorting: ");
disp();
int k,key,flag=0,start,end=n-1,mid;
printf("\nenter element to search:\n");
scanf("%d",&key);
start=0;
while(start<=end)
{
mid=(start+end)/2;
if(a[mid]>key)
{
end=mid-1;
}
else if(a[mid]<key)
{
start=mid+1;
}
else
{
flag=1;
k=mid;
break;
}
}
if(flag==1)
{
printf("element found at a[%d]\n",k);
}
else
{
printf("element not found\n");
}
}
void main()
{
int ch,c=1;
printf("Enter the size of array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter value for a[%d]:\n",i);
scanf("%d",&a[i]);
b[i]=a[i];
}
printf("\nthe elements are: ");
disp();
while(c)
{
printf("\nchoose option:\n1.linear search\n2.binary search\nenter 
choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
linear();
break;
case 2:
binary();
break;
default:
printf("enter valid choice\n");
break;
}
printf("\ndo you want to continue(1/0):");
scanf("%d",&c);
}
}
