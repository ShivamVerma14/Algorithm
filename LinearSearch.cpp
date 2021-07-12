/* Linear Search Analysis
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 4th Semester
Roll No.: 19HCS4048
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate random numbers and store it in an array
void generate_random_array(int *array, int size)
{
    time_t t;
    srand((unsigned) time(&t));
    for(int index = 0; index < size; ++index)
        array[index] = rand() % 50000 + 1;
}

// Function to display array from start_index to end_index
void show_array(int *array, int start_index, int end_index)
{
    for(int index = start_index; index < end_index; ++index)
        cout << array[index] << '\n';
    
    cout << endl;
}

// Function to linearly search at element from an array and returns the number of comparisons
int linear_search(int *array, int size, int key)
{
    int count = 0;

    for(int index = 0; index < size; ++index)
    {
        count++;
        if(array[index] == key)
            return count;
    }
    
    return count;
}

int main()
{
    int size, *array, element, no_of_comparison;

    cout << "Enter the size of inputs in an array: ";
    cin >> size;

    array = new int[size];
    generate_random_array(array, size);

    /* Function calling one at a time to display 50 elements in the array */
    
    show_array(array, 0, 50);
    //show_array(array, (size / 2) - 26, (size / 2) + 25);
    //show_array(array, size - 51, size - 1);

    cout << "Enter the element to find: ";
    cin >> element;

    no_of_comparison = linear_search(array, size, element);

    cout << "Number of comparisons: " << no_of_comparison;

    delete[] array;

    return 0;
}
