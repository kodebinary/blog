#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* createNode(int val)
{
	struct Node *tmp = 
		(struct Node*)malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

int height(struct Node *root)
{
	if(root == NULL)
		return 0;
	return 1 + 
		max(height(root->left), 
		    height(root->right));
}

int main(int argc, char* argv[])
{
	struct Node *root = createNode(10);
	root->left = createNode(4);
	root->right = createNode(8);
	root->left->left = createNode(50);
	root->left->right = createNode(24);
	root->left->left->right = createNode(18);
	root->right->left = createNode(5);

	cout<<"Height of tree: "<<height(root)<<endl;
	return 0;
}
