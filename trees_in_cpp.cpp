#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int key;
	 struct node *left,*right;
};

struct node* newnode(int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left= temp->right = NULL;
	
	return temp;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
	
	cout<<root->key<<" ";
	preorder(root->left);
	preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
	
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
	}
}

// function to insert a new node

struct node* insert(struct node* node, int item)
{
	if(node== NULL) return newnode(item);
	
	if(item < node->key)
		node->left = insert(node->left, item);
	else if(item> node->key)
		node->right= insert(node->right,item);
		
	return node;
}

// function to search for a node

struct node* search(struct node *root, int item)
{
	if(root==NULL || root->key==item)
		return root;
	if(root->key > item)
		return search(root->left,item);
	return search(root->right, item);
	
}

// main function
int main() 
{ 
    
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    cout<<"Inorder traversal :\n\n";
    inorder(root);
	cout<<"\n\n";
	// print preorder traversal
	cout<<"pre order traversal :\n\n";
	preorder(root);
	cout<<"\n\n";
	// print post order traversal
	cout<<"post order traversal :\n\n";
	postorder(root);
   
    return 0; 
} 
