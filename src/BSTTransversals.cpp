/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_traversal(struct node *root, int *arr, int *index)
{
	if (root->left != NULL)
	{
		inorder_traversal(root->left, arr, index);
	}
	arr[*index] = (root)->data;
	++(*index);
	if ((root)->right != NULL)
	{
		inorder_traversal(((root)->right), arr, index);
	}
}
void preorder_traversal(struct node *root, int *arr, int *index)
{
	arr[*index] = (root)->data;
	++(*index);
	if ((root)->left != NULL)
	{
		preorder_traversal(((root)->left), arr, index);
	}
	if ((root)->right != NULL)
	{
		preorder_traversal(((root)->right), arr, index);
	}
}
void postorder_traversal(struct node *root, int *arr, int *index)
{
	if ((root)->left != NULL)
	{
		postorder_traversal(((root)->left), arr, index);
	}
	if ((root)->right != NULL)
	{
		postorder_traversal(((root)->right), arr, index);
	}
	arr[*index] = (root)->data;
	++(*index);
}
void inorder(struct node *root, int *arr) {
	int index = 0;
	if (root != NULL&&arr != NULL)
		inorder_traversal(root, arr, &index);
}
void preorder(struct node *root, int *arr) {
	int index = 0;
	if (root != NULL&&arr != NULL)
		preorder_traversal(root, arr, &index);
}
void postorder(struct node *root, int *arr) {
	int index = 0;
	if (root != NULL&&arr != NULL)
		postorder_traversal(root, arr, &index);
}
