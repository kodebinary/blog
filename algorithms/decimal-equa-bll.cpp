#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

struct Node 
{
	int data;
	struct Node *next;
};

struct Node *createNode(int val)
{
	struct Node *tmpNode = (struct Node*)malloc(sizeof(struct Node));
	tmpNode->data = val;
	tmpNode->next = NULL;
	return tmpNode;
}

int decimalValue(struct Node *head)
{
	int decimal = 0;
	int index = 0;
	stack<int> stk;
	struct Node *curr = head;
	while(curr != NULL)
	{
		stk.push(curr->data);
		curr = curr->next;
	}

	while(!stk.empty())
	{
		decimal += stk.top() * pow(2, index);
		stk.pop();
		index++;
	}
	return decimal;
}

// Recursive func to 
// find decimal equivalent of Binary LL.
int decimalValRec(struct Node *head)
{
	if(head == NULL)
		return 0;
	static int pos = 0;
	int decimal = decimalValRec(head->next);
	decimal += (head->data * pow(2, pos++));
	return decimal;
}

void printLinkedList(struct Node *head)
{
	struct Node *curr = head;
	while(curr != NULL)
	{
		cout<<curr->data<<"-->";
		curr = curr->next;
	}
	cout<<"NULL"<<endl;
}

int main(int argc, char *argv[])
{
	struct Node *head = createNode(1);
	head->next = createNode(0);
	head->next->next = createNode(1);
	head->next->next->next = createNode(0);
	head->next->next->next->next = createNode(0);
	head->next->next->next->next->next = createNode(1);

	cout<<"Linked list is: "<<endl;
	printLinkedList(head);

	cout<<"Decimal value is: "<<decimalValue(head)<<endl;
	cout<<"Decimal Value Rec is: "<<decimalValRec(head)<<endl;
}
