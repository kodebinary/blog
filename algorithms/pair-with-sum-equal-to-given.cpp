#include <iostream>

using namespace std;

/*
*	Name: pairExistsWithSum
*	Inputs:	1. Array of integers.
*		2. Length of the input array.
*		3. Value of integer X.
*	Output: Returns True / False (bool).
*	Desc: This function return true if there is any pair
*	exists in inp[] array which sums up to value x, other
*	wise returns false.
*/

bool pairExistsWithSum(int inp[], int len, int x)
{
	for(int i=0; i<len; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(inp[i] + inp[j] == x)
				return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	int inp[] = {-2, 5, 9, -8, 4, 1};
	int x = 14;
	int len = sizeof(inp) / sizeof(inp[0]);
	cout<<"Pair exists with sum "<<x<<": "<<(pairExistsWithSum(inp, len, x)?"TRUE":"FALSE")<<endl;
	return 0;
}
