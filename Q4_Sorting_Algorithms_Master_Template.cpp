/*
 * Q4 - SORTING ALGORITHMS MASTER TEMPLATE
 * ========================================
 *
 * Purpose
 * -------
 * Use this file as:
 *
 * 1. a revision guide for sorting questions;
 * 2. a clean example that can be opened and explained in VS Code; and
 * 3. a starting point for exam answers.
 *
 * The active example demonstrates bubble sort. Other sorting algorithms listed
 * in the function bank can be added using the same structure.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// ============================================================================
// 1. EXAM QUESTION CHECKLIST
// ============================================================================

/*
 * Before writing any code, identify the following:
 *
 * (a) Which sorting algorithm is required?
 *     Bubble sort, selection sort, insertion sort, quicksort or merge sort?
 *
 * (b) Must the algorithm be written from scratch, or must faulty code be fixed?
 *     When fixing code, read every line and check the common planted errors.
 *
 * (c) Is the required order ascending or descending?
 *
 *     Ascending bubble sort:
 *         if (array[index] > array[index + 1])
 *
 *     Descending bubble sort:
 *         if (array[index] < array[index + 1])
 *
 *     For descending order, reverse the relevant comparisons.
 *
 * (d) Is a function template required?
 *     A template may need to work with both numbers and strings.
 *
 * (e) Should the program use given values or generate random values?
 *
 * (f) Are any additional operations required?
 *     Examples: find duplicates, perform a binary search, or print the array
 *     before and after sorting.
 *
 * (g) Must the program state the time complexity?
 */

// ============================================================================
// 2. FUNCTION BANK
// ============================================================================

/*
 * SORTING FUNCTIONS
 *
 * void bubbleSort(int* array, int size);
 * int* selectionSort(int* array, int size);
 * int* insertionSort(int* array, int size);
 * void quickSort(int* array, int first, int last);
 * void mergeSort(int* array, int left, int right);
 *
 * HELPER FUNCTIONS
 *
 * bool isSorted(const int* array, int size);
 * void swapValues(int& first, int& second);
 * void printArray(const int* array, int size);
 * void findDuplicates(const int* array, int size);
 * int binarySearch(
 *     const int* array,
 *     int first,
 *     int last,
 *     int key);
 *
 * TEMPLATE VERSIONS
 *
 * template <typename T>
 * void bubbleSort(T* array, int size);
 *
 * template <typename T>
 * void printArray(const T* array, int size);
 */

// ============================================================================
// 3. COMPLEXITY QUICK REFERENCE
// ============================================================================

/*
 * Bubble sort:    O(n^2)
 * Selection sort: O(n^2)
 * Insertion sort: O(n^2)
 * Quicksort:      O(n log n) average, O(n^2) worst case
 * Merge sort:     O(n log n)
 */

// ============================================================================
// 4. BUBBLE SORT FOR INTEGER ARRAYS
// ============================================================================

/*
 * Bubble sort repeatedly compares adjacent values.
 *
 * For ascending order, two adjacent values are swapped when the value on the
 * left is greater than the value on the right.
 *
 * The 'sorted' flag allows the algorithm to stop early when a complete pass
 * performs no swaps.
 */
void bubbleSort(int *array, int size)
{
    bool sorted;

    do
    {
        sorted = true;

        // Stop at size - 1 because the loop reads array[index + 1].
        for (int index = 0; index < size - 1; ++index)
        {
            if (array[index] > array[index + 1])
            {
                const int temporary = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temporary;

                // At least one swap occurred, so another pass is required.
                sorted = false;
            }
        }
    } while (!sorted);
}

// ============================================================================
// 5. COMMON BUBBLE-SORT BUGS
// ============================================================================

/*
 * BUG 1
 * -----
 * Incorrect:
 *     while (sorted);
 *
 * Correct:
 *     while (!sorted);
 *
 * Reason:
 *     Another pass is required when the previous pass performed a swap.
 *
 *
 * BUG 2
 * -----
 * Incorrect:
 *     for (int index = 0; index < size; ++index)
 *
 * Correct:
 *     for (int index = 0; index < size - 1; ++index)
 *
 * Reason:
 *     The loop accesses array[index + 1]. If index reaches size - 1, the code
 *     attempts to read array[size], which is outside the array.
 *
 *
 * BUG 3
 * -----
 * Incorrect:
 *     array[index + 1] = array[index];
 *
 * Correct:
 *     array[index + 1] = temporary;
 *
 * Reason:
 *     The original value from array[index] has already been overwritten. The
 *     saved temporary value must be assigned to array[index + 1].
 */

// ============================================================================
// 6. TEMPLATE BUBBLE SORT
// ============================================================================

/*
 * This version works with any type that supports operator>.
 *
 * Examples include int, short, double and std::string.
 */
template <typename T> void bubbleSort(T *array, int size)
{
    bool sorted;

    do
    {
        sorted = true;

        for (int index = 0; index < size - 1; ++index)
        {
            if (array[index] > array[index + 1])
            {
                const T temporary = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temporary;
                sorted = false;
            }
        }
    } while (!sorted);
}

// ============================================================================
// 7. GENERIC ARRAY-PRINTING FUNCTION
// ============================================================================

template <typename T> void printArray(const T *array, int size)
{
    for (int index = 0; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}

// ============================================================================
// 8. OPTIONAL DYNAMIC RANDOM-ARRAY EXAMPLE
// ============================================================================

/*
 * This is a separate function rather than a second main() function.
 * Call it from main() when the question requires a dynamic random array.
 */
void demonstrateDynamicRandomArray()
{
    int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0)
    {
        std::cout << "The array size must be greater than zero.\n";
        return;
    }

    int *array = new int[size];

    // Seed the pseudo-random number generator once.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int index = 0; index < size; ++index)
    {
        array[index] = std::rand() % 51; // Values from 0 to 50 inclusive.
    }

    std::cout << "Unsorted array: ";
    printArray(array, size);

    bubbleSort(array, size);

    std::cout << "Sorted array:   ";
    printArray(array, size);

    std::cout << "Bubble sort complexity: O(n^2)\n";

    delete[] array;
}

// ============================================================================
// 9. MAIN EXAM PATTERN: GIVEN ARRAY
// ============================================================================

int main()
{
    int values[] = { 7, 3, 5, 7, 6, 1, 4, 2 };
    const int size = static_cast<int>(sizeof(values) / sizeof(values[0]));

    std::cout << "Unsorted integer array: ";
    printArray(values, size);

    bubbleSort(values, size);

    std::cout << "Sorted integer array:   ";
    printArray(values, size);

    std::cout << '\n';

    // The template version can also sort strings.
    std::string names[] = { "Tom", "Hal", "Dan", "Bob", "Sue", "Ann", "Gus" };

    const int nameCount = static_cast<int>(sizeof(names) / sizeof(names[0]));

    std::cout << "Unsorted string array:  ";
    printArray(names, nameCount);

    bubbleSort(names, nameCount);

    std::cout << "Sorted string array:    ";
    printArray(names, nameCount);

    std::cout << "\nBubble sort complexity: O(n^2)\n";

    /*
     * To demonstrate the dynamic random-array pattern instead, uncomment:
     *
     * demonstrateDynamicRandomArray();
     */

    return 0;
}