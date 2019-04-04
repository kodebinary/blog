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
		cout<<inp[i]<<" ";
	cout<<endl;
}

int quickSortUtil(int inp[], int start, int end)
{
	int pivot = end - 1;
	int left = start - 1;

	for(int i=start; i<end-1; i++)
	{
		if(inp[i] < inp[pivot])
		{
			left++;
			swap(inp[left], inp[i]);
		}
	}
	swap(inp[left+1], inp[pivot]);
	return left+1;
}

void quickSort(int inp[], int start, int end)
{
	if(start < end)
	{
		int pivot = quickSortUtil(inp, start, end);
		quickSort(inp, start, pivot);
		quickSort(inp, pivot+1, end);
	}
}

int main(int argc, char* argv[])
{
	int inp[] = {12, 8, -7, 10, 4, 2, 9};
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Input Array: "<<endl;	
	printArray(inp, len);

	quickSort(inp, 0, len);
	cout<<"Sorted Array: "<<endl;
	printArray(inp, len);

	return 0;
}
