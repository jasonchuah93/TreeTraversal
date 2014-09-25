#include <stdio.h>
#include "BinaryTree.h"
#include "Print.h"
#include "Stack.h"


void binaryTreeTraverseInOrder(Node *currentNode){
	Stack *stack; 
	stack = stackNew();
	printf("Created a stack\n");
	
	if(currentNode->left == NULL && currentNode->right == NULL){
		display(currentNode->data);
		goto here;
	}
	else{
		if(currentNode->left != NULL){
			stackPush(stack,currentNode);
			currentNode=currentNode->left;
			if(currentNode->left == NULL && currentNode->right == NULL){
				display(currentNode->data);
				currentNode=stackPop(stack); //pop 10
			}
			else{
				stackPush(stack,currentNode);
				currentNode=currentNode->left;
				if(currentNode->left == NULL && currentNode->right == NULL){
					display(currentNode->data);
				}
				currentNode=stackPop(stack); //pop 5 
				if(currentNode->right!=NULL){
					stackPush(stack,currentNode);
					currentNode=currentNode->right;
					if(currentNode->left == NULL && currentNode->right == NULL){
						display(currentNode->data);
					}
					currentNode=stackPop(stack);
				}
				display(currentNode->data);
				currentNode=stackPop(stack);
			}
		}
		if(currentNode->right != NULL){
			stackPush(stack,currentNode);//push 10 in again 
			currentNode=currentNode->right;//go to right
			if(currentNode->left == NULL && currentNode->right == NULL){
				display(currentNode->data); // show 20
			}
			currentNode=stackPop(stack);
		}
		
		display(currentNode->data);
	}
	currentNode=stackPop(stack); //check if is null
	here:
	stackDel(stack);
	printf("Deleted a stack\n");
	printf("-------------------------------");
}