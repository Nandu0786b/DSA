// Minimum Number of Coins
// Minimum Elements

// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0

//question is that we are having a target sum and an array with some coins we can us one coin many times. now our target is to find the minimum number of coin, there some sould equal 
//to the target


//********************************* Tabulation ******************************************************

#include <bits/stdc++.h>

int solvetab(vector<int>&num,int x){
    vector<int>dp(x+1,INT_MAX);//here we are putting int max because we are doing bottom to top approach
    dp[0]=0;

    for(int i=1;i<=x;i++){
        //here i am finding the minimum required coin for the every amount
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];


}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    return solvetab(num,x);
}


//***************************************** TLE *******************************************
//TC=O(X*N),X is the target and N is the number of coin
//again tle after using the memoization
#include <bits/stdc++.h>
int solve(vector<int> &num,int x,vector<int>dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    dp[x]=mini;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int>dp(x+1,-1);
    int ans=solve(num,x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
//***************************************** TLE *******************************************
//TC is the exponential in this case because we wre checking on the every case that what coin should choose here 
//TC=O(N^N)
#include <bits/stdc++.h>
int solve(vector<int> &num,int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans=solve(num,x);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}