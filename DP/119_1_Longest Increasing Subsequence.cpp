// Longest Increasing Subsequence

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// https://leetcode.com/problems/longest-increasing-subsequence/

// Subsequence:- means you can pick any number of element but thay should maintain the order like if any element come first then it should come first in the answer also

// Expected Time Complexity : O( N*log(N) )
// Expected Auxiliary Space: O(N)

//********************************* BST *************************************


class Solution
{
    public:
    int solvebst(int n, int *a){
        if (n==0){
            return 0;
        }

        vector<int> ans;
        ans.push_back(a[0]);

        for(int i=1; i<n; i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{//find the answer of just bigger element

                int index=lower_bound(ans.begin(),ans.end(), a[i])-ans.begin();

                ans[index]=a[i];

            }
        }
        return ans.size();

    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        return solvebst(n,a);
    }
};


//********************************* DP=>TABULATION,TLE **************************


//Tabulation+space optimization


class Solution
{
    public:
    int solve(int n, int *a){
        //base case
        vector<int> c(n+1, 0);
        vector<int> ne(n+1, 0);
        for(int cur=n-1; cur>=0; cur--){
            for(int pre=cur-1; pre>=-1; pre--){
                int take=0;
                if(pre == -1 || a[cur]>a[pre] ){
                    take=1+ne[cur+1];
                }
                //exclude
                int nottake= 0+ne[pre+1];
                c[pre+1]= max(take,nottake);
                    }
            ne=c;
        }

        return c[0];
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        return solve(n,a);
    }
};





//********************************* DP=>TABULATION,TLE  **************************


class Solution
{
    public:
    int solve(int n, int *a){
        //base case
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int cur=n-1; cur>=0; cur--){
            for(int pre=cur-1; pre>=-1; pre--){

                int take=0;
                if(pre == -1 || a[cur]>a[pre] ){
                    take=1+dp[cur+1][cur+1];
                }

                //exclude
                int nottake= 0+dp[cur+1][pre+1];

                dp[cur][pre+1]= max(take,nottake);
                    }
        }

        return dp[0][0];
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        return solve(n,a);
    }
};




//********************************* DP=>TOP TO DOWN APPROACH,TLE  ****************


class Solution
{
    public:
    int solve(int n, int *a, int cur, int pre, vector<vector<int>> &dp){
        //base case
        if(cur==n){
            return 0;
        }
        if(dp[cur][pre+1]!=-1){
            return dp[cur][pre+1];
        }

        //include, we will do when current element is bigger then previous
        int take=0;
        if(pre == -1 || a[cur]>a[pre] ){
            take=1+solve(n, a, cur+1, cur, dp);
        }

        //exclude
        int nottake= 0+solve(n,a,cur+1, pre, dp);

        return dp[cur][pre+1]= max(take,nottake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n,a,0,-1,dp);
    }
};


//******************************************* TLE *************************************

class Solution
{
    public:
    int solve(int n, int *a, int cur, int pre){
        //base case
        if(cur==n){
            return 0;
        }

        //include, we will do when current element is bigger then previous
        int take=0;
        if(pre == -1 || a[cur]>a[pre] ){
            take=1+solve(n, a, cur+1, cur);
        }

        //exclude
        int nottake= 0+solve(n,a,cur+1, pre);

        return max(take,nottake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        return solve(n,a,0,-1);
    }
};