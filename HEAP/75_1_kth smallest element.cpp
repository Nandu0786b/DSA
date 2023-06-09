// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//TC=O(n * log(n))

//approach: kth element ka ek max heap bana lo
//Now remaining (n-k) element ko process karna start karo, if element is small then the max heap element then push this in the max heap else remove
//when all element processed then max heap root will be our answer

//if same question ask for the largest element the we will create min heap and in the second for loop we use condition arr.top()<arr[i], then remove from queue and push this
#include<queue>
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> ans;
        
        for(int i=0;i<k;i++){//TC=O(n * log(n)), n for the loop and log(n) for the max heap queue
            ans.push(arr[i]);
        }
        for(int i=k;i<=r;i++){//here we are doing i<=r because r is index not the size, same TC is here
            if(ans.top()>arr[i]){
                ans.pop();
                ans.push(arr[i]);
            }
        }
        return ans.top();
    }
};

//approach:sort array in increaing order -> TC=o(n * log(n))
//Now return kth element from the start ->TC=o(1)
