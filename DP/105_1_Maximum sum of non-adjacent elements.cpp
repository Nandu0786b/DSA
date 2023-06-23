// Maximum sum of non-adjacent elements


// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0


//******************************* DP => TOP TO BOTTOM ***********************************************************

#include <bits/stdc++.h>
int solve(vector<int>&nums,int i,vector<int>&dp){
    if(nums.size()<=i){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    dp[i]=max(nums[i]+solve(nums,i-2,dp),solve(nums,i-1,dp));
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size()+1,-1);
    return solve(nums,nums.size()-1,dp);
}

//******************************* TABULATION ********************************************************************

#include <bits/stdc++.h>
int solve(vector<int>&nums){
    vector<int>dp(nums.size(),-1);
    dp[0]=nums[0];

    for(int i=1;i<nums.size();i++){
        int inc=dp[i-2]+nums[i];
        int exc=dp[i-1];

        dp[i]=max(inc,exc);
    }
    return dp[nums.size()-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}
//without dp vector

#include <bits/stdc++.h>
int solve(vector<int>&nums){
    int dp1=nums[0];
    int dp2=0;

    for(int i=1;i<nums.size();i++){
        int inc=dp2+nums[i];
        int exc=dp1;
        dp2=dp1;
        dp1=max(inc,exc);
    }
    return (dp1);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums);
}
//******************************* TLE *********************************************************

// on every case we are taking two case include or exclude
//TC=O(2^N)
//in thiswe are going left to right for the right to left we can pass i initiaal as nums.size() and base case will be i<0 return 0

#include <bits/stdc++.h>
int solve(vector<int>&nums,int i){
    if(nums.size()<=i){
        return 0;
    }
    return max(nums[i]+solve(nums,i+2),solve(nums,i+1));
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums,0);
}


//right to left

#include <bits/stdc++.h>
int solve(vector<int>&nums,int i){
    if(nums.size()<=i){
        return 0;
    }
    return max(nums[i]+solve(nums,i-2),solve(nums,i-1));
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums,nums.size()-1);
}