#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

int height(struct Node *root)
{
	if(root == NULL)
		return 0;
	return 1 +
		max(height(root->left), height(root->right));
}

void levelOrderUtil(
	struct Node *root, 
	int level,
	int dispLevel)
{
	if(root == NULL)
		return;
	if(level == dispLevel) {
		cout<<root->data<<" ";
		return;
	}
	levelOrderUtil(root->left, level+1, dispLevel);
	levelOrderUtil(root->right, level+1, dispLevel);
}

void levelOrderRec(struct Node *root)
{
	int hgt = height(root);
	for(int i=0; i<hgt; i++)
		levelOrderUtil(root, 0, i);
}

struct Node *createNode(int val)
{
	struct Node *tmp = (struct Node*)
				malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void levelOrderItr(struct Node *root)
{
	if(root == NULL)
		return;
	queue<struct Node*> que;
	que.push(root);
	while(!que.empty())
	{
		struct Node *tmp = que.front();
		que.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)
			que.push(tmp->left);
		if(tmp->right)
			que.push(tmp->right);
	}
	cout<<endl;
}

int main(int argc, char* argv[])
{
	struct Node *root = createNode(10);
	root->left = createNode(4);
	root->right = createNode(8);
	root->left->left = createNode(50);
	root->left->right = createNode(24);
	root->right->left = createNode(5);
	root->right->right = createNode(12);
	root->left->left->right = createNode(18);

	cout<<"Level Order Traversal: "<<endl;
	levelOrderRec(root);
	cout<<endl;
	cout<<"Iterative level order: "<<endl;
	levelOrderItr(root);
	
	return 0;
}
