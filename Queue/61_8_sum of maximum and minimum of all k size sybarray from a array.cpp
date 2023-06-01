// Sum of minimum and maximum elements of all subarrays of size k.
// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

// basically ek previous question kiya tha same who hi approach hain bus yaha pa 2 queue ki need hain ma ma maximum element honga and mi ma minimum element honga
#include <iostream>
#include<queue>
using namespace std;
int solve(int* arr,int n,int k){
    deque<int>ma;
    deque<int>mi;
    int ans=0;
    // handle first k size window
    for(int i=0;i<k;i++){
    while(!ma.empty() &&arr[ma.back()]<=arr[i]){
            ma.pop_back();
        
    }
    while(!mi.empty() &&arr[mi.back()]>=arr[i]){
        mi.pop_back();
    }
    ma.push_back(i);
    mi.push_back(i);
    }
    ans+=arr[ma.front()]+arr[mi.front()];
    // handle remaining windows
    for(int i=k;i<n;i++){
        // start next window
        while(!ma.empty() && i-ma.front()>=k){
            ma.pop_back();
        }
        while(!mi.empty() && i-mi.front()>=k){
            mi.pop_back();
        }
                //addition

        while(!ma.empty() && arr[ma.back()] <= arr[i])
            ma.pop_back();
        while(!mi.empty() && arr[mi.back()] >= arr[i])
            mi.pop_back();
        ma.push_back(i);
        mi.push_back(i);
        ans+=arr[ma.front()]+arr[mi.front()];
    }
    
    return ans;
    
    
}
int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}