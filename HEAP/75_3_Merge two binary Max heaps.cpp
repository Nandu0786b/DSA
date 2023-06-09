// Merge two binary Max heaps
// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

class Solution {
private:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    void print(vector<int>arr){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
        }

public:
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        vector<int> merged(n + m);

        for (int i = 0; i < n; i++) {
            merged[i] = a[i];
        }

        for (int i = 0; i < m; i++) {
            merged[n + i] = b[i];
        }

        for (int i = (n + m) / 2 - 1; i >= 0; i--) {//(n+m)/2 sa start kiya hain because es ka bad wala sara ka sara leaf node honga
            heapify(merged, n + m, i);
        }

        return merged;
    }
};

//****************************** BY me *************************************
//review need
class Solution{
    private:
    void insert(vector<int> &ans,int value){
            ans.push_back(value);
            int s=ans.size();
            int index=s-1;
            while(index>0){
                int parent=(index-1)/2;
                
                if(ans[parent]<ans[index]){
                    swap(ans[parent],ans[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }
    void print(vector<int>arr){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans(a);
        for(int i=0;i<m;i++){
            insert(ans,b[i]);
        }
        return ans;
    }
};