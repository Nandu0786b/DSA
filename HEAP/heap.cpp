// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;
class Heap{
    public:
        int arr[100];
        int s;
        
        Heap(){
            arr[0]=-1;
            s=0;
        }
        
        void insert(int value){
            s++;
            int index=s;
            arr[index]=value;
            
            while(index>1){
                int parent=index/2;
                
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }
        void delet(){
            if(s==0){
                cout<<"Nothing for the delete";
                return;
            }
            arr[1]=arr[s];
            s--;
            int i=1;
            //take root node to the it's correct position
            while(i<s){
                int left=2*i;
                int right=2*i+1;
                if(left<s && arr[i]<arr[left] && arr[left]>arr[right]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                else if(right<s && arr[i]<arr[right]){
                    swap(arr[i],arr[right]);
                    i=right;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=this->s;i++){
                cout<<arr[i]<<" ";
            }
        }
};
int main() {
    // Write C++ code here
    Heap n;
    n.insert(5);
    n.insert(3);
    n.insert(10);
    n.insert(7);
    n.insert(30);
    n.insert(4);
    n.insert(35);
    n.print();
    n.delet();
    cout<<endl;
    n.print();
    return 0;
}

// Deletion using the heapify 

// C++ program for implement deletion in Heaps
//in this i am starting index from 0
//This is using the recursion

#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
	// Get the last element
	int lastElement = arr[n - 1];

	// Replace root with last element
	arr[0] = lastElement;

	// Decrease size of heap by 1
	n = n - 1;

	// heapify the root node
	heapify(arr, n, 0);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{
	// Array representation of Max-Heap
	//	 10
	// / \
	// 5 3
	// / \
	// 2 4
	int arr[] = { 35,10,30,3,7,4,5 };

	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	deleteRoot(arr, n);

	printArray(arr, n);

	return 0;
}