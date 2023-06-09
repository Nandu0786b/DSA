// Minimum Cost of ropes
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

//main thing is that har bar minimum number ko hi laka chalana hain so last ma cost minimum ho
//es ma sum bhi add kartha jana hain due to this we are starting from the start and continously adding sum again in the queue 
//and also updating the cost variable evry time
//TC=o(n*log(n)),SC=(n)

#include<queue>
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        long long cost=0;
        for(int i=0;i<n;i++ ){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            
            long long sum =a+b;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};
