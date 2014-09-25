#include "unity.h"
#include "BinaryTree.h"
#include "mock_Print.h"
#include "mock_Stack.h"

void setUp(void){}

void tearDown(void){}

/**
 *   10
 *	/	\
 *	-   -
**/

void test_binary_tree_with_1_node(void){
	Node root = {NULL,NULL,6};
	Stack stack;
	
	printf("Starts test_binary_tree_with_1_node\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(6);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   -
**/


void test_binary_tree_with_2_nodes_parent_and_left_child(void){
	Node leftChild = {NULL,NULL,5};
	Node root = {&leftChild,NULL,10};
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and left child \n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack,&root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}
