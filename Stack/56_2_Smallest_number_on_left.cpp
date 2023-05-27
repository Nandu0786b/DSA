// Smallest number on left
// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

// medium


// same as the previous only for loop is changed

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        stack<int>s;
        s.push(-1);
        vector<int>a(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()>=curr){
                s.pop();
            }
            a[i]=s.top();
            s.push(curr);
        }   
    return a;
    }
};