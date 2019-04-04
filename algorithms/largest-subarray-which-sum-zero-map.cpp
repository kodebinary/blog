#include <iostream>
#include <unordered_map>

using namespace std;

int maxOptimisedZeroSum(int inp[], int len)
{
	int maxLen = 0;
	unordered_map<int, int> sumMap;
	int sum = 0;

	for(int i=0; i<len; i++)
	{
		sum+=inp[i];
		
		if(sum == 0)
		{
			maxLen = i+1;
		}
		if(sumMap.find(sum) != sumMap.end())
		{
			maxLen = maxLen > i - sumMap[sum] ? maxLen : i - sumMap[sum];
		}
		else
		{
			sumMap[sum] = i;
		}
	}
	return maxLen;
}

int main(int argc, char* argv[])
{
	int inp[] = {9, 5, -10, 4, 8, -7, 1};
	int len = sizeof(inp) / sizeof(inp[0]);
	cout<<"Length of the longest zero sum subarray is: "<<maxOptimisedZeroSum(inp, len)<<endl;
	return 0;
}
