#include <iostream>

using namespace std;

int* mergeArrays(int inp1[], int len1, int inp2[], int len2)
{
	int sum = len1 + len2;
	int *result = new int[sum];
	int i = 0, j = 0, k = 0;
	while(i < len1 && j < len2)
	{
		if(inp1[i] < inp2[j])
		{
			result[k++] = inp1[i++];
		}
		else
		{
			result[k++] = inp2[j++];
		}
	}
	while(i < len1)
	{
		result[k++] = inp1[i++];
	}
	while(j < len2)
	{
		result[k++] = inp1[j++];
	}
	return result;
}

int main(int argc, char* argv[])
{
	int inp1[] = {-1, 5, 10, 14, 17, 44};
	int inp2[] = {-3, 4, 7, 11, 19, 25};
	int len1 = sizeof(inp1) / sizeof(inp1[0]);
	int len2 = sizeof(inp2) / sizeof(inp2[0]);
	int *res;

	res = mergeArrays(inp1, len1, inp2, len2);

	bool oddLen = (len1 + len2) % 2;
	int midIdx = (len1 + len2) / 2;
	double median;
	if(oddLen)
	{
		median = res[midIdx];
	} 
	else
	{
		cout<<"Is it an even length array?"<<endl;
		median = (res[midIdx-1] + res[midIdx]) / 2.0;
	}
	cout<<"Median is: "<<median<<endl;
	return 0;
}
