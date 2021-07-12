/* Heap Sort Analysis using Max Heap
 * Name: Shivam Verma
 * Course: B.Sc. (H) Computer Science
 * Semester: 4th
 * Roll No.: 19HCS4048
*/

#include<bits/stdc++.h>
using namespace std;

int count=0;

void generate_random_array(int *array, int size) {
    srand(time(nullptr));

    for(int index = 0; index < size; ++index)
        array[index] = (rand() % size) + 1;
}

void show_array(int *array, int size) {
    for(int index = 0; index < size; ++index)
        cout << array[index] << " ";

    cout << endl;
}

void max_heapify(int *array, int n, int index) {
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
        max_heapify(array, n, largest);
    }
}

void heapsort(int *array, int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        max_heapify(array,n,i);

    for(int i = n - 1; i >= 0; i--) {
        swap(array[0],array[i]);
        max_heapify(array,i,0);
    }
}

int main()
{
    char choice;

    do{
        int size;

        cout << "\n Enter the number of elements : ";
        cin >> size;
        int *array = new int[size];

        generate_random_array(array, size);
        show_array(array, size);
        //heapsort(A, A + size); // for best case
        //heapsort(A, A + size, greater<int>()); // for worst case
        heapsort(array, size);
        show_array(array, size);

        cout << "\n Number of comparisons: " << ::count;
        ::count = 0;

        cout << "\n Do you wish to continue? (Y/N): ";
        cin >> choice;
    }while(choice == 'y'|| choice == 'Y');

    return 0;
}
