#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	struct node *right;
	int data;
};
struct node *root=NULL;
void main()
{
void insert(int);
struct node* search(struct node*,int);
void inorder(struct node*);
void delete(int);
int data,c;
do
{
printf("******BINARY SEARCH TREE******\n");
printf("1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&c);
switch(c)
{
case 1: printf("Enter the data to insert:\n");
	scanf("%d",&data);
	insert(data);
	break;
case 2: printf("Enter the data to search:\n");
	scanf("%d",&data);
	search(root,data);
	break;
case 3: printf("Enter the data to delete:\n");
	scanf("%d",&data);
	delete(data);
	break;
case 4: if(root==NULL)
	printf("NULL TREE...\n");
	else{
	printf("Inorder traversal results:\n");
	inorder(root);
	printf("\n");
	}
	break;
case 5: printf("Exiting...\n");
	exit(0);
}
}while(1);
}
void insert(int x)
{
//create a newnode
struct node *t,*t1,*t2;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->left=t->right=NULL;
if(root==NULL)//case of empty tree
root=t;
else
{
t1=root;
while(t1!=NULL && t1->data!=x)
{
t2=t1;
//for remembering the parent node
if(x>t1->data)
t1=t1->right;
else
t1=t1->left;
}
if(x==t2->data)
printf("duplicate data not allowed\n");
else//actual insertion code block
{
if(x>t2->data)//case of new data greater than parent
t2->right=t;
else//case of new data lower than parent
t2->left=t;
}
}
}
//search a given key in a given BST
struct node* search(struct node* root, int data)
{
// Base Cases: root is null or key is present at root
if (root == NULL )//case of empty tree
printf("Not found..\n");
else if(root->data == data)
{   
printf("Item found..\n");
}   
else 
{
// Key is greater than root's key
if (data > root->data)//case of right subtree
       return search(root->right, data);
       
else
    // Key is smaller than root's key
    return search(root->left, data);//case of left subtree
    
}
}
 
//function to delete a node
void delete(int data)
{
struct node*t1,*t2,*t3,*sucpar,*suc;
t1=root;
//loop to find the node to be deleted
while(t1!=NULL && t1->data!=data)
{
t2=t1;
if(data>t1->data)
t1=t1->right;
else
t1=t1->left;
}
//after the loop t1 points to the node to be deleted
//t2 points to the parent of the node to be deleted
//t1==NULL implies not found
if(t1==NULL)
printf(" item Not found..\n");
else//element found case
{
if(t1->right==NULL && t1->left==NULL)//case of leaf node
{
if(t1!=root)
{
if(t2->data>data)
t2->left=NULL;
else
t2->right=NULL;
}
root=NULL;
}
else if(t1->left==NULL ||t1->right==NULL)//case of single child
{
if(t1!=root)
{
if(data>t2->data)//case of deleting node on the right side of parent
t2->right=t1->left==NULL?t1->right:t1->left;
else//case of deleting node on the left side of parent
t2->left=t1->left==NULL?t1->right:t1->left;
}
else
{
if(root->right!=NULL)
root=root->right;
else
root=root->left;
}
}
else//case of two child
{
//inorder successor will be left extreme of right subtree
sucpar=t1;
suc=t1->right;
while(suc->left!=NULL)
{
sucpar=suc;
suc=suc->left;
}
//copy the inorder successor to the node to be deleted
t1->data=suc->data;
//next step is to add link to inorder successor parent
//for that we need to find it is left or right
if(suc->data<sucpar->data)
sucpar->left=suc->right;
else
sucpar->right=suc->right;
t1=suc;
}
free(t1);//common removal for all cases
}
}
void inorder(struct node *t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d " ,t->data);
inorder(t->right);
}
}



