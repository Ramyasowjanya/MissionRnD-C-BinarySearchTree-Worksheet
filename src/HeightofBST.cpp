/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node {
	struct node * left;
	int data;
	struct node *right;
};

void count_height(struct node *root, int *count_arr, int *index)
{
	count_arr[*index] = count_arr[*index] + 1;
	if (root->left != NULL)
	{
		count_height(root->left, count_arr, index);
	}
	if (root->right != NULL)
	{
		count_height(root->right, count_arr, index);
	}
	if (root->left == NULL&&root->right == NULL)
	{
		(*index)++;
	}
}
int get_height(struct node *root) {
	int count_arr[4] = { 0,1,1,1 }, index = 0, large = 0;
	if (root == NULL)
		return 0;
	else if (root->left == NULL&&root->right == NULL)
		return 1;
	else
	{
		count_height(root, count_arr, &index);
		while (index > 0)
		{
			if (count_arr[index] > count_arr[large])
				large = index;
			index--;
		}
		return count_arr[large];
	}
}
void count_tree(struct node *temp, int *count)
{
	*count = *count + temp->data;
	if (temp->left != NULL)
	{
		count_tree(temp->left, count);
	}
	if (temp->right != NULL)
	{
		count_tree(temp->right, count);
	}
}

int get_left_subtree_sum(struct node *root) {
	struct node* temp;
	int count = 0;
	if (root != NULL)
	{
		if (root->left != NULL)
		{
			temp = root->left;
			count_tree(temp, &count);
		}
		return count;
	}
	return 0;
}

int get_right_subtree_sum(struct node *root) {
	struct node* temp;
	int count = 0;
	if (root != NULL)
	{
		if (root->right != NULL)
		{
			temp = root->right;
			count_tree(temp, &count);
		}
		return count;
	}
	return 0;
}