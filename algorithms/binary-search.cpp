#include <iostream>

using namespace std;

void printArray(int inp[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout<<inp[i]<<" ";
	}
	cout<<endl;
}

int binSearchUtil(int inp[], int start, int end, int elm)
{
	if(start < end)
	{
		int mid = (start+end) / 2;
		if(inp[mid] == elm)
		{
			return mid;
		}
		else if(inp[mid] < elm)
		{
			return binSearchUtil(inp, mid+1, end, elm);
		}
		else
		{
			return binSearchUtil(inp, 0, mid, elm);
		}
	}
	return -1;
}

int binarySearch(int inp[], int len, int elm)
{
	return binSearchUtil(inp, 0, len, elm);
}

int main(int argc, char* argv[])
{
	int inp[] = {2, 8, 10, 15, 21, 29, 33};
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Input Array: "<<endl;
	printArray(inp, len);

	cout<<"Element 15 found at location(-1 if not found): "
		<<binarySearch(inp, len, 15)<<endl;
	cout<<"Element 25 found at location(-1 if not found): "
		<<binarySearch(inp, len, 25)<<endl;
	return 0;
}
