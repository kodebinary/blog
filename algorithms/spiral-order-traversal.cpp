#include <iostream>
#include <stack>

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
		(struct Node*)malloc(
		sizeof(struct Node));
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

void spiralOrderRecUtil(
	struct Node *root,
	bool rtl,
	int level, int foundLvl)
{
	if(root == NULL)
		return;
	if(level == foundLvl)
	{
		cout<<root->data<<" ";
		return ;
	}
	if(rtl)
	{
		spiralOrderRecUtil(
			root->right, rtl, level+1, foundLvl);
		spiralOrderRecUtil(
			root->left, rtl, level+1, foundLvl);
	} else {
		spiralOrderRecUtil(
			root->left, rtl, level+1, foundLvl);
		spiralOrderRecUtil(
			root->right, rtl, level+1, foundLvl);
	}	
}

void spiralOrderRec(struct Node *root)
{
	int hgt = height(root);
	bool direction = false;
	for(int i=0; i<hgt; i++)
	{
		spiralOrderRecUtil(root,
			direction, 0, i);
		direction = !direction;
	}
}

void spiralOrderItr(struct Node *root)
{
	stack<struct Node*> level1;
	stack<struct Node*> level2;

	level1.push(root);

	while(!level1.empty() || !level2.empty())
	{
		while(!level1.empty())
		{
			struct Node *tmp = level1.top();
			level1.pop();
			cout<<tmp->data<<" ";
			if(tmp->left)
				level2.push(tmp->left);
			if(tmp->right)
				level2.push(tmp->right);
		}
		while(!level2.empty())
		{
			struct Node *tmp = level2.top();
			level2.pop();
			cout<<tmp->data<<" ";
			if(tmp->right)
				level1.push(tmp->right);
			if(tmp->left)
				level1.push(tmp->left);
		}
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

	cout<<"Spiral Order (Recursive): "<<endl;
	spiralOrderRec(root);
	cout<<endl;
	cout<<"Spiral Order (Iterative): "<<endl;
	spiralOrderItr(root);
	return 0;
}
