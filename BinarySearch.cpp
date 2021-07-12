/* Binary Search Analysis
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 4th Semester
Roll No.: 19HCS4048
*/

#include <iostream>

using namespace std;

// Function to generate an array in sorted array
void generate_array(int *array, int size)
{
    for(int index = 0; index < size; ++index)
        array[index] = index;
}

// Function to search an element in array binearly
int binary_search(int *array, int size, int element)
{
    int lower_bound = 0, upper_bound = size - 1, count = 0;

    while(lower_bound <= upper_bound)
    {
        int mid = (lower_bound + upper_bound) / 2;

        if(array[mid] == element)
        {
            count++;
            return count;
        }
        
        if(array[mid] < element)
        {
            count++;
            lower_bound = mid + 1;
        }
        else
        {
            count++;
            upper_bound = mid - 1;
        }
    }

    return count;
}

int main()
{
    int size, *array, element, no_of_comparison;
    char choice;

    cout << "Enter the size of inputs in an array: ";
    cin >> size;

    array = new int[size];
    generate_array(array, size);

    do
    {
        cout << "Enter the element to find: ";
        cin >> element;

        no_of_comparison = binary_search(array, size, element);

        cout << "Number of comparisons: " << no_of_comparison;

        cout << "\nDo you want to continue search with same input size: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    delete[] array;

    return 0;
}
