
#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}

// Driver Code
int main()
{
    int n,i;
    int arr[1000];
    cout<<"Please Enter the Size of Array = ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	cout << " Number of inversions are "
		<< getInvCount(arr, n);
	return 0;
}

// This code is contributed
// by Akanksha Rai
