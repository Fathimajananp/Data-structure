//set
#include<stdio.h>
struct bit{
unsigned char x:1;
};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersect(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[9]={0};
struct bit b[9]={0};
struct bit c[9]={0};
int x,y;
printf("Enter the no of elements in set A:");
scanf("%d",&x);
readset(a,x);
printf("Enter the no of elements in set B:");
scanf("%d",&y);
readset(b,y);
printf("Set A:");
printset(a);
printf("Set B:");
printset(b);
unionset(a,b,c);
printf("A U B =");
printset(c);
intersect(a,b,c);
printf("A intersect B =");
printset(c);
difference(a,b,c);
printf("A - B =");
printset(c);
}

//function for reading a set and store as bit string
void readset(struct bit a[],int n)
{
int i,x,k,d;
printf("Enter %d elements:",n);
for(i=0;i<n;i++)
{
scanf("%d",&d);
for(k=0;k<size;++k)
if(uset[k]==d)
{
a[k].x=1;
break;
}
}
return;
}
//To print a set from bit string representation
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<size;++k)
if(a[k].x==1)
printf("%d,",uset[k]);
printf("}\n");
return;
}

//to find union of two sets
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x | b[k].x;
return;
}

//to print intersection of two sets
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x & b[k].x;
return;
}

//to print difference of two sets
void difference(struct bit a[],struct bit b[], struct bit c[])
{
int k;
for(k=0;k<size;++k)
if(a[k].x==1)
c[k].x=a[k].x ^ b[k].x;
return;
}

