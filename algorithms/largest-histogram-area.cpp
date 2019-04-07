#include <iostream>
#include <stack>

using namespace std;

int largestHistArea(int inp[], int len)
{
	stack<int> stk;
	int top, t;
	int i;
	int area, maxArea = -1;
	
	for(i=0; i<len; i++)
	{
		if(stk.empty() ||
			(inp[i] > inp[stk.top()]))
		{
			stk.push(i);
		}
		else {
			while(inp[stk.top()] > inp[i])
			{
				top = stk.top();
				stk.pop();
				if(stk.empty()) {
					area = inp[top]*i;
					if(area > maxArea)
						maxArea = area;
					break;
				}
				else
					area = inp[top]*(i-stk.top()-1);
				if(area > maxArea)
					maxArea = area;
			}
			stk.push(i);
		}
	}
	while(!stk.empty())
	{
		top = stk.top();
		stk.pop();
		if(stk.empty())
			area = inp[top]*i;
		else
			area = inp[top]*(i-stk.top()-1);
		if(area > maxArea)
			maxArea = area;
	}
	return maxArea;
}

int main(int argc, char *argv[])
{
	int inp[] = {3, 2, 5, 4, 2};
	int len = sizeof(inp) / sizeof(inp[0]);
	cout<<"Largest histogram area: "
		<<largestHistArea(inp, len)<<endl;
	return 0;
}
