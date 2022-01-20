#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
struct node *start=(struct node*)0;//representation of empty list
struct node *temp;
void main()
{
void insert(int);
struct node* search(int);
void delete(int);
int data, c;
do
{
printf("******DOUBLY LINKEDLIST OPERATIONS******\n");
printf("1.Insert\n");
printf("2.Search\n");
printf("3.Delete\n");
printf("4.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&c);
switch(c)
{
case 1: printf("Enter a value to insert:\n");
        scanf("%d",&data);
	insert(data);
	break;
case 2: printf("Enter a value to search:\n");
	scanf("%d",&data);
	temp=search(data);
	if(temp==0)
	printf("Item not found..\n");
	else
	printf("Item found..\n");
	break;
case 3: printf("Enter a value for delete:\n");
	scanf("%d",&data);
	delete(data);
	break;
case 4: exit(0);
}
}
while(1);
}
//function to insert at beginning
void insert(int data)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
//inserting item in an empty node
if(start==0)
{
temp->left=temp->right=(struct node *)0;
start=temp;	
}
//case of atleast one node
else
{
temp->left=(struct node *)0;
temp->right=start;
start->left=temp;
start=temp;
}
printf("Value inserted..\n");
}
//function for searching an item
struct node *search(int data)
{
struct node *temp;
temp=start;
while(temp!=(struct node *)0 && temp->data!=data)
{
temp=temp->right;
}
return temp;//temp 0 implies not found,1 implies found
}
//function for deleting a data from a node
void delete(int data)
{
struct node *temp;
temp=search(data);//calling search to find whether that data exists or not
if(temp==0)
{
printf("Data not found..\n");
}
else
{
//element exists case
if(temp==start)//case of first node

if(temp->right==NULL)//only one node
{
start=NULL;
}
else//case of having more than one node
{
temp->right->left=NULL;
start=temp->right;
}
//case of last node
else if(temp->right==NULL)
{
temp->left->right=NULL;
}
else
{
//case of interior node
temp->left->right=temp->right;
temp->right->left=temp->left;
}

free(temp);
printf("Item deleted..\n");
}
}
