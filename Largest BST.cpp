#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

struct tree_info {
	int size_of_subtree;
	int min;
	int max;
	int largest_BST;
	bool Is_BST;
};

tree_info Largest_BST(node* root) {
	if (root == NULL) {
		return { 0,INT_MAX,INT_MIN,0,true };
	}
	if (root->left == NULL && root->right == NULL)  // means a leaf node
		return { 1,root->data,root->data,1,true };
	// now get larges BST from left and right and then calculate for current
	
	tree_info left = Largest_BST(root->left);
	tree_info right = Largest_BST(root->right);

	tree_info current;
	current.size_of_subtree = (1 + left.size_of_subtree + right.size_of_subtree);

	if (left.Is_BST && right.Is_BST && left.max<root->data && right.min>root->data) {
		current.min = min(left.min, min(right.min, root->data));
		current.max = max(left.max, max(right.max, root->data));
		
		// current is BST so it's subtree is also BST and largest....
		current.largest_BST = current.size_of_subtree; 
		current.Is_BST = true;

		return current;
	}
	// if current is not BST then largest BST is either left or right....
		current.largest_BST = max(left.largest_BST, right.largest_BST);
		current.Is_BST = false;

	return current;
}
int main() {
	/*           15
	            / \
			  20   30
			  /    / \
			 5    15  35
	ANS= 3
	*/
	node* root = new node(15);
	root->left = new node(20);
	root->right = new node(30);

	root->right->right = new node(35);
	root->right->left = new node(15);
	root->left->left = new node(5);

	//tree_info temp = Largest_BST(root);
	cout << Largest_BST(root).largest_BST << endl;
	return 0;
}