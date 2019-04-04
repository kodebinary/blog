#include <iostream>

using namespace std;

bool pairExistsWithProduct(int inp[], int len, int x)
{
	for(int i=0; i<len; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(inp[i] * inp[j] == x)
				return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	int inp[] = {5, 9, 14, -8, 7, 4};
	int x = 36;
	int len = sizeof(inp) / sizeof(inp[0]);
	cout<<"Pair exists with product "<<x<<": "<<(pairExistsWithProduct(inp, len, x) ? "TRUE" : "FALSE")<<endl;
	return 0;
}
