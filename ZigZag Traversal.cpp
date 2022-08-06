#include<iostream>
#include<stack>
using namespace std;
struct node {
	int data;
	node* left, * right;
	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* BST_from_array(int arr[], int start, int end) {
	if (start > end)
		return NULL;
	int med = (start + end) / 2;
	int key = arr[med];
	node* root = new node(key);
	root->left = BST_from_array(arr, start, med - 1);
	root->right = BST_from_array(arr, med + 1, end);

	return root;
}

void zigZag_traversal(node* root) {
	if (!root)
		return;
	stack<node*>curr_level;
	stack<node*>next_level;

	bool right_to_left = true;

	curr_level.push(root);
	while (!curr_level.empty()) {

		node* temp = curr_level.top();
		curr_level.pop();
		cout << temp->data << "  ";
		if (right_to_left == true) {

			if (temp->right)
				next_level.push(temp->right);
			if (temp->left)
				next_level.push(temp->left);

		}
		else {

			if (temp->left)
				next_level.push(temp->left);
			if (temp->right)
				next_level.push(temp->right);
	
		}

		if (curr_level.empty()) {
			right_to_left = !right_to_left;
			swap(curr_level, next_level);
		}
		
	}
}

void in_order(node* root) {
	if (root == NULL)
		return;
	in_order(root->left);
	cout << root->data << "  ";
	in_order(root->right);
}
int main() {
	/*              3
	               / \
                  1   4
				   \   \
				    2   5
                 	
	*/
	int arr[] = { 1,2,3,4,5 };
	node* root = BST_from_array(arr, 0, 4);
	
	zigZag_traversal(root);
	return 0;
}