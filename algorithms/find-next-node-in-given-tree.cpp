#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int val)
{
	struct Node *tmp =
		(struct Node*)malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

struct Node *findNextSameLevel(
	struct Node* root,
	int value)
{
	queue<struct Node*> que;
	que.push(root);
	while(!que.empty())
	{
		struct Node *tmp = que.front();
		que.pop();
		if(tmp->data == value)
			break;
		if(tmp->left != NULL)
		{
			que.push(tmp->left);
		}
		if(tmp->right != NULL)
		{
			que.push(tmp->right);
		}
	}
	if(!que.empty())
		return que.front();
	return NULL;
}

int main(int argc, char *argv[])
{
	struct Node *root = createNode(10);
	root->left = createNode(4);
	root->right = createNode(8);
	root->left->left = createNode(50);
	root->left->right = createNode(24);
	
	root->right->left = createNode(5);
	root->right->right = createNode(12);

	struct Node *nextNode = findNextSameLevel(root, 50);
	if(nextNode)
		cout<<"Next node in the same level for 50 is: "<<nextNode->data<<endl;
	nextNode = findNextSameLevel(root, 24);
	if(nextNode)
		cout<<"Next node in the same level for 24 is: "<<nextNode->data<<endl;

	return 0;
}
