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

void mergeArrays(int inp[], int left, int mid, int right)
{
	int len1 = mid - left + 1;
	int len2 = right - mid;

	int leftArr[len1];
	int rightArr[len2];

	int k = left;

	for(int i=0; i < len1; i++)
		leftArr[i] = inp[left + i];
	for(int i=0; i<len2; i++)
		rightArr[i] = inp[mid + 1 + i];

	int i = 0, j = 0;
	while(i < len1 && j < len2)
	{
		if(leftArr[i] <= rightArr[j])
		{
			inp[k] = leftArr[i];
			i++;
		}
		else
		{
			inp[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while(i < len1)
	{
		inp[k] = leftArr[i];
		i++, k++;
	}
	while(j < len2)
	{
		inp[k] = rightArr[j];
		j++, k++;
	}
}

void mergeSort(int inp[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(inp, left, mid);
		mergeSort(inp, mid+1, right);
	
		mergeArrays(inp, left, mid, right);
	}
}

int main(int argc, char* argv[])
{
	int inp[] = {5, 8, -9, 2, 12, -4};
	int len = sizeof(inp) / sizeof(inp[0]);
	
	cout<<"Input Array is: "<<endl;
	printArray(inp, len);
	mergeSort(inp, 0, len);
	cout<<"Sorted Array: "<<endl;
	printArray(inp, len);
}
