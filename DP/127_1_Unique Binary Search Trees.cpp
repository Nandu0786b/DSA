// Unique Binary Search Trees

// https://leetcode.com/problems/unique-binary-search-trees/description/

//in this question the main thing is that how much node you are having.
//every node can be a root node
//TC=>O(n^2)

//*********************************** WITH DP-TABULATION ************************




class Solution {
public:

    int solve(int n) {
        vector<int>dp(n+1, 0);
        dp[0]=dp[1]=1;

        for(int i=2; i<=n; i++){// i represent the node(n)

            for(int j=1; j<=i; j++){//j root is represent as a root node
                dp[i]+=dp[j-1]*dp[i-j];
            }

        }

        return dp[n];
    }
    int numTrees(int n){
        return solve(n);
    }
};




//********************************** WITH DP ************************************



class Solution {
public:

    int solve(int n, vector<int> &dp) {
        if(n<=1){
            return 1;
        }

        int ans=0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i<=n;i++){
            ans+=solve(i-1, dp)*solve(n-i, dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n){
        vector<int>dp(n+1, -1);

        return solve(n, dp);
    }
};


//********************************** WITHOUT DP *********************************

class Solution {
public:
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }

        int ans=0;

        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};