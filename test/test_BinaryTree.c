#include "unity.h"
#include "BinaryTree.h"
#include "Traversal.h"
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