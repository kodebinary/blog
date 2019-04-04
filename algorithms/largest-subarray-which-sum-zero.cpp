#include <iostream>

using namespace std;

int maxZeroSumSubarray(int inp[], int len)
{
	int maxLen = 0;
	for(int i=0; i<len; i++)
	{
		int subarraySum = 0;
		for(int j=i; j<len; j++)
		{
			subarraySum += inp[j];

			if(subarraySum == 0)
				maxLen = (maxLen > (j-i+1)) ? maxLen : j-i+1;
		}
	}
	return maxLen;
}

int main(int argc, char *argv[])
{
	int inp[] = {9, 5, -10, 4, 8, -7, 1};
	int len = sizeof(inp) / sizeof(inp[0]);
	cout<<"Length of the longest zero sum subarray is: "<<maxZeroSumSubarray(inp, len)<<endl;
	return 0;
}
