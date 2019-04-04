#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparator(int a, int b) { return (a<b); }

/*
*	Name: pairExistsWithSumSorted
*	Inputs:	1. Array of integers.
*		2. Length of the input array.
*		3. Value of integer X.
*	Output: Returns True / False (bool).
*	Desc: This function return true if there is any pair
*	exists in inp[] array which sums up to value x, other
*	wise returns false.
*/
bool pairExistsWithSumSorted(int inp[], int len, int x)
{
	vector<int> input(inp, inp+len);

	sort(input.begin(), input.end(), comparator);
	int start=0;
	int end = len-1;
	while(start<end)
	{
		int sum = input[start]+input[end];
		if(sum == x)
			return true;
		else if(sum < x)
			start++;
		else
			end--;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int inp[] = {-2, 5, 9, -8, 4, 1};
	int x = 14;
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Pair exists with sum "<<x<<": "<<(pairExistsWithSumSorted(inp, len, x) ? "TRUE":"FALSE")<<endl;
	return 0;
}
