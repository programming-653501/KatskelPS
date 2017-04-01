// lab5_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>

struct Tree{
	int data;
	Tree *left;
	Tree * right;
};

void treecpy(Tree** dest, Tree** src);
void addData(Tree** tree, int data);
void LeftOrder(Tree* tree);
int treecmp(Tree *tree1, Tree *tree2);

int main()
{
	Tree *root = NULL;
	addData(&root, 1);
	addData(&root, 7);
	addData(&root, 3);
	addData(&root, 1);
	LeftOrder(root);
	Tree *copy = NULL;
	treecpy(&copy, &root);
	printf("\n");
	addData(&copy, 4);
	LeftOrder(copy);
	printf("\n");
	if (treecmp(root, copy))
		printf("Trees are equal\n");
	else
		printf("Trees aren't equal\n");
	_getch();
    return 0;
}

void addData(Tree** tree, int data)
{
	if (!(*tree))
	{
		(*tree) = new Tree();
		(*tree)->data = data;
		(*tree)->left = (*tree)->right = NULL;
	}
	else
	{
		if (data > (*tree)->data)
			addData(&(*tree)->right, data);
		else if (data < (*tree)->data)
			addData(&(*tree)->left, data);
		else
			printf("The element %d is already in the tree\n", data);
	}
}

void treecpy(Tree** dest, Tree** src)
{
	*dest = new Tree();
	(*dest)->data = (*src)->data;
	(*dest)->left = (*dest)->right = NULL;
	if((*src)->left)
		treecpy(&(*dest)->left, &(*src)->left);
	if((*src)->right)
		treecpy(&(*dest)->right, &(*src)->right);
}

void LeftOrder(Tree* tree)
{
	if (!tree)
		printf("Tree is empty");
	else
	{
		if (tree->left)
			LeftOrder(tree->left);
		printf("%d ", tree->data);
		if (tree->right)
			LeftOrder(tree->right);
	}
}

int treecmp(Tree *tree1, Tree *tree2)
{
	if (tree1 == NULL && tree2 != NULL)
		return 0;
	if (tree1 != NULL && tree2 == NULL)
		return 0;
	if (tree1 == NULL && tree2 == NULL)
		return 1;
	if (tree1->data != tree2->data)
		return 0;
	if (!treecmp(tree1->left, tree2->left))
		return 0;
	if (!treecmp(tree1->right, tree2->right))
		return 0;
	return 1;
}