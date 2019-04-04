#include <iostream>

using namespace std;

float avg(int a, int b)
{
	return (a + b) / 2.0f;
}

float sortedArraysMedian(int inp1[], int len1, int inp2[], int len2)
{
	int median;
	int start = 0;
	int end = len1 - 1;
	
	int offset1;
	int offset2;
	bool isOddLen = (len1 + len2) % 2 == 1;
	while(1)
	{
		offset1 = (start + end + 1) / 2;
		offset2 = (len1 + len2 + 1) / 2 - offset1;

		if(offset1 == 0)
		{
			if(isOddLen)
				return inp2[len2-1];
			else return (inp2[len2-1] + inp1[0]) / 2;
		}
		else if(offset1 >= len1)
		{
			if(isOddLen)
				return inp2[0];
			else return (inp1[len1-1] + inp2[0]) / 2;
		}
		else
		{
			if(inp2[offset2-1] < inp1[offset1] && 
				inp2[offset2] > inp1[offset1-1])
			{
				if(isOddLen)
					return max(inp1[offset1-1], inp2[offset2-1]);
				else
					return avg(
						(float)min(inp1[offset1], 
						inp2[offset2]), 
						(float)max(inp2[offset2-1], 
						inp1[offset1-1]));
			}
			else if(inp1[offset1] < inp2[offset2-1])
			{
				start = offset1;
				end = len1-1;
			}
			else // if(inp1[offset1-1] > inp2[offset2])
			{
				start = 0;
				end = offset1;
			}
		}
	}

	return median;
}

int main(int argc, char* argv[])
{
	int inp1[] = {5, 9, 12, 16, 19, 21, 28};
	int inp2[] = {2, 8, 23, 45, 81, 92};

	int len1 = sizeof(inp1) / sizeof(inp1[0]);
	int len2 = sizeof(inp2) / sizeof(inp2[0]);

	float median = (len1 > len2) ? 
			sortedArraysMedian(inp1, len1, inp2, len2) :
			sortedArraysMedian(inp2, len2, inp1, len1);
	cout<<"Median is: "<<median<<endl;

	return 0;
}
