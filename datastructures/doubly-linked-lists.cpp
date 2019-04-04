/**
*	Detailed explanation of this doubly linked list program
*	can found at https://kodebinary.com/doubly-linked-list
*/
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

class DLL
{
  public:
	struct Node *head, *tail;

	DLL()
	{
		head = tail = NULL;
	}
	~DLL() {}

	bool empty()
	{
		return (head == NULL) &&
			   (tail == NULL);
	}

	void insert_back(int val)
	{
		struct Node *tmpNode = newNode(val);
		if (empty())
		{
			head = tail = tmpNode;
			return;
		}
		tail->next = tmpNode;
		tmpNode->prev = tail;
		tail = tmpNode;
	}
	void insert_front(int val)
	{
		struct Node *tmpNode = newNode(val);
		if (empty())
		{
			head = tail = tmpNode;
			return;
		}
		tmpNode->next = head;
		head->prev = tmpNode;
		head = tmpNode;
	}
	int insert_at(int val, int pos)
	{
		struct Node *tmpNode = newNode(val);
		struct Node *curr = head;
		int index = 0;
		if (empty() && pos == index)
		{
			head = tail = tmpNode;
			return;
		}
		while (curr != NULL)
		{
			index++;
			if (index == pos)
				break;
			curr = curr->next;
		}
		if (index == pos)
		{
			// Insert node at given pos.
			tmpNode->next = curr->next;
			curr->next->prev = tmpNode;
			tmpNode->prev = curr;
			curr->next = tmpNode;
		}
	}

	int delete_at(int val)
	{
		struct Node *curr = head;
		int index = -1;
		if (head == tail)
		{
			if (head->data == val)
			{
				head = tail = NULL;
				free(curr);
				return 0;
			}
			return index;
		}
		while (curr->next != NULL)
		{
			index++;
			curr = curr->next;
			if (curr->data == val)
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				curr->next = NULL;
				curr->prev = NULL;
				free(curr);
				return index;
			}
		}
		if (curr != NULL)
			return -1;
	}

	struct Node *find(int value)
	{
		struct Node *curr = head;
		while (curr->next != NULL)
		{
			if (curr->data == value)
				return curr;
		}
		return NULL;
	}

  private:
	struct Node *newNode(int val)
	{
		struct Node *node = (struct Node *)malloc(sizeof(struct Node));
		node->data = val;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
};

int main()
{
	struct Node *head, *tail;
}
