#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparator(int a, int b) { return (a<b); }

bool pairExistsWithProductSorted(int inp[], int len, int x)
{
	vector<int> input(inp, inp+len);

	sort(input.begin(), input.end(), comparator);
	int start=0;
	int end = len-1;
	while(start<end)
	{
		int prod = input[start]*input[end];
		if(prod == x)
			return true;
		else if(prod < x)
			start++;
		else
			end--;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int inp[] = {5, 9, 14, -8, 7, 4};
	int x = 36;
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Pair exists with product "<<x<<": "<<(pairExistsWithProductSorted(inp, len, x) ? "TRUE":"FALSE")<<endl;
	return 0;
}
