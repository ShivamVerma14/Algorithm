/* Given a set of positive integers and a sum value S, find out if there exists a subset in array whose sum is equal to given sum S using Dynamic Programming
Name: Shivam Verma
Course: B.Sc.(H) Computer Science
Semester: 4th
Roll No.: 19HCS4048
*/

#include<bits/stdc++.h>
using namespace std;

int count=0;

void generateRandomArray(int *array, int size) {
    srand(time(nullptr));

    for(int index = 0; index < size; ++index)
        array[index] = (rand() % size) + 1;
}

void generateArrayAscendingOrder(int *array, int size)
{
    for(int index = 0; index < size; ++index)
        array[index] = index;
}

// Function to generate an array with elements in reversed order
void generateArrayDescendingOrder(int *array, int size)
{
    int element = size;
    for(int index = 0; index < size; ++index)
        array[index] = element--;
}

void showArray(int *array, int size) {
    for(int index = 0; index < size; ++index)
        cout << array[index] << " ";

    cout << endl;
}

void maxHeapify(int *array, int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right= 2 * index + 2;

    if(left < n && array[left] > array[largest]) {
        ::count++;
        largest=left;
    }

    if(right < n && array[right] > array[largest]) {
        largest = right;
        ::count++;
    }

    if(largest != index) {
        swap(array[largest],array[index]);
        maxHeapify(array, n, largest);
    }
}

void heapsort(int *array, int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(array,n,i);

    for(int i = n - 1; i >= 0; i--) {
        swap(array[0],array[i]);
        maxHeapify(array,i,0);
    }
}

int main()
{
    char first_choice, second_choice;
    int size, *array;

    cout << "**** Case Scenario ****\n";
    cout << "1. Random Case\n";
    cout << "2. Best Case\n";
    cout << "3. Worst Case\n";
    cout << "Enter your choice: ";
    cin >> first_choice;

    do{

        cout << "Enter the size of array: ";
        cin >> size;

        array = new int[size];

        switch(first_choice) 
        {
            case '1':
                generateRandomArray(array, size);
                heapsort(array, size);
                break;

            case '2':
                generateArrayAscendingOrder(array, size);
                heapsort(array, size);
                break;

            case '3':
                generateArrayDescendingOrder(array, size);
                heapsort(array, size);
                break;

            default:
                cout << "Wrong choice of option!!!\n";
        }

        cout << "\nNumber of comparisons: " << ::count;
        ::count = 0;

        cout << "\nDo you wish to continue? (Y/N): ";
        cin >> second_choice;

    } while(second_choice == 'y'|| second_choice == 'Y');

    delete[] array;

    return 0;
}