#include <iostream>
#include <unordered_map>

using namespace std;

/*
*	Name: pairExistsWithSumUsingMap
*	Inputs:	1. Array of integers.
*		2. Length of the input array.
*		3. Value of integer X.
*	Output: Returns True / False (bool).
*	Desc: This function return true if there is any pair
*	exists in inp[] array which sums up to value x, other
*	wise returns false.
*/
bool pairExistsWithSumUsingMap(int inp[], int len, int x)
{
	unordered_map<int, int> resMap;
	for(int i=0; i<len; i++)
	{
		int res = x - inp[i];
		if(resMap.find(inp[i]) != resMap.end())
			return true;
		else
			resMap[res] = i;
	}
	return false;		
}

int main(int argc, char* argv[])
{
	int inp[] = {-2, 5, 9, -8, 4, 1};
	int x = 14;
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Pair exists with sum "<<x<<": "<<(pairExistsWithSumUsingMap(inp, len, x)?"TRUE":"FALSE")<<endl;
	return 0;
}
