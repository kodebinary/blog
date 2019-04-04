#include <iostream>

using namespace std;

void printArray(int inp[], int len)
{
	for(int i=0; i<len; i++)
		cout<<inp[i]<<" ";
	cout<<endl;
}

int calcInterval(int len)
{
	int result = 0;
	while(result < len / 3)
		result = result * 3 + 1;
	return result;
}

void shellSort(int inp[], int len)
{
	int interval = calcInterval(len);

	for(; interval > 0; interval /= 3)
	{
		for(int j=interval; j<len; j++)
		{
			int temp = inp[j];
			int k;
			for(k=j; k>=interval &&
			 	inp[k-interval] > temp;
				k -= interval)
			{
				inp[k] = inp[k-interval];
			}
			inp[k] = temp;
		}
	}
	
}

int main(int argc, char* argv[])
{
	int inp[] = {4, -10, 11, 9, 41, 16, 5};
	int len = sizeof(inp) / sizeof(inp[0]);
	
	cout<<"Input Array: "<<endl;
	printArray(inp, len);
	shellSort(inp, len);
	cout<<"Sorted Array: "<<endl;
	printArray(inp, len);

	return 0;
}
