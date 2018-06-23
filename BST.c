	
#include<stdio.h>
#include<stdlib.h>

struct list
{
        int info;
        struct list *left,*right;   

};


void insert_node(struct list ** , int );
void preorder_traversal(struct list *);
void postorder_traversal(struct list *);
void inorder_traversal(struct list *);
	

int main()
{
	struct list *root=NULL;
	int item,ch;
	while (1)
	{
		printf("\n1.\tInsert Node\n2.\tPreorder Traverse\n3.\tInorder traversal\n4.\tPostorder Traversal.\n0.\tExit\n\nEnter your Choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter item :\t");
				scanf("%d",&item);
				insert_node(&root,item);
				break;
			case 2: preorder_traversal(root);
				break;
			case 3: inorder_traversal(root);
				break;
			case 4: postorder_traversal(root);
				break;
			case 0: exit(0);
			default: printf("\n wrong Entry"); 
		}
	
	}
	return(0);

}

void insert_node(struct list ** root, int item)
{
	struct list * par=NULL,*loc,*newnode;
	loc=*root;
	while(loc!=NULL)
	{

		if (item==(loc->info))
		{
			printf("\n Duplicate Item:");
			return;
		}
		par=loc;
		if (item<loc->info)
			loc=loc->left;
		else 
			loc=loc->right;
		
	}
	newnode=(struct list *)malloc(sizeof(struct list));
	newnode->info= item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(par==NULL)
		*root=newnode;
	else if (item<par->info)
		par->left=newnode;
	else
		par->right=newnode;
	
	return;
}

void preorder_traversal(struct list * root)
{
	if(root!=NULL)
	{
		printf("\t %d",root->info);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	
	}

	return;			
}

void inorder_traversal(struct list * root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		printf("\t%d",root->info);
		inorder_traversal(root->right);
		
	}
	return;

}

void postorder_traversal(struct list * root)
{
	if(root!=NULL)
	{
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		printf("\t %d",root->info);
	}
	return;

}

