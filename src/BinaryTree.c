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
				currentNode->state=VISITED_RIGHT_NODE;
			}else if(currentNode->left!=NULL){
				stackPush(stack,currentNode);
				currentNode=currentNode->left;
				currentNode->state=ENTERED_NODE;
			}else{
				currentNode->state=VISITED_LEFT_NODE;
			}
		}else if(currentNode->state==VISITED_LEFT_NODE){
			if(currentNode->right==NULL){
				display(currentNode->data);
				changeNodeState(currentNode);
			}else{
				display(currentNode->data);
				stackPush(stack,currentNode);
				currentNode=currentNode->right;
				currentNode->state=ENTERED_NODE;
			}
		}else if(currentNode->state==VISITED_RIGHT_NODE){
			if((currentNode=stackPop(stack))==NULL){
				break;
			}else{
				if(currentNode->state==ENTERED_NODE){
					changeNodeState(currentNode);
				}else if(currentNode->state==VISITED_LEFT_NODE){
					changeNodeState(currentNode);
				}
			}
		}
	}
	stackDel(stack);
}

void binaryTreePrintInOrder(Node *node){
	if(node!=NULL){
		binaryTreePrintInOrder(node->left);
		printf("Node : %d\n",node->data);
		binaryTreePrintInOrder(node->right);
	}
}
