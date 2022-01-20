//2 way merging
#include<stdio.h>
void main()
{
void reader(int[],int);
void display(int[],int);
void merge(int[],int[],int[],int,int);
int s1[50],s2[50],s3[100],m,n;
printf("enter the number of elements in first array[1-50]:");
scanf("%d",&m);
printf("enter the elements in first array in non decreasing order");
reader(s1,m);
printf("enter the number of elements in second array[1-50]:");
scanf("%d",&n);
printf("enter the elements in second array in non decreasing order");
reader(s2,n);
merge(s1,s2,s3,m,n);
printf("The merged array is :\n");
display(s3,m+n);
}
//function for reading an array
void reader(int s[],int n)
{
int i;

for(i=0;i<n;i++)
scanf("%d",&s[i]);
return;
}
//function for displaying array
void display(int s[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d  ",s[i]);
return;
}
void merge(int s1[],int s2[],int s3[],int m,int n)
{
int i,j,k;
i=j=k=0;
//compare and copy element
while(i<m&&j<n)
{
if(s1[i]<s2[j])
{
s3[k]=s1[i];
i=i+1;
k=k+1;
}
else
{
s3[k]=s2[j];
j=j+1;
k=k+1;
}
}
//copying remaining elements from s1
while(i<m)
s3[k++]=s1[i++];
//copying remaining elements from s2
while(j<n)
s3[k++]=s2[j++];
return;
}
