#include <stdio.h>
#include "BinaryTree.h"
#include "Print.h"
#include "Stack.h"

void changeNodeState(Node *curMode){
	switch(curMode->state){
		case ENTERED_NODE:
			curMode->state = VISITED_LEFT_NODE;
		break;
		case VISITED_LEFT_NODE:
			curMode->state = VISITED_RIGHT_NODE;
		break;
		default:
			curMode->state = UNKNOWN_NODE_STATE;
		break;
	}
}

void binaryTreeTraverseInOrder(Node *currentNode){
	Stack *stack; 
	stack = stackNew();
	while(1){
		if(currentNode->left == NULL && currentNode->right == NULL){
			display(currentNode->data);
			currentNode->state=ENTERED_NODE;
			goto here;
		}else if(currentNode->left!=NULL){
			currentNode->state=ENTERED_NODE;
			stackPush(stack,currentNode);
			currentNode=currentNode->left;
			currentNode->state=ENTERED_NODE;
			if(currentNode->left == NULL && currentNode->right == NULL){
				display(currentNode->data);
				currentNode=stackPop(stack);
				display(currentNode->data);
				changeNodeState(currentNode);
			}
		}else if(currentNode->right!=NULL){
			display(currentNode->data);
			currentNode->state=ENTERED_NODE;
			stackPush(stack,currentNode);
			currentNode=currentNode->right;
			currentNode->state=ENTERED_NODE;
			display(currentNode->data);
			currentNode=stackPop(stack);
			
			currentNode->state=VISITED_RIGHT_NODE;
		}
		if(currentNode->state==VISITED_LEFT_NODE){
			if(currentNode->right!=NULL){
				stackPush(stack,currentNode);
				currentNode=currentNode->right;
				currentNode->state=ENTERED_NODE;
				display(currentNode->data);
				currentNode=stackPop(stack);
			}else{
				break;
			}
		}
		if(currentNode->state==VISITED_RIGHT_NODE || currentNode->state==VISITED_LEFT_NODE){
			break;
		}
	}
		currentNode=stackPop(stack); // Check it is NULL
		here:
		stackDel(stack);
}

