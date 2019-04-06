#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *findLoop(struct Node *head)
{
	struct Node *curr = head;
	struct Node *slow, *fast;
	slow = fast = head;
	slow = slow->next;
	fast = fast->next->next;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	while(curr != slow)
	{
		curr = curr->next;
		slow = slow->next;
	}
	return curr;
}

struct Node *createNode(int val)
{
	struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = val;
	tmp->next = NULL;
	return tmp;
}

void printList(struct Node* head)
{
	struct Node *curr = head;
	int counter = 0;
	while(curr != NULL && counter < 10)
	{
		cout<<curr->data<<"-->";
		curr = curr->next;
		counter++;
	}
	cout<<endl;
}

int main(int argc, char* argv[])
{
	struct Node *head = createNode(24);
	head->next = createNode(20);
	head->next->next = createNode(7);
	head->next->next->next = createNode(8);
	head->next->next->next->next = createNode(9);
	head->next->next->next->next->next = createNode(4);
	head->next->next->next->next->next->next = head->next->next;

	cout<<"Given list is: "<<endl;
	printList(head);
	struct Node *loop = findLoop(head);
	cout<<"Loop found at: "<<loop->data<<endl;
	return 0;
}
