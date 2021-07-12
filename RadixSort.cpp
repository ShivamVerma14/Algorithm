/* Radix Sort
Name: Shivam Verma
Course: B.Sc. (H) Computer Science 4th Semester
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

int get_maximum(int *array, int size) 
{
    int max = array[0];
    for(int index = 1; index < size; ++index)
        if(array[index] > max)
            max = array[index];

    return max;
}

void print(int *array, int size)
{
    for(int index = 0; index < size; ++index)
        cout << array[index] << " ";
    cout << endl;
}

void count_sort(int *array, int size, int exp)
{
    int *output = new int[size];
    int count[10] = {0};

    for(int index = 0; index < size; ++index)
        count[(array[index] / exp) % 10]++;

    for(int index = 1; index < 10; ++index)
        count[index] += count[index - 1];

    for (int index = size - 1; index >= 0; --index)
    {
        output[count[(array[index] / exp) % 10] - 1] = array[index];
        count[(array[index] / exp) % 10]--;
    }

    for (int index = 0; index < size; ++index)
        array[index] = output[index];

    delete[] output;
}

void radix_sort(int *array, int size)
{
    int max = get_maximum(array, size);

    for(int exp = 1; max / exp > 0; exp *= 10)
        count_sort(array, size, exp);
}

int main()
{
    int size;

    cout << "Enter the size of Array: ";
    cin >> size;

    int *array = new int[size];

    cout << "Enter the elements of Array... \n";
    for(int index = 0; index < size; ++index)
        cin >> array[index];

    system("cls");

    cout << "Array before Sorting: ";
    print(array, size);

    radix_sort(array, size);

    cout << "Array after Sorting: ";
    print(array, size);

    return 0;
}