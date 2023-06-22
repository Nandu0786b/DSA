// Count Ways To Reach The N-th Stairs

//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0

//on each stairs we are having two option that either take one step ot two step


//*********************** top to bottom ***********************************************

// Now think on each step we are having two subproblem that take one step or two step so we can store the value of step on each stairs


#include <bits/stdc++.h>
#define MOD 1000000007
int solve(int nstairs,vector<int> &dp){//i showing the current stairs
    if(nstairs==0)
        return 1;
    else if(nstairs<0)
        return 0;
    if(dp[nstairs]!=-1){
        return dp[nstairs];
    }
    dp[nstairs]=(solve(nstairs-1,dp)+solve(nstairs-2,dp))%MOD;
    return dp[nstairs];

}
int countDistinctWays(int nstairs) {
    //  Write your code here.
    vector<int> dp(nstairs+1,-1);
    return solve(nstairs,dp);
}

//*********************** TLE => top to bottom ***********************************************


#include <bits/stdc++.h>
#define MOD 1000000007
int solve(int nstairs,int i){//i showing the current stairs
    if(nstairs==i)
        return 1;
    else if(nstairs<i)
        return 0;
    // return (solve(nstairs,i+1)+solve(nstairs,i+2))%MOD;
        return (solve(nstairs,i+1)+solve(nstairs,i+2));

}
int countDistinctWays(int nstairs) {
    //  Write your code here.
    return solve(nstairs,0);
}