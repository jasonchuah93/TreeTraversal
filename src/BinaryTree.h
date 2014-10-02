#ifndef BinaryTree_H
#define BinaryTree_H

#include "Traversal.h"

typedef struct Node Node;

struct Node{
	Node *left;
	Node *right;
	int data;
	NodeState state;
};

void binaryTreeTraverseInOrder(Node *root);
void binaryTreePrintInOrder(Node *node);

#endif // BinaryTree_H
