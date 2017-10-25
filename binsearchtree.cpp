/*
FILENAME:	binsearchtree.cpp
AUTHOR:		eric phung
DATE:		2017.10.23
PURPOSE:	main file for p-tree project in c++
			binary search tree insertion
			avl tree w/ proper balance
			cs362 data structures coursework
NOTES:		
	*	need balance rotations for avl tree property
*/
#include <iostream>
#include <vector>
#include "filereader.cpp"



struct Node {
	int data;
	Node *left;
	Node *right;

};

int getHeight(Node *node){
	// get height from this node
	int heightLeft 	= 0;
	int heightRight = 0;

	if (node->left != nullptr) {
		heightLeft = getHeight(node->left);
	}

	if (node->right != nullptr) {
		heightRight = getHeight(node->right);
	}


	if (heightLeft > heightRight) {
		// left subtree is higher
		return (heightLeft+1);
	} else {
		return (heightRight +1);
	}

}// end get height

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insert(Node *root, Node *node) {
	// traverse tree and insert node at correct location
	if (node->data < root->data) {
		// move left
		if (root->left != nullptr) {
			// if root has a left child
			root = root->left;
			insert(root,node);

		} else {
			root->left = node;
			return;
		}
	} else if (node->data > root->data) {
		// move right
		if (root->right != nullptr) {
			// if root has right child
			root = root->right;
			insert(root,node);
		} else {
			root->right = node;
			return;
		}
	}

}// end insert

void printNode(Node *node) {
	if (node->left != nullptr) {
		std::cout << node->left << " left [" << node->left->data << "] <--- ";	
	}
	std::cout << "node [" << node->data << "] " << node;
	if (node->right != nullptr) {
		std::cout << " ---> right [" << node->right->data << "] " << node->right << std::endl;
	}
	else if ((node->left == nullptr) && (node->right == nullptr)){
		// print leaf node
		std::cout << " <--- leaf node " << std::endl;
	}
	else {
		std::cout << std::endl;
	}
	
}// end print node


// function to print tree
void printSubtree(Node *root, int space) {
    // Base case
    if (root == nullptr)
        return;
 
    // Increase distance between levels
    space += 2;
 
    // Process right child first
    printSubtree(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 2; i < space; i++)
        printf(" ");
    printf("%d", root->data);
    
    // Process left child
    printSubtree(root->left, space);
}

Node * findMin(Node *root) {
	while(root->left != nullptr) {
	    root = root->left;
	}
	return root;
}// end findMin

Node * findMax(Node *root){
	while(root->right != nullptr) {
	    root = root->right;
	}
	return root;
}




int main() {

	// vector to hold node ptrs for garbage collection	
	std::vector<Node *> ptrs;

	// read integer values from txt file into a vector
	std::vector<int> nums;
	nums = getIntegersFromFile("treenode.txt");

	// create first tree node
	Node *root = newNode(nums.at(0));
	ptrs.push_back(root);

	// insert the rest of the nodes from text file
	for (int i = 1; i < nums.size(); ++i) {
		Node *n = newNode(nums.at(i));
		insert(root,n),
		ptrs.push_back(n);
	}// for integer values in txt file

	// print full tree to console
	printSubtree(root,0);
	printf("\n");


	// find the minimum tree node
	Node *min = findMin(root);
	printNode(min);

	// find maximum tree node
	Node *max = findMax(root);
	printNode(max);


	// print tree height from root
	printf("Tree Height is %i\n", getHeight(root));

	// print min and max height
	//printf("Max Node Height is %i\n", getHeight(max));
	//printf("Min Node Height is %i\n", getHeight(min));





	// garbage collection pointers
	for (int i = 0; i < ptrs.size(); ++i) {
		delete ptrs.at(i);
	}

	return 0;
}// end main