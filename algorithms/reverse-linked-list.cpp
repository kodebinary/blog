#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *createNode(int val)
{
	struct Node *node =
	 (struct Node*)malloc(sizeof(struct Node));

	node->data = val;
	node->next = NULL;
	return node;
}

struct Node *iterativeRev(struct Node *head)
{
	struct Node *prev = NULL;
	struct Node *next, *curr;
	next = curr = head;
	while(curr != NULL)
	{
		// Move next to current's next.
		next = curr->next;
		// Current's next to prev.
		curr->next = prev;
		// Prev to current.
		prev = curr;
		// Current to next.
		curr = next;
	}
	return prev;
}

struct Node* recursiveRev(struct Node *head)
{
	if(head == NULL || head->next == NULL)
		return head;
	
	struct Node *rev = recursiveRev(head->next);
	
	head->next->next = head;
	head->next = NULL;
	return rev;
}

void printList(struct Node *head)
{
	struct Node *curr = head;
	while(curr != NULL)
	{
		cout<<curr->data<<"-->";
		curr = curr->next;
	}
	cout<<"NULL"<<endl;
}

int main(int argc, char* argv[])
{
	struct Node *head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	cout<<"Given List is: "<<endl;
	printList(head);
	head = iterativeRev(head);
	cout<<"Reversed List (Iterative): "<<endl;
	printList(head);
	cout<<"Reversing Reversed List (Recursive): "<<endl;
	head = recursiveRev(head);
	printList(head);
	return 0;
}
