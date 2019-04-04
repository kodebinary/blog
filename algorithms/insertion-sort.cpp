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

void insertionSort(int inp[], int len)
{
	for(int i=1; i<len; i++)
	{
		int curIdx = i;
	 	while(inp[curIdx] < inp[curIdx-1])
		{
			swap(inp[curIdx], inp[curIdx-1]);
			--curIdx;
			if(curIdx == 0) break;
		}
	}
}

int main(int argc, char* argv[])
{
	int inp[] = {10, 30, 14, -9, 21, -12, 5};
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Input Array: "<<endl;
	printArray(inp, len);
	insertionSort(inp, len);
	cout<<endl<<"Sorted Array: "<<endl;
	printArray(inp, len);
	return 0;
}
