// K-th Largest Sum Subarray
// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398


//approach: start two nested loop, and check every possible values
//we are using the two for loop so total TC=o(n^2)
//Now store sum of all arra
//SC=o(n^2), because vector storing maximum n*n data as all subarray sum

#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int>sumstore;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			sumstore.push_back(sum);
		}
	}
	sort(sumstore.begin(),sumstore.end()); //sort tc is O(n log n).
	return sumstore[sumstore.size()-k];
}

//using the min heap queue
//basically apan min heap ma data tabhi dal raha hain ya tho who full na ho ya fir sum uska top sa bada ho hence usma sirf who hi kth largest
//element hi rahenga and kth largest element front ma hoga
// in this TC increased because we are using min heap queue in the two nested loop so TC= O(n^2 log n), which increased with respect to above solution
//but we are pushing only k element so SC=o(k)
#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int ,vector<int>,greater<int>>mini;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}

