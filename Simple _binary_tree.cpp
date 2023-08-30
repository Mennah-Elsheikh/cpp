
#include <iostream>
using namespace std;
//create a struct to declare the node 
struct node
{
	int data;
	//create two pointers of the node to pont to left and right node 
	//there will be the same tyrpe of the node 
	struct node* left = NULL;//the pointer of the left node 
	struct node* right = NULL;//the pointer of the right node 
};
 //now we will create node using a function colled new_node 
//it will return a node this node has a return type struct node as we know 
struct node*new_node ( int data )
{
	struct node* node = new struct node();//here we allocate the new node and we will declare data 
	//and two pointers to make this node tree node 
	node->data = data;//the data of the root or the parent node 
	node->left = NULL;//as defualt the pointer of the node that point to the left node will be null untill we declare a new left node  
	node->right = NULL;
	return(node);//the function will return node 
}
void preorderTraversal(struct node* node) {
	if (node == NULL)//the base case 
		return;

	cout << node->data << "->";
	preorderTraversal(node->left);//recursion
	preorderTraversal(node->right);//recursion
}

// Postorder traversal
//left - right - root 
void postorderTraversal(struct node* node) {
	if (node == NULL)//the base case 
		return;

	postorderTraversal(node->left);//recursion 
	postorderTraversal(node->right);//recursion
	cout << node->data << "->";
}

// Inorder traversal
//left -  root - right
void inorderTraversal(struct node* node) {//we will send the node itself 
	if (node == NULL)//the base case of the recurseve 
		return;

	inorderTraversal(node->left);//recursion
	cout << node->data << "->";
	inorderTraversal(node->right);//recursion
}

int main()
{
	struct node* root;
	root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	cout << "Inorder traversal ";
	inorderTraversal(root);

	cout << "\nPreorder traversal ";
	preorderTraversal(root);

	cout << "\nPostorder traversal ";
	postorderTraversal(root);
}

 