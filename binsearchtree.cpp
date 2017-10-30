/*
FILENAME:	binsearchtree.cpp
AUTHOR:		eric phung
DATE:		2017.10.23
PURPOSE:	main file for p-tree project in c++
			binary search tree insertion
			avl tree w/ proper balance
			cs362 data structures coursework
NOTES:		
	*	needs balance rotations for avl tree property
*/

#include "utility.h"

// standard node struct for this program
struct Node {
	int data;
	int height;
	int depth;
	Node *left;
	Node *right;
};

// global variables
std::vector<int> nums;// values from file
std::vector<Node *> ptrs;
int balance;
int insertions;
int i;
Node *root;
Node *n;

// new node function
Node* newNode(int data) {
    Node* node 		= new Node;
    node->data 		= data;
    node->left 		= NULL;
    node->right 	= NULL;
    ptrs.push_back(node);
    return node;
}

// function to print tree
void printTree(Node *root, int space) {
    // base case
    if (root == NULL){return;}

    // Increase distance between levels
    space += space;
 
    // Process right child first
    printTree(root->right, space);
 
    // Print current node after space
    // count
    for (int i = 2; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    
    // Process left child
    printTree(root->left, space);
}

// print a single node
void printNode(Node *node) {
	if (node->left != NULL) {
		std::cout << "[" << node->left->data << "] <--- \t";
	} else {
		std::cout << "\t\t\t";
	}
	std::cout << "[" << node->data << "]";
	if (node->right != NULL) {
		std::cout << " ---> [" << node->right->data << "]\t";
	} else {
		std::cout << "\t\t\t\t";
	}
	std::cout << "\theight = " << node->height << ", " << "depth = " << node->depth;
	std::cout << std::endl;
}// end print node

void insert(Node *root, Node *node) {
	// traverse tree and insert node at correct location
	if (node->data < root->data) {
		// move left
		node->depth++;// inc depth
		if (root->left != NULL) {
			// if root has a left child
			root = std::move(root->left);
			insert(root,node);
		} else {
			root->left = std::move(node);
		}
	} else if (node->data > root->data) {
		// move right
		node->depth++;// inc depth
		if (root->right != NULL) {
			// if root has right child
			root = std::move(root->right);
			insert(root,node);
		} else {
			root->right = std::move(node);
		}
	}
}// end insert

// get the height fo a node
int getHeight(Node *node){
	// get height from this node
	int heightLeft 	= 0;
	int heightRight = 0;
	if (node->left != NULL)
		heightLeft = getHeight(node->left);
	if (node->right != NULL)
		heightRight = getHeight(node->right);

	if (heightLeft > heightRight)
		// left subtree is higher
		return (heightLeft+1);
	else
		// right subtree is higher
		return (heightRight+1);
}// end get height

// get the balance of a node
int getBalance(Node *q) {
	int balance = (q->right->height)-(q->left->height);
	return balance;
}// end get balance,sb

// update all node heights
void updateAllHeights(Node *q) {
	// set all node heights
	for (int i = 0; i < ptrs.size(); ++i)
		ptrs.at(i)->height = (getHeight(ptrs.at(i))-1);
}// end update heights

// print debug information
void printPointers(std::vector<Node *> v) {
	// print all nodes and linked nodes
	int i;
	for (i = 0; i < v.size(); ++i)
		printNode(v.at(i));
	if (v.size() > insertions)
		std::cout << "More pointer exister than objects! :o Oh noez!" << std::endl;
	std::cout << "Active Pointers: " << v.size() << std::endl;
	// print tree height from root
	printf("Tree Height: %i\n", getHeight(root));
	printf("Number of Nodes: %i\n", insertions);
	printf("Balance is %i ", balance);
	if (balance < 0) {std::cout << "=> Tree is Left-Heavy\n";}
	else if (balance > 0) {std::cout << "Tree is Right-Heavy\n";}// end if
	else {std::cout << "Even at zero" << std::endl;}

}

// main program
int main() {

	// read contents from file
	nums = getIntegersFromFile("treenode.txt");
	
	// create root node
	root = newNode(nums.at(i));// BEFORE AVL IMPLEMENTATION!!!!
	insertions++;

	// construction while loop
	while(i < 5) {
		n = newNode(nums.at(i));
		insert(root,n);
		insertions++;
		updateAllHeights(root);
		i++;
	}// end while


	// print to console
	std::cout << "Finished Program" << std::endl;
	printTree(root,1);
	//printPointers(ptrs);

	// garbage
	nums.clear();
	ptrs.clear();

	return 0;
}// end main