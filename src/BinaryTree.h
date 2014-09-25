#ifndef BinaryTree_H
#define BinaryTree_H

typedef struct Node Node;

struct Node{
	Node *left;
	Node *right;
	int data;
};

void binaryTreeTraverseInOrder(Node *root);

#endif // BinaryTree_H
