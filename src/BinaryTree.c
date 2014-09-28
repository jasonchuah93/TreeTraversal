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
	currentNode->state=ENTERED_NODE;
	while(1){
		if(currentNode->state==ENTERED_NODE){
			if(currentNode->left==NULL && currentNode->right==NULL){
				display(currentNode->data);
				break;
			}else if(currentNode->left!=NULL){
				stackPush(stack,currentNode);
				currentNode=currentNode->left;
				currentNode->state=ENTERED_NODE;
			}else if(currentNode->right!=NULL){
				display(currentNode->data);
				stackPush(stack,currentNode);
				currentNode=currentNode->right;
				currentNode->state=ENTERED_NODE;
			}
		}
	}
	while(1){
		if((currentNode=stackPop(stack))==NULL){
			break;
		}else{
			if(currentNode->left!=NULL){
				changeNodeState(currentNode);
			}
		}
		if(currentNode->state==VISITED_LEFT_NODE){
			printf("here display 10 \n");
			display(currentNode->data);
			if(currentNode->right!=NULL){
				stackPush(stack,currentNode);
				currentNode=currentNode->right;
				display(currentNode->data);
			}
		}
	}
	stackDel(stack);
}

/*
while(1){
		if(currentNode->left == NULL && currentNode->right == NULL){
			currentNode->state=ENTERED_NODE;
			display(currentNode->data);
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
				//changeNodeState(currentNode);
			}
		}else if(currentNode->right!=NULL){
			currentNode->state=ENTERED_NODE;
			display(currentNode->data);
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
		
		stackDel(stack);
*/