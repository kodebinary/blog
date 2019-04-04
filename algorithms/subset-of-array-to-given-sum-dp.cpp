#include <iostream>

using namespace std;

bool subsetArraySum(int inp[], int len, int sum)
{
	bool dp[len][sum+1];
	
	for(int i=0; i<=sum; i++)
	{
		dp[0][i] = (inp[0] == i);
	}
	for(int i=1; i<len; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			dp[i][j] = (inp[i] == j) || dp[i-1][j];
			if(j > inp[i])
				dp[i][j] |= dp[i-1][j-inp[i]];
		}
	}
	return dp[len-1][sum];
}

int main(int argc, char* argv[])
{
	int inp[] = {5, 2, 10, 12, 9, 21};
	int len = sizeof(inp) / sizeof(inp[0]);
	int sum = 15;
	
	int result = subsetArraySum(inp, len, sum);
	cout<<"Subarray with sum 15 found: "
		<<((result == true)?"TRUE":"FALSE")<<endl;
	return 0;
}
