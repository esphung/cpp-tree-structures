#include <iostream>
#include <vector>
#include "filereader.cpp"

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
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

void printSubtree(Node *node) {
	// should work for subtrees as well
	std::cout << "root node [" << node->data << "]";


	std::cout << std::endl;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void printSubtree(Node *root, int space)
{
    // Base case
    if (root == nullptr)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    printSubtree(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    printSubtree(root->left, space);
}

int main() {

	// vector to hold node ptrs for garbage collection	
	std::vector<Node *> v;

	// read integer values from txt file into a vector
	std::vector<int> fileVector;
	fileVector = getVectorFromFile("treenode.txt");

	// create first tree node
	Node *root = newNode(fileVector.at(0));
	v.push_back(root);

	// insert the rest of the nodes from text file
	for (int i = 1; i < fileVector.size(); ++i) {
		Node *n = newNode(fileVector.at(i));
		insert(root,n),
		v.push_back(n);

	}// for integer values in txt file

	printSubtree(root,1);



	// garbage collection
	for (int i = 0; i < v.size(); ++i) {
		delete v.at(i);
	}



	std::cout << "~ finished tree program successfully ~" << std::endl;
	return 0;
}// end main