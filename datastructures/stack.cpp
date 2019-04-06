#include <iostream>

using namespace std;

class Stack
{
private:
	int *inp;
	int cap;
	int top;
public:
	Stack()
	{
		cap = 0;
		top = 0;
	}
	Stack(int capacity)
	{
		cap = capacity;
		top = 0;
		inp = new int[cap];
	}

	void push(int val)
	{
		if(top < cap)
		{
			inp[top] = val;
			top++;
		}
	}
	int pop(void)
	{
		int ret;
		if(top > 0)
		{
			ret = inp[top];
			top--;
		}
		return ret;
	}
	int topVal()
	{
		return inp[top-1];
	}
	bool empty()
	{
		return top;
	}
	
};

int main(int argc, char *argv[])
{
	Stack stack(6);
	stack.push(5);
	stack.push(10);
	stack.push(8);
	stack.push(3);
	stack.push(2);
	stack.push(9);
	
	cout<<"Top element after pushing all elements in stack: "<<endl;
	cout<<stack.topVal()<<endl;
	stack.pop();
	cout<<"Top of stack after pop: "<<stack.topVal()<<endl;
	stack.pop();
	cout<<"Top of stack after pop: "<<stack.topVal()<<endl;

	return 0;
}
