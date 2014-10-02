#include "unity.h"
#include "BinaryTree.h"
#include "Traversal.h"
#include "mock_Print.h"
#include "mock_Stack.h"

void setUp(void){}

void tearDown(void){}

void test_changeNodeState_should_change_state_entered_node_to_visited_left_node(void){
	
	Node root = {.state=ENTERED_NODE};
	
	changeNodeState(&root);
	TEST_ASSERT_EQUAL(VISITED_LEFT_NODE,root.state);
}

void test_changeNodeState_should_change_visited_left_node_to_visited_right_node(void){
	
	Node root = {.state=VISITED_LEFT_NODE};
	
	changeNodeState(&root);
	TEST_ASSERT_EQUAL(VISITED_RIGHT_NODE,root.state);
}

void test_changeNodeState_should_change_visited_right_node_to_unknown_node_state(void){
	
	Node root = {.state=VISITED_RIGHT_NODE};
	
	changeNodeState(&root);
	TEST_ASSERT_EQUAL(UNKNOWN_NODE_STATE,root.state);
}

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
	stackPop_ExpectAndReturn(&stack,NULL);
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
	stackPush_Expect(&stack,&root); //push 10 into stack 
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	-   20
**/

void test_binary_tree_with_2_nodes_parent_and_right_child(void){
	Node rightChild = {NULL,NULL,20};
	Node root = {NULL,&rightChild,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and right child \n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(10);
	stackPush_Expect(&stack,&root); //push 10 into stack 
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   20
**/

void test_binary_tree_with_3_nodes_parent_and_left_child_and_right_child(void){
	Node leftChild = {NULL,NULL,5};
	Node rightChild = {NULL,NULL,20};
	Node root = {&leftChild,&rightChild,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 3 node parent,left child and right child \n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack,&root); 
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPush_Expect(&stack,&root); 
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   -
 *	/\
 * 1 -
**/

void test_binary_tree_with_3_nodes_parent_and_left_child_and_below(void){
	Node leftChild = {NULL,NULL,1};
	Node leftChild2	= {&leftChild,NULL,5};
	Node root = {&leftChild2,NULL,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 3 node parent,left child and below\n");
	
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root); //push 10 
	stackPush_Expect(&stack,&leftChild2); //push 5 
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack,&leftChild2); // pop 5
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root); // pop 10
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   -
 *	/\
 * 1 7
**/

void test_binary_tree_with_4_nodes_parent_and_left_child_and_below(void){
	Node rightChild = {NULL,NULL,7};
	Node leftChild = {NULL,NULL,1};
	Node leftChild2	= {&leftChild,&rightChild,5};
	Node root = {&leftChild2,NULL,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 4 node parent,left child and below\n");
	
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root); //push 10 
	stackPush_Expect(&stack,&leftChild2); //push 5 
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack,&leftChild2); // pop 5
	display_Expect(5);
	stackPush_Expect(&stack,&leftChild2); //push 5 
	display_Expect(7);
	stackPop_ExpectAndReturn(&stack,&leftChild2); // pop 5
	stackPop_ExpectAndReturn(&stack,&root); // pop 10
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   15
 *	/\
 * 1 7
**/

void test_binary_tree_with_5_nodes_parent_and_left_child_and_right_child(void){
	Node node7 = {NULL,NULL,7};
	Node node1 = {NULL,NULL,1};
	Node node5	= {&node1,&node7,5};
	Node node15 = {NULL,NULL,15};
	Node root = {&node5,&node15,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 5 node parent,left child and below\n");
	
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root); //push 10 
	stackPush_Expect(&stack,&node5); //push 5 
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack,&node5); // pop 5
	display_Expect(5);
	stackPush_Expect(&stack,&node5); //push 5 
	display_Expect(7);
	stackPop_ExpectAndReturn(&stack,&node5); // pop 5
	stackPop_ExpectAndReturn(&stack,&root); // pop 10
	display_Expect(10);
	stackPush_Expect(&stack,&root);
	display_Expect(15);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
 *   10
 *	/	\
 *	5   15
 *	/\  / \
 * 1 7  13 18
**/

void test_binary_tree_with_7_nodes_parent_and_left_child_and_right_child(void){
	Node node7 = {NULL,NULL,7};
	Node node1 = {NULL,NULL,1};
	Node node13 = {NULL,NULL,13};
	Node node18 = {NULL,NULL,18};
	Node node5	= {&node1,&node7,5};
	Node node15 = {&node13,&node18,15};
	Node root = {&node5,&node15,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 7 node parent,left child and below\n");
	
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root); //push 10 
	stackPush_Expect(&stack,&node5); //push 5 
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack,&node5); // pop 5
	display_Expect(5);
	stackPush_Expect(&stack,&node5); //push 5 
	display_Expect(7);
	stackPop_ExpectAndReturn(&stack,&node5); // pop 5
	stackPop_ExpectAndReturn(&stack,&root); // pop 10
	display_Expect(10);
	stackPush_Expect(&stack,&root); //push 10
	stackPush_Expect(&stack,&node15);
	display_Expect(13);
	stackPop_ExpectAndReturn(&stack,&node15);
	display_Expect(15);
	stackPush_Expect(&stack,&node15);
	display_Expect(18);
	stackPop_ExpectAndReturn(&stack,&node15);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}



/**
 *   100
 *	/	 \
 *	50    -
	/ \
	20	-
	/ \
   18 -
**/
void test_traversing_left(void){
	Node node18 = {NULL,NULL,18};
	Node node20 = {&node18,NULL,20};
	Node node50 = {&node20,NULL,50};
	Node node100 = {&node50,NULL,100};
	Node *currentNode, *root=&node100;
	
	currentNode=root;
	printf("%d\n",currentNode->data);
	
	currentNode=currentNode->left;
	printf("%d\n",currentNode->data);
	
	currentNode=currentNode->left;
	printf("%d\n",currentNode->data);
	
	currentNode=currentNode->left;
	printf("%d\n",currentNode->data);
}

/**
 *   10
 *	/	\
 *	5   -
**/


void test_binary_tree_print_in_order_for_root_and_left_node(void){
	Node node5 = {NULL,NULL,5};
	Node root = {&node5,NULL,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and left child \n");
	binaryTreePrintInOrder(&root);
}

/**
 *   10
 *	/	\
 *	-    50
**/


void test_binary_tree_print_in_order_for_root_and_right_node(void){
	Node node50 = {NULL,NULL,50};
	Node root = {NULL,&node50,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and left child \n");
	binaryTreePrintInOrder(&root);
}

/**
 *   10
 *	/	\
 *	8    50
**/


void test_binary_tree_print_in_order_for_root_right_and_left_node(void){
	Node node8 = {NULL,NULL,8};
	Node node50 = {NULL,NULL,50};
	Node root = {&node8,&node50,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and left child \n");
	binaryTreePrintInOrder(&root);
}

/**
 *  			 10
 *				/	\
 *				8    50
 *			   / \   / \
 *			  3  14  30 80
**/


void test_binary_tree_print_in_order_for_root_right_and_left_node_2(void){
	Node node3 = {NULL,NULL,3};
	Node node14 = {NULL,NULL,14};
	Node node30 = {NULL,NULL,30};
	Node node80 = {NULL,NULL,80};
	Node node8 = {&node3,&node14,8};
	Node node50 = {&node30,&node80,50};
	Node root = {&node8,&node50,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 2 node parent and left child \n");
	binaryTreePrintInOrder(&root);
}


