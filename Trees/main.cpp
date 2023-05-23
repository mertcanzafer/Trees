#include <iostream>
using namespace std;
template<class T>
class Node {
public:
	T value;
	Node* rightChild;
	Node* leftChild;

};

// How to create a new Node
template<class T>
Node<T>* createNode(T value)
{
	Node<T>* NextNode = new Node<T>();
	NextNode->value = value;
	NextNode->leftChild = NextNode->rightChild = NULL;
	return NextNode;
}
template<class T>
// Preorder Algh.
void printTreePreorder(Node<T>* root)
{
	// Data- left- right
	if (root == NULL) return;

	cout << root->value << endl;
	printTreePreorder(root->leftChild);
	printTreePreorder(root->rightChild);
}
template<class T>
// Inorder Algh
void printTreeInorder(Node<T>* root)
{
	// left - Data - right
	if (root == NULL) return;

	printTreeInorder(root->leftChild);
	cout << root->value << endl;
	printTreeInorder(root->rightChild);
}

template<class T>
// Postorder Algh
void printTreePostorder(Node<T>* root)
{
	// left - right - data
	if (root == NULL) return;

	printTreePostorder(root->leftChild);
	printTreePostorder(root->rightChild);
	cout << root->value << endl;
}


int main()
{
	Node<int>* root = createNode(1);


	// level = 1
	root->leftChild = createNode(2);
	root->rightChild = createNode(3);
	//level = 2
	root->leftChild->leftChild = createNode(4);
	root->leftChild->rightChild = createNode(5);
	
	root->rightChild->leftChild = createNode(6);
	root->rightChild->rightChild = createNode(7);
	//level = 3
	root->leftChild->rightChild->leftChild = createNode(9);
	root->rightChild->rightChild->leftChild = createNode(15);

	printTreePreorder(root);
	cout << "--------------------" << endl;
	printTreeInorder(root);
	cout << "--------------------" << endl;
	printTreePostorder(root);

	delete root;
	return 0;
}