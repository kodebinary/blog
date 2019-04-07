#include <iostream>

using namespace std;

class Queue
{
protected:
	int *que;
	int rear, front, size;
	int _cap;
public:
	Queue()
	{
		_cap = 0;
		front=rear=size = 0;
	}
	Queue(int capacity)
	{
		_cap = capacity;
		que = new int[_cap];
		front = rear = size = 0;
	}
	~Queue() {}
	void printQue()
	{
		for(int i=front; i < rear; i++)
		{
			cout<<que[i]<<"  ";
		}
		cout<<endl;
	}
	bool empty() {
		return (size == 0);
	}
	bool fill() {
		return (size == _cap);
	}

	virtual void enqueue(int val) = 0;
	virtual int dequeue() = 0;
};

class LinearQueue : public Queue
{
public:
	LinearQueue(int cap)
	{
		_cap = cap;
		que = new int[_cap];
	}
        void enqueue(int val)
        {
                if(fill())
                {
                        cout<<"Queue already filled."<<endl;
                        return ;
                }
                que[rear] = val;
                size++;
                rear++;
        }
        int dequeue()
        {
                if(empty())
                {
                        cout<<"Queue is empty"<<endl;
                        return -1;
                }
                int val = que[front];
                for(int i=1; i<size; i++)
                {
                        que[i-1] = que[i];
                }
                rear--;
                size--;
		return val;
        }
};

class CircularQueue : public Queue
{
public:
	CircularQueue(int capacity) {
		_cap = capacity;
		que = new int[_cap];
	}
	void printQue()
	{
		for(int i=front; i!=(rear%_cap); i=(i+1)%_cap)
		{
			cout<<que[i]<<"  ";
		}
		cout<<endl;
	}
	void enqueue(int val)
	{
		if(fill())
		{
			cout<<"Queue already filled."<<endl;
			return ;
		}
		que[rear] = val;
		rear = (rear+1) % _cap;
		size++;
	}
	int dequeue(void)
	{
		if(empty())
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		int val = que[front];
		front = (front+1) % _cap;
		size--;
		return val;	
	}
};

int main(int argc, char* argv[])
{
	Queue *que = new LinearQueue(6);
	que->enqueue(12);
	que->enqueue(15);
	que->enqueue(9);
	que->enqueue(5);
	que->enqueue(19);
	que->enqueue(3);

	cout<<"Queue is: "<<endl;
	que->printQue();
	cout<<"Dequeue from above queue: "
		<<que->dequeue()<<endl;
	cout<<"Queue after dequeue: "<<endl;
	que->printQue();
	Queue *cque = new CircularQueue(6);
	cque->enqueue(12);
	cque->enqueue(15);
	cque->enqueue(9);
	cout<<"Circular Queue is: "<<endl;
	cque->printQue();
	cout<<"Dequeue from circular queue: "
		<<cque->dequeue()<<endl;
	cout<<"Queue after dequeue: "<<endl;
	cque->printQue();
	return 0;
}
