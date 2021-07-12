/* Quick Sort Analysis
 * Name: Shivam Verma
 * Course: B.Sc. (H) Computer Science
 * Semester: 4th
 * Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

int count = 0;

void generate_random_array(int *array, int size) {
    srand(time(nullptr));

    for(int index = 0; index < size; ++index)
        array[index] = (rand() % size) + 1;
}

void generate_sorted_array(int *array, int size) {
    for(int index = 0; index < size; ++index)
        array[index] = index + 1;
}

void generate_unsorted_array(int *array, int size) {
    int element = size;
    for(int index = 0; index < size; ++index)
        array[index] = element--;
}

void show_array(int *array, int size) {
    for(int index = 0; index < size; ++index)
        cout << array[index] << " ";

    cout << endl;
}

int partition(int *array, int lower_bound, int upper_bound) {
    int pivot = upper_bound, index = lower_bound;

    for(int i = lower_bound; i <= upper_bound; ++i) {
        ::count++;
        if(array[i] < array[pivot]) {
            swap(array[i], array[index]);
            index++;
        }
    }

    swap(array[pivot], array[index]);

    return index;
}

int random_pivot_partition(int *array, int lower_bound, int upper_bound) {
    srand(time(nullptr));

    int pivot = lower_bound + rand() % (upper_bound - lower_bound);
    swap(array[upper_bound], array[pivot]);
    return partition(array, lower_bound, upper_bound);
}

void quick_sort(int *array, int lower_bound, int upper_bound) {
    if(lower_bound < upper_bound) {
        int pivot_index = random_pivot_partition(array, lower_bound, upper_bound);
        quick_sort(array, lower_bound, pivot_index - 1);
        quick_sort(array, pivot_index + 1, upper_bound);
    }
}

int main() {
    int size, *array;
    char first_choice, second_choice;

    do {
        cout << "**** CASE SCENARIO ****\n";
        cout << "1. Best Case\n";
        cout << "2. Average Case\n";
        cout << "3. Worst Case\n";
        cout << "Enter your choice: ";
        cin >> first_choice;

        switch(first_choice) {
            case '1' :
                do {
                    cout << "Enter the size of Array: ";
                    cin >> size;
                    array = new int[size];

                    generate_sorted_array(array, size);

                    quick_sort(array, 0, size - 1);

                    cout << "\nNumber of comparisons: " << ::count;
                    ::count = 0;

                    cout << "\nDo you want to continue on same case scenario? (Y/N): ";
                    cin >> second_choice;
                }while (second_choice == 'Y' || second_choice == 'y');

                break;

            case '2' :
                do {
                    cout << "Enter the size of Array: ";
                    cin >> size;
                    array = new int[size];

                    generate_random_array(array, size);

                    quick_sort(array, 0, size - 1);

                    cout << "\nNumber of comparisons: " << ::count;
                    ::count = 0;

                    cout << "\nDo you want to continue on same case scenario? (Y/N): ";
                    cin >> second_choice;
                }while (second_choice == 'Y' || second_choice == 'y');

                break;

            case '3' :
                do {
                    cout << "Enter the size of Array: ";
                    cin >> size;
                    array = new int[size];

                    generate_unsorted_array(array, size);

                    quick_sort(array, 0, size - 1);

                    cout << "\nNumber of comparisons: " << ::count;
                    ::count = 0;

                    cout << "\nDo you want to continue on same case scenario? (Y/N): ";
                    cin >> second_choice;
                }while (second_choice == 'Y' || second_choice == 'y');

                break;

            default : cout << "Wrong choice of Options!!!\n";
        }

        cout << "Do you want to continue on different case scenario? (Y/N): ";
        cin >> first_choice;
    }while (first_choice == 'Y' || first_choice == 'y');
}

