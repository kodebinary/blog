#include <iostream>

using namespace std;

// Recursive approve to find subset.
bool subSetExists(int inp[], int len, int sum)
{
	if(sum == 0) return true;
	if(len == 0 && sum != 0)	return false;

	if(inp[len-1] > sum) 
		return subSetExists(inp, len-1, sum);

	return subSetExists(inp, len-1, sum) ||
		 subSetExists(inp, len-1, sum - inp[len-1]);
}

// Driver program
int main(int argc, char* argv[])
{
	int inp[] = {10, 4, 19, 8, 2, 12, 5};
	int len = sizeof(inp) / sizeof(inp[0]);
	bool hasSubset = subSetExists(inp, len, 7);
	cout<<"Subset Exists with Sum 7: "
		<<((hasSubset == true)?"TRUE":"FALSE")<<endl;
	return 0;
}
