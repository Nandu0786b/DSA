// Count derangements

//https://www.codingninjas.com/studio/problems/count-derangements_873861/

//for a number we can plce on (n-1) place.
//Now we are have two possibility
//like we are placing this element on the x position and also place x position element on the current element's position
//in the second case we are not going to place these x element on the current element position

//************************************** DP=>TABULATION ************************************************

//SC=O(N), Due to dp vector
//TC=O(N), Due to for loop

#define MOD 1000000007
#include<bits/stdc++.h>

long long int solveTab(int n){
    vector<long long int>dp(n+1,-1);
    // base case.
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<n+1;i++){//top to down m jo recursion relation tha usko yaha pa dal do
        long long int first=dp[i-1]%MOD;

        long long int second=dp[i-2]%MOD;

        long long int sum=(first+second);

        long long int ans=(((i-1)%MOD)*sum)%MOD;

        dp[i]=ans;

    }


    return dp[n];
}
long long int countDerangements(int n) {
  return solveTab(n);
}


//************************************************************* TABULATION ****************************************************************************
//SC=O(1)
//TC=O(N)
//Without dp vector
//here we know that current subproblem depend on the previous two subproblem so we no need to maintain the whole dp vector we can do using three variable

#define MOD 1000000007
#include<bits/stdc++.h>

long long int solveTab(int n){
    // base case.
    long long int dp1=1;
    long long int dp2=0;
    long long int dpp=0;

    for(int i=3;i<n+1;i++){//top to down m jo recursion relation tha usko yaha pa dal do
        dpp=dp1;
        long long int first=dp1%MOD;

        long long int second=dp2%MOD;

        long long int sum=(first+second);

        long long int ans=(((i-1)%MOD)*sum)%MOD;

        dp1=ans;
        dp2=dpp;

    }


    return dp1;
}
long long int countDerangements(int n) {
  return solveTab(n);
}


//
#define MOD 1000000007
#include<bits/stdc++.h>

long long int solveTab(int n){
    // base case.
    long long int dp1=1;
    long long int dp2=0;
    long long int dpp=0;

    for(int i=3;i<n+1;i++){//top to down m jo recursion relation tha usko yaha pa dal do
        dpp=dp1;

        dp1=(((i-1)%MOD)*(dp1%MOD+dp2%MOD))%MOD;

        dp2=dpp;

    }


    return dp1;
}
long long int countDerangements(int n) {
  return solveTab(n);
}

//************************************** DP ************************************************************
//TOP TO DOWN APPROACH
//TC=O(N)
//SC=O(N), Due to recursion call and dp vector

#define MOD 1000000007
#include<bits/stdc++.h>
long long int solvedp(int n,vector<long long int>&dp){
    // base case.
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = (((n - 1) % MOD) * ((solvedp(n - 1,dp) % MOD) +(solvedp(n - 2,dp)) % MOD)) % MOD;

    return dp[n];
}
long long int countDerangements(int n) {
  vector<long long int>dp(n+1,-1);
  return solvedp(n,dp);
}

//************************************** TLE ***********************************************************
//TC=O(exponential)


#define MOD 1000000007
long long int countDerangements(int n) {
  // base case.
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  int ans = (((n - 1)%MOD) * ((countDerangements(n - 1) % MOD) +
                          (countDerangements(n - 2)) % MOD)) %
            MOD;

  return ans;
}
