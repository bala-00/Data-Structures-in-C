#include<stdio.h>
int ar1[10][10],ar2[10][10],tu1[10][3],tu2[10][3],s[20][20],tr1[10][3],tr2[10][3],x,y,m,n;
void read(int r,int c,int ar[][10]);
void transpose(int tu[][3],int tr[][3]);
void tupleadd(int x[][3],int y[][3]);
void ctuple(int r,int c,int ar[][10],int tu[][3]);

void read(int r,int c,int ar[][10])

{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("enter the elements[%d][%d] of the matrix:",i,j);
            scanf("%d",&ar[i][j]);
        }
    }
    printf("\nSPARSE:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ctuple(int m,int n,int ar[][10],int tu[][3])

{
    int i,j,k=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (ar[i][j]!=0)
            {
                k++;
            }
        }
    }
    tu[k][3];
    tu[0][0]=m;
    tu[0][1]=n;
    tu[0][2]=k-1;
    int co=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (ar[i][j]!=0)
            {
                tu[co][0]=i;
                tu[co][1]=j;
                tu[co][2]=ar[i][j];
                co++;
            }
        }
    } 
    for(i=0;i<co;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",tu[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(int tu[][3],int tr[][3])

{
    int i,j,k,n;
    tr[0][0]=tu[0][1];
    tr[0][1]=tu[0][0];
    tr[0][2]=tu[0][2];
    k=1;
    n=tu[0][2];
    for(i=0;i<tu[0][1];i++)
    {
        for(j=1;j<=n;j++)
        {
            
            if (i==tu[j][1])
            {
                tr[k][0]=i;
                tr[k][1]=tu[j][0];
                tr[k][2]=tu[j][2];
                k++;
            }
        }
    }
    
    tr[k][3];
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",tr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tupleadd(int x[][3],int y[][3])

{
 int k1=x[0][2],k2=y[0][2];
 int i=1,j=1,k=1,x1=0,y1=0;
 if(x[0][0]==y[0][0] && x[0][1]==y[0][1])
 {
  while(i<=k1 && j<=k2)
  {
   if(x[0][0]<y[0][0])
   {
    s[k][0]=x[i][0];
    s[k][1]=x[i][1];
    s[k][2]=x[i][2];
    k++;
    i++;
   }
   else if(x[0][0]>y[0][0])
   {
    s[k][0]=y[j][0];
    s[k][1]=y[j][1];
    s[k][2]=y[j][2];
    j++;
                k++;
   }
   else if(x[0][1]<y[0][1])
   {
    s[k][0]=x[i][0];
    s[k][1]=x[i][1];
    s[k][2]=x[i][2];
    k++;
                i++;
   }
   else if(x[0][1]>y[0][1])
   {
    s[k][0]=y[j][0];
    s[k][1]=y[j][1];
    s[k][2]=y[j][2];
    j++;
                k++;
   }
   else
   {
    s[k][0]=x[i][0];
    s[k][1]=x[i][1];
    s[k][2]=x[i][2]+y[j][2];
    i++;
                k++;
                j++;
   }
  }
  while(i<k1)
  {
   s[k][0]=x[i][0];
   s[k][1]=x[i][1];
   s[k][2]=x[i][2];
   k++;
            i++;
  }
  while(j<k2)
  {
   s[k][0]=y[j][0];
   s[k][1]=y[j][1];
   s[k][2]=y[j][2];
   j++;
   k++;
  }
  s[0][0]=x[0][0];
  s[0][1]=y[0][1];
  s[0][2]=k-1;
  for(i=0;i<k;i++)
  {
   for(j=0;j<3;j++)
   {
    printf("%d\t",s[i][j]);
   }
   printf("\n");
  }
    }
    else
    {
        printf("tuple cannot be added");
    }
}

void main()

{
    printf("Read the no of rows and coloum of first sparse matrix:");
    scanf("%d%d",&x,&y);
    int ar1[x][y];
    read(x,y,ar1);
    printf("TUPLE 1\n"); 
    ctuple(x,y,ar1,tu1);
    printf("TRANSPOSE\n");
    transpose(tu1,tr1);
    printf("Read the no of rows and coloum of second sparse matrix:");
    scanf("%d%d",&m,&n);
    int ar2[m][n];
    read(m,n,ar2);
    printf("TUPLE 2\n");
    ctuple(m,n,ar2,tu2);
    printf("TRANSPOSE\n");
    transpose(tu2,tr2);
    printf("SUM:\n");
    tupleadd(tu1,tu2); 
}
