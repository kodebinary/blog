#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int inp[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout<<inp[i]<<" ";
	}
	cout<<endl;
}

int leftNode(int node)
{
	return 2*node + 1;
}

int rightNode(int node)
{
	return 2*node + 2;
}

void heapify(int inp[], int len, int idx)
{
	int maxIdx = idx;
	int left = leftNode(idx);
	int right = rightNode(idx);

	if(left < len && inp[left] > inp[maxIdx])
	{
		maxIdx = left;
	}
	if(right < len && inp[right] > inp[maxIdx])
	{
		maxIdx = right;
	}
	if(maxIdx != idx)
	{
		swap(inp[idx], inp[maxIdx]);
		heapify(inp, len, maxIdx);
	}
}

void heapSort(int inp[], int len)
{
	int i;
	for(i = len / 2 - 1; i >= 0; i--)
	{
		heapify(inp, len, i);
	}
	for(int i = len-1; i>=0; i--)
	{
		// Move max element at end of the array.
		swap(inp[0], inp[i]);
		// Do heapify for the reset of the array.
		heapify(inp, i, 0);
	}
}

int main(int argc, char* argv[])
{
	int inp[] = { 3, 8, 5, 10, -9, 4, -3 };
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Input Array is: "<<endl;
	printArray(inp, len);
	heapSort(inp, len);
	cout<<"Sorted Array: "<<endl;
	printArray(inp, len);

	return 0;
}
