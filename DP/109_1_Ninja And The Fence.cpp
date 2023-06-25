// Ninja And The Fence

// https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208

//approach:
//like for the n two case is present last two post may be same or different

//for the n==1 ans will be k
//for the n==2 if the last two have same color then total case is k and if last two is diffferent then for the last second k case and for the last first k-1 so k*k-1
//for the n=2 total is k+k*(k-1)=>k*k

//it means we will add two cases same and different

//for the same case
//like on the n-2 place x color is present it means on the last position we can put (k-1) color, k-1 because if we put k color then one case will be there when last three post 
//color will be same

//for the different case
//like on the n-1 place x color is present then for the different color on the current position we can place k-1 color

//now for the current position final answer will be last two same + last two different




//****************************************** DP=> Tabulation  ****************************************************
//TC=O(N)
//SC=O(N)
#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}
int multi(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n, int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;

    dp[2]=add(k,multi(k,k-1));

    for(int i=3;i<n+1;i++){
        dp[i]=add(multi(dp[i-2],k-1),multi(dp[i-1],k-1));
    }


    return dp[n];
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}

//****************************************** DP=> Tabulation Without using the dp vector  ************************
//TC=O(N)
//SC=O(1)
#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}
int multi(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n, int k){
    int dp2=k;

    int dp1=add(k,multi(k,k-1));
    int dpp;

    for(int i=3;i<n+1;i++){
        dpp=dp1;
        dp1=add(multi(dp2,k-1),multi(dp1,k-1));
        dp2=dpp;
    }


    return dp1;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}


//****************************************** DP=> TOP TO DOWN ****************************************************
//TC=O(N)
//SC=O(N)

#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}
int multi(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n, int k, vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,multi(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] =add(multi(solve(n-2,k,dp),k-1),multi(solve(n-1,k,dp),k-1));

    return dp[n];
}
int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solve(n,k,dp);
}

//****************************************** TLE *****************************************************************
//TC=O(Exponenetial)
//SC=O(N)

#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD+b%MOD)%MOD;
}
int multi(int a, int b){
    return ((a%MOD)*(b%MOD))%MOD;
}
int solve(int n, int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,multi(k,k-1));
    }

    int ans =add(multi(solve(n-2,k),k-1),multi(solve(n-1,k),k-1));

    return ans;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}

//*********************************************** GPT ******************************************************************
//1.
#include <bits/stdc++.h>
#define MOD 1000000007

int numberOfWays(int N, int K) {
    // Write your code here.
    // return solve(n,k);
    const int mod = 1000000007;
    int dp[N + 1];
    dp[0] = 1;
    dp[1] = K;
    dp[2] = K *1LL* K;

    for (int i = 3; i <= N; i++) {
        dp[i] = ((K - 1) *1LL* (dp[i - 1] % mod) + (K - 1) *1LL* (dp[i - 2] % mod)) % mod;
    }

    return dp[N];
}

//2.

#include <bits/stdc++.h>
#define MOD 1000000007

int numberOfWays(int N, int K) {
    // Write your code here.
    // return solve(n,k);
    const int mod = 1000000007;
    int dpp;
    int dp2 = K;
    int dp1 = K *1LL* K;

    for (int i = 3; i <= N; i++) {
        dpp=dp1;
        dp1 = ((K - 1) *1LL* (dp1 % mod) + (K - 1) *1LL* (dp2 % mod)) % mod;
        dp2=dpp;
    }

    return dp1;
}


