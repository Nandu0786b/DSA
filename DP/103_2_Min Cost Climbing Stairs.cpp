//Min Cost Climbing Stairs

// https://leetcode.com/problems/min-cost-climbing-stairs/description/
//************************* DP ***************************************

//TC=O(N)
// SC=O(N)+O(N)
class Solution {
private:
    int solve(vector<int>& cost,int n,vector<int> &dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));

        return ans;
    }
};

//************************* TLE **************************************

//TC=O(2^N)
//SC=O(N)

class Solution {
private:
    int solve(vector<int>& cost,int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));//on every stairs we have to add self stairs cost and minimum of cost by which we can come there
        return ans;

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=min(solve(cost,n-1),solve(cost,n-2));//like on the last stairs i can reach from the n-1 or n-2 stairs which is the minimum

        return ans;
    }
};

//*************************** using the bottom to top approach **************************
//TC=O(N)
//SC=O(N)

class Solution {
private:
    int solve(vector<int>& cost,int n){
        vector<int>dp(n+1,-1);//dp array

        dp[0]=cost[0];//base case
        dp[1]=cost[1];//base case

        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);//using the dp
        }
        //main thing is that like on the last stair there is no cost because we are not going to take any mosr step from end
        //so on the last step we can come from the n-1 or n-2 stairs so the minimum of these will be our answer
        return min(dp[n-1],dp[n-2]);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {


        return solve(cost,cost.size());
    }
};

//***************************** without dp vector ********************************************************
//TC=O(N)
//SC=O(1)

//BASICALLY IF WE SEE, ONLY REQUIRED PREVIOUS TWO NUMBER TO CALCULATE MINIMUM COST THEN WHY WE NEED TO CREATE AND STORE ALL COS T
//WE ALSO CAN DO USING THREE VARIABLE USING THIS WE WILL SAVE SPACE OF O(n)

class Solution {
private:
    int solve(vector<int>& cost,int n){

        int dp0=cost[0];//base case
        int dp1=cost[1];//base case
        int dpo;
        for(int i=2;i<n;i++){
            dpo=dp1;
            dp1=cost[i]+min(dp0,dp1);//using the dp
            dp0=dpo;
        }
        //main thing is that like on the last stair there is no cost because we are not going to take any mosr step from end
        //so on the last step we can come from the n-1 or n-2 stairs so the minimum of these will be our answer
        return min(dp0,dp1);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {


        return solve(cost,cost.size());
    }
};