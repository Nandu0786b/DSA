// Partition Equal Subset Sum

// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//question:given array and devide in to the two part

//approach: just calculate the sum of array if it's odd then two part is not possible but if there even then we can try
//now our taregt is two break this array in the two set, and there sum should be half of the initial sum
//Now in every recursion call there is two option, include or exclude, if include then add in the sum and if exclude then no problem


//Mostly in the 2d dp we create the dp according to variable which are changing in the every recursion call

//********************************* DP=>TABULATION &  SPACE OPTIMIZATION ***************


class Solution{
public:
    bool solve(int *arr, int N, int t){

        vector<int> dpc(t+1, 0);
        vector<int> dpn(t+1, 0);

        dpc[0]=1;
        dpn[0]=1;

        for(int index=N-1; index>=0; index--  ){
            for(int target=1; target<=t/2; target++ ){
                bool include=0;
                if(target-arr[index]>=0)
                   include=dpn[target-arr[index]];
                bool exclude=dpn[target];

                dpc[target] =  include || exclude;
            }
            dpn=dpc;
        }
        return dpc[t/2];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++){
            total+=arr[i];
        }
        if(total%2!=0){
            return 0;
        }
        return solve(arr, N, total);
    }

};



//********************************* DP=>TABULATION **************************


class Solution{
public:
    bool solve(int *arr, int N, int t){

        vector<vector<int>> dp(N+1, vector<int>(t+1, 0));

        for(int i=0;i<=N;i++)
            dp[i][0]=1;

        for(int index=N-1; index>=0; index--  ){
            for(int target=1; target<=t/2; target++ ){
                bool include=0;
                if(target-arr[index]>=0)
                   include=dp[index+1][target-arr[index]];
                bool exclude=dp[index+1][target];

                dp[index][target] =  include || exclude;
            }
        }
        return dp[0][t/2];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++){
            total+=arr[i];
        }
        if(total%2!=0){
            return 0;
        }
        return solve(arr, N, total);
    }

};


//********************************* DP=>TOP TO DOWN APPROACH ****************


class Solution{
public:
    bool solve(int index, int *arr, int N, int target, vector<vector<int>> &dp){
        if(index>=N){
            return 0;
        }
        if(target<0)
            return 0;
        if(target==0)
            return 1;

        if(dp[index][target]!=-1)
            return dp[index][target];

        bool include=solve(index+1, arr, N, target-arr[index], dp);
        bool exclude=solve(index+1, arr, N, target, dp);

        return  dp[index][target] =  include || exclude;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++){
            total+=arr[i];
        }
        if(total%2!=0){
            return 0;
        }
        int target=total/2;
        vector<vector<int>> dp(N+1, vector<int>(target+1, -1));
        return solve(0, arr, N, target, dp);
    }

};



//******************************** TLE ***************************************



class Solution{
public:
    bool solve(int index, int *arr, int N, int target ){
        if(index>=N){
            return 0;
        }
        if(target<0)
            return 0;
        if(target==0)
            return 1;

        bool include=solve(index+1, arr, N, target-arr[index]);
        bool exclude=solve(index+1, arr, N, target);

        return include || exclude;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++){
            total+=arr[i];
        }
        if(total%2!=0){
            return 0;
        }
        int target=total/2;
        return solve(0, arr, N, target);
    }

};


