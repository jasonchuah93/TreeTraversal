#include <stdio.h>
#include "BinaryTree.h"
#include "Print.h"
#include "Stack.h"


void binaryTreeTraverseInOrder(Node *root){
	Stack *stack; 
	stack = stackNew();
	printf("Created a stack\n");
	
	
	
	
	display(root->data);
	stackDel(stack);
	printf("Deleted a stack\n");
	printf("-------------------------------");
}