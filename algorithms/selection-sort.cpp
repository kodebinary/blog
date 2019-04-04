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

void selectionSort(int inp[], int len)
{
	int maxIndex;
	for(int i=0; i<len; i++)
	{
		maxIndex = 0;
		for(int j=0; j<len-i; j++)
		{
			if(inp[maxIndex] < inp[j])
			{
				maxIndex = j;
			}
		}
		swap(inp[maxIndex], inp[len-i-1]);
	}
}

int main(int argc, char* argv[])
{
	int inp[] = {20, 10, 5, 30, 45, 9, -12};
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Input Array: "<<endl;
	printArray(inp, len);
	selectionSort(inp, len);
	cout<<"\nSorted Array: "<<endl;
	printArray(inp, len);
	
	return 0;
}
