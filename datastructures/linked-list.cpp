/**
*	Detailed explanation of linked lists can be
*	found at https://kodebinary.com/doubly-linked-list
**/
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

// Consider node structure here as defined earlier code part.
struct Node* createNode(int value)
{
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}
struct Node* insert(struct Node* head, int value, int pos)
{
    if(head == NULL) return NULL;
    int curr_pos = 0;
    struct Node *current_node = head;
    struct Node *newNode = createNode(value);
    if(pos == 0)
    {
        newNode->next = head;
        return newNode;
    }
    while(current_node->next != NULL)
    {
        curr_pos++;
        current_node = current_node->next;
        if(curr_pos == (pos - 1))
            break;
    }
    newNode->next = current_node->next;
    current_node->next = newNode;
    return head;
}

struct Node *deleteNode(struct Node *head, int value)
{
    if(head == NULL) return NULL;
    struct Node *current = head;
    struct Node *delNode = head;
    if(head->data == value)
    {
        head = head->next;
        current->next = NULL;
        free(current);
        return head;
    }
    while(current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }
    if(current->next != NULL)
    {
        delNode = current->next;
        current->next = delNode->next;
        delNode->next = NULL;
        free(delNode);
    }
    return head;
}

struct Node *find(struct Node *head, int value)
{
    if(head == NULL) return NULL;
    struct Node *current = head;

    while(current->next != NULL)
    {
        if(current->data == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void printList(struct Node *head)
{
	struct Node *curr = head;
	while(curr != NULL)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int main(int argc, char* argv[])
{
	// Create linked list here.
	struct Node *head = NULL;
	head = createNode(10);
	head->next = createNode(20);
	head->next->next = createNode(15);
	head->next->next->next = createNode(5);

	cout<<"Input List: "<<endl;
	printList(head);

	head = insert(head, 9, 2);
	cout<<"List after insert 9 at 2nd position: "<<endl;
	printList(head);

	head = deleteNode(head, 9);
	cout<<"List after deleing 9: "<<endl;
	printList(head);

	struct Node *foundNode = find(head, 20);
	if(foundNode != NULL)
		cout<<"Number 20 found in List"<<endl;
	else
		cout<<"Number 20 not found in List"<<endl;
	
	return 0;
}
