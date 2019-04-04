#include <iostream>

using namespace std;

/*
* 	For swaping two input elements.
*/
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSortAlgo(int inp[], int len)
{
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len-i-1; j++)
		{
			if(inp[j] > inp[j+1])
				swap(inp[j], inp[j+1]);
		}
	}
}

void printArray(int inp[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout<<inp[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char* argv[])
{
	int inp[] = {40, 20, 30, 9, 81, -1, 47};
	int len = sizeof(inp) / sizeof(inp[0]);
	
	cout<<"Input Array: "<<endl;
	printArray(inp, len);
	bubbleSortAlgo(inp, len);

	cout<<endl<<"Sorted Array: "<<endl;
	printArray(inp, len);
	return 0;
}
