#include <iostream>

using namespace std;

int insert(int arr[], int len, int index, int value)
{
    for(int i=len-1; i>=0; i--)
    {
        // Put value at index then exit.
        // No need to move elements lesser than index.
        if(i == index)
        {
	    arr[i+1] = arr[i];
            arr[i] = value;
            len++;
            break;
        }
        else if(i>index)
        {
            // Move ith index in i+1 index.
            arr[i+1] = arr[i];
        }
    }
    return len;
}

int deleteVal(int arr[], int len, int value)
{
    int foundIndex = len;
    for(int i=0; i<len; i++)
    {
        if(arr[i] == value)
        {
            foundIndex = i;
        }
        if(i>foundIndex)
        {
            // Move 1 position left to its position.
            arr[i-1] = arr[i];
        }
    }
    return len-1;
}

int find(int arr[], int len, int value)
{
    // If not found it returns -1.
    int found = -1;
    for(int i=0; i<len; i++)
    {
        // Set the found index if value found in array.
        if(arr[i] == value)
        {
            found = i;
        }
    }
    return found;
}

void printArray(int inp[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout<<inp[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char *argv[])
{
	int input[] = {-1, 9, -10, 5, 13};
	int len = sizeof(input) / sizeof(input[0]);

	cout<<"Input Array: "<<endl;
	printArray(input, len);

	len = insert(input, len, 2, 41);
	cout<<"After inserting 41 at 2nd position: "<<endl;
	printArray(input, len);

	len = deleteVal(input, len, 41);
	cout<<"Now after deleting 41 array is: "<<endl;
	printArray(input, len);

	int index = find(input, len, 5);
	cout<<"Found 5 at index: "<<index<<endl;

	return 0;
}
