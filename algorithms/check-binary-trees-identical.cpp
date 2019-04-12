#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

// Recursive approach to find
// given tree are identical or not.
bool identicalRec(
	struct Node *root1,
	struct Node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data) &&
		identicalRec(root1->left, root2->left) &&
		identicalRec(root1->right, root2->right);
}

// An iterative approach to find
// given trees are identical or not.
bool identicalItr(
	struct Node *root1,
	struct Node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;

	stack<pair<struct Node*, struct Node*> > stk;
	stk.push(make_pair(root1, root2));

	while(!stk.empty())
	{
		Node *tmp1 = stk.top().first;
		Node *tmp2 = stk.top().second;
		stk.pop();

		if(tmp1->data != tmp2->data)
			return false;

		if(tmp1->left && tmp2->left)
			stk.push(make_pair(tmp1->left, tmp2->left));
		else if(tmp1->left || tmp2->left)
			return false;

		if(tmp1->right && tmp2->right)
			stk.push(make_pair(tmp1->right, tmp2->right));
		else if(tmp1->right || tmp2->right)
			return false;
	}
	return true;
}

struct Node *createNode(int val)
{
	struct Node *tmp = 
		(struct Node*)malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->left = tmp->right = NULL;
	return tmp;
}

int main(int argc, char *argv[])
{
	// Tree one.
	struct Node *root1 = createNode(5);
	root1->left = createNode(10);
	root1->right = createNode(8);
	root1->left->left = createNode(2);
	root1->left->right = createNode(7);

	root1->right->left = createNode(15);
	root1->right->right = createNode(18);
	
	// Second binary tree.
	struct Node *root2 = createNode(5);
	root2->left = createNode(10);
	root2->right = createNode(8);
	root2->left->left = createNode(2);
	root2->left->right = createNode(7);

	root2->right->left = createNode(15);
	root2->right->right = createNode(18);

	cout<<"Trees Identical (Recursive): "
		<<(identicalRec(root1, root2)?"TRUE":"FALSE")<<endl;
	cout<<"Trees Identical (Iterative): "
		<<(identicalItr(root1, root2)?"TRUE":"FALSE")<<endl;
	return 0;
}
