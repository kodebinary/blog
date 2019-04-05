#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

class CircularList
{
	private:
		struct Node *head;

		struct Node *createNode(int val)
		{
			struct Node *tmp =
				(struct Node*)malloc(sizeof(struct Node));
			tmp->data = val;
			tmp->next = NULL;
			return tmp;
		}
	public:
		CircularList()
		{
			head = NULL;
		}
		CircularList(int inp[], int len)
		{
			head = createNode(inp[0]);
			struct Node* curr=head;
			for(int i=1; i<len; i++)
			{
				curr->next = createNode(inp[i]);
				curr = curr->next;
			}
			curr->next = head;
		}
		~CircularList()
		{
			struct Node *curr = head;
			curr = curr->next;
			head->next = NULL;
			// Free list.
			while(curr != NULL)
			{
				struct Node *tmp = curr;;
				curr = curr->next;
				tmp->next = NULL;
				free(tmp);
			}
		}
		void insertEnd(int val);
		void insertBegin(int val);
		void deleteAt(int pos);
		void print() {
			struct Node *curr = head;
			while(curr->next != head)
			{
				cout<<curr->data<<"-->";
				curr = curr->next;
			}
			cout<<curr->data<<"-->"<<head->data<<endl;
		}
};

void CircularList::insertEnd(int val)
{
	struct Node *curr = head;
	if(head == NULL)
	{
		cout<<"Can't insert, list is empty"<<endl;
		return ;
	}
	while(curr->next != head)
	{
		curr = curr->next;
	}
	struct Node *tmpNode = createNode(val);
	tmpNode->next = head;
	curr->next = tmpNode;
}

void CircularList::insertBegin(int val)
{
	struct Node *curr=head;
	struct Node *tmpNode = createNode(val);
	if(head == NULL)
	{
		head = tmpNode;
		head->next = head;
		return ;
	}
	tmpNode->next = head;
	while(curr->next != head)
	{
		curr = curr->next;
	}
	curr->next = tmpNode;
	head = tmpNode;
}

void CircularList::deleteAt(int pos)
{
	int idx = 0;
	struct Node *curr = head;
	if(pos == 0)
	{
		while(curr->next != head)
		{
			curr = curr->next;
		}
		curr->next = head->next;
		head->next = NULL;
		free(head);
		head = curr->next;
	}
	while(curr->next != head && idx < pos-1)
	{
		idx++;
		curr = curr->next;
	}
	struct Node *tmp = curr->next;
	curr->next = curr->next->next;
	tmp->next = NULL;
	free(tmp);
}

int main(int argc, char* argv[])
{
	int list[] = {20, 15, 5, 10, 12};
	int len = sizeof(list) / sizeof(list[0]);
	CircularList dll(list, len);
	dll.print();
	dll.insertBegin(24);
	cout<<"After inserting 24 at beign "<<endl;
	dll.print();
	dll.insertEnd(9);
	cout<<"After inserting 9 at end: "<<endl;
	dll.print();
	dll.deleteAt(2);
	cout<<"Delete at position 2: "<<endl;
	dll.print();

	return 0;
}
