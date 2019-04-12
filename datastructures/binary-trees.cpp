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
    	struct Node *tmpNode =
		(struct Node*)malloc(sizeof(struct Node));
	tmpNode->data  = val;
	tmpNode->left  = NULL;
	tmpNode->right = NULL;
	return tmpNode;
}

void preOrder(struct Node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<"  ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(struct Node *root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<"  ";
	inOrder(root->right);
}
void postOrder(struct Node *root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<"  ";
}

int main(int argc, char* argv[])
{
    	struct Node *root = createNode(1);
  	root->left = createNode(2);
	root->right = createNode(3);
	
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	cout<<"Pre-order :"<<endl;
	preOrder(root);
	cout<<endl<<"In-order :"<<endl;
	inOrder(root);
	cout<<endl<<"Post-order :"<<endl;
	postOrder(root);
	cout<<endl;

	return 0;
}
