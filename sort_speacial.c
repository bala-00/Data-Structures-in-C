#include <stdio.h>
int i,j;
int a[10],b[10],n;
void swap(int* a, int* b);
void set(int a[], int n, int i);
void heapSort(int a[], int n);
int partition(int ar[], int low, int high) ;
void quickSort(int ar[], int low, int high) ;
void merges(int a[], int p, int q, int r);
void mergeSort(int a[], int l, int r);
void disp(int a[], int n);
void heap();
void quick();
void merge();
void merges(int a[], int p, int q, int r)
{
 int n1 = q - p + 1;
 int n2 = r - q;
 int x[n1], y[n2];
 for (i = 0; i < n1; i++)
 {
 x[i] = a[p + i];
 }
 for (j = 0; j < n2; j++)
 {
 y[j] = a[q + 1 + j];
 }
 int i, j, k;
 i = 0;
 j = 0;
 k = p;
 while (i < n1 && j < n2)
 {
 if (x[i] <= y[j])
 {
 a[k] = x[i];
 i++;
 }
 else
 {
 a[k] = y[j];
 j++;
 }
 k++;
 }
 while (i < n1)
 {
 a[k] = x[i];
 i++;
 k++;
 }
 while (j < n2)
 {
 a[k] = y[j];
 j++;
 k++;
 }
}
void mergeSort(int a[], int l, int r)
{
 if (l < r)
 {
 int m = l + (r - l) / 2;
 mergeSort(a, l, m);
 mergeSort(a, m + 1, r);
 merges(a, l, m, r);
 }
}
int partition(int ar[], int low, int high) 
{ 
int pivot = ar[high];
i = (low - 1);
for (j = low; j < high; j++) 
{
if (ar[j] <= pivot) 
{
 i++;
 swap(&ar[i], &ar[j]);
 }
}
swap(&ar[i + 1], &ar[high]);
return (i + 1);
}
void quickSort(int ar[], int low, int high) 
{
if (low < high) 
{
 int pi = partition(ar, low, high);
 quickSort(ar, low, pi - 1);
 quickSort(ar, pi + 1, high);
}
}
void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}
void set(int a[], int n, int i)
{
int big = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && a[left] > a[big])
{
big = left;
}
if (right < n && a[right] > a[big])
{
big = right;
}
if (big != i) 
{
swap(&a[i], &a[big]);
set(a, n, big);
}
}
void heapSort(int a[], int n)
{
for (i = n / 2 - 1; i >= 0; i--)
{
set(a, n, i);
}
for (i = n - 1; i >= 0; i--) 
{
swap(&a[0], &a[i]);
set(a, i, 0);
}
}
void disp(int a[], int n)
{
for (i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
}
void quick() 
{
printf("Unsorted Array\n");
disp(a, n);
quickSort(a, 0, n - 1);
printf("Sorted array:\n");
disp(a, n);
}
void heap()
{
printf("Unsorted Array\n");
disp(a, n);
heapSort(a, n);
printf("Sorted array is\n");
disp(a, n);
}
void merge()
{
 printf("Unsorted Array\n");
disp(a, n);
 mergeSort(a, 0, n - 1);
 printf("Sorted array: \n");
 disp(a, n);
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
disp(a,n);
printf("\n");
printf("\nchoose option:\n1.quick\n2.merge\n3.heap\nenter 
choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
quick();
break;
case 2:
merge();
break;
case 3:
heap();
break;
default:
printf("enter valid choice\n");
break;
}
printf("\ndo you want to continue(1/0):");
scanf("%d",&c);
}
}