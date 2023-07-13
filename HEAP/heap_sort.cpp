// C++ program for implementation of Heap Sort
//Heap sort :- basically apana first element already maximum element hain in the max heap, Now isko end ma la javo and end wala ko yaha pa la ava
//size ko 1 sa kam kar do
// ab jo current apan 1st element pa laya tha usko heapify ki help sa right position pa la javo
// now again first element max hain so again same process jab thak ki size!=1

//min heap ma iska opposite karna hain means in the above we are decreaing the size but in this every time we will get minimum at front so we will
//increase our size till it's not equal the array size

//TC=o(n*log(n))   :=> basically hamna every element ka liya call kiya hain and hamna every element pa jakar usko max heap ma bhi convert kiya hain


#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end(in this swap every time ith largest element will go in end)
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap(in this again will come new maximum element in the front)
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}
