#include <iostream>
#include <unordered_map>

using namespace std;

bool pairExistsWithProductUsingMap(int inp[], int len, int x)
{
	unordered_map<int, int> resMap;
	for(int i=0; i<len; i++)
	{
		if((x % inp[i]) != 0) continue;

		int res = x / inp[i];
		if(resMap.find(inp[i]) != resMap.end())
			return true;
		else
			resMap[res] = i;
	}
	return false;		
}

int main(int argc, char* argv[])
{
	int inp[] = {5, 9, 14, -8, 7, 4};
	int x = 36;
	int len = sizeof(inp) / sizeof(inp[0]);

	cout<<"Pair exists with product "<<x<<": "<<(pairExistsWithProductUsingMap(inp, len, x)?"TRUE":"FALSE")<<endl;
	return 0;
}
