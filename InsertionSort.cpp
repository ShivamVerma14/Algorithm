/* Insertion Sort Analysis
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

// Function to generate an array with sorted elements
void generate_array_ascending_order(int *array, int size)
{
    for(int index = 0; index < size; ++index)
        array[index] = index;
}

// Function to generate an array with elements in reversed order
void generate_array_descending_order(int *array, int size)
{
    int element = size;
    for(int index = 0; index < size; ++index)
        array[index] = element--;
}

// Function to sort the elements of an array through Insertion Sort
int insertion_sort(int *array, int size)
{
    int key, j, count = 0;
    for(int i = 1; i < size; ++i)
    {
        key = array[i];
        j = i;
        count++;
        while(j > 0 && array[j - 1] > key)
        {
            if(array[j - 1] > key)
                count++;
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
    return count;
}

int main()
{
    int size, *array;
    char choice;

    do
    {
        cout << "Enter the size of array: ";
        cin >> size;

        array = new int[size];

        // generate_random_array(array, size);
        // generate_array_ascending_order(array, size);
        generate_array_descending_order(array, size);

        int no_of_comparisons = insertion_sort(array, size);

        cout << "Number of comparisons: " << no_of_comparisons << endl;

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;

    }while(choice == 'Y' || choice == 'y');

    return 0;
}