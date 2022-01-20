#include<stdio.h>
#include<stdlib.h>
//defining a structure
struct node
{
int data;
struct node *next;
};
struct node *sp=(struct node*)0;
int ss;
void main()
{
void push(int);
int pop();
int search(int);
int c,data,k=1;
do
{
printf("******SINGLY LINKED STACK OPERATIONS*****\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.search\n");
printf("4.exit\n");
printf("enter your choice:\n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter the element to insert:\n");
scanf("%d",&data);
push(data);
break;
case 2:data=pop();
if(ss==1)
printf("poped item is: %d\n",data);
break;
case 3:printf("enter the data to search\n");
scanf("%d",&data);
k=search(data);
if(k==1)
{
printf("item not found..\n");
}

break;
case 4:printf("exiting...");
exit(0);
}
}
while(1);
}

void push(int x)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=sp;
sp=newnode;
printf("item inserted..\n");
}

int pop()
{
int a;
struct node *temp;
if(sp==(struct node*)0)
{
printf("stack is empty\n");
ss=0;
}
else
{
a=sp->data;
temp=sp;
sp=sp->next;
free(temp);
ss=1;
return a;
}
}
int search(int x)
{
struct node *ptr;
ptr=sp;

while(ptr!=(struct node*)0)
{
if(ptr->data==x)
{
printf("item found..\n");
return 0;
}
ptr=ptr->next;
}
return 1;
}
