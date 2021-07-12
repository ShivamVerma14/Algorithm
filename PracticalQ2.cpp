/* Given a set of positive integers and a sum value S, find out if there exists a subset in array whose sum is equal to given sum S using Dynamic Programming
Name: Shivam Verma
Course: B.Sc.(H) Computer Science
Semester: 4th
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

bool** dp;
 
void display(const vector<int>& v)
{
    for (int index = 0; index < v.size(); ++index)
        cout << v[index] << " ";

    cout << endl;
}

void printSubsets(int array[], int i, int sum, vector<int>& p)
{
    if (i == 0 && sum != 0 && dp[0][sum])
    {
        p.push_back(array[i]);
          if (array[i] == sum)
              display(p);
        return;
    }
 
    if (i == 0 && sum == 0)
    {
        display(p);
        return;
    }

    if (dp[i - 1][sum])
    {
        vector<int> b = p;
        printSubsets(array, i - 1, sum, b);
    }

    if (sum >= array[i] && dp[i - 1][sum - array[i]])
    {
        p.push_back(array[i]);
        printSubsets(array, i - 1, sum - array[i], p);
    }
}

void printAllSubsets(int arr[], int n, int sum)
{
    if (n == 0 || sum < 0)
       return;
 
    dp = new bool*[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new bool[sum + 1];
        dp[i][0] = true;
    }
 
    if (arr[0] <= sum)
       dp[0][arr[0]] = true;

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i] <= j) ? dp[i - 1][j] || dp[i - 1][j - arr[i]] : dp[i - 1][j];

    if (dp[n - 1][sum] == false)
    {
        cout << "There are no subsets with sum " << sum;
        return;
    }

    vector<int> p;
    cout << "\nThe subsets with sum " << sum << " : \n";
    printSubsets(arr, n - 1, sum, p);
}
 
int main()
{
    int *array, size, sum = 0;

    system("cls");
    
    cout << "Enter the size of Array: ";
    cin >> size;

    array = new int[size];

    cout << "Enter the elements in array...\n";
    for(int index = 0; index < size; ++index)
        cin >> array[index];

    cout << "Enter the target sum: ";
    cin >> sum;

    printAllSubsets(array, size, sum);

    return 0;
}