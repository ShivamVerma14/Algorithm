/* Given a set of positive integers and a sum value S, find out if there exists a subset in array whose sum is equal to given sum S using Dynamic Programming.
Name: Shivam Verma
Course: B.Sc. (H) Computer Science
Semester: 4th 
Roll No: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i
    bool subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= sum; j++)
		{
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }
    return subset[n][sum];
}

int main()
{
	int size, target_sum;

	cout << "Enter the Size of Array: ";
	cin >> size;
	int *arr = new int[size];

	cout << "Enter the Elements in Array: ";
	for(int i=0; i < size; i++)
		cin >> arr[i];

	cout << "Entered array is ";
	for(int i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "Enter the Target Sum: ";
	cin >> target_sum;

    if (isSubsetSum(arr, size, target_sum) == true)
        cout << "Target Found a subset with given sum";
    else
        cout << "No subset with given sum";
        
    return 0;
}