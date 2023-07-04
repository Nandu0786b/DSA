// Dice throw

// https://practice.geeksforgeeks.org/problems/dice-throw5349/1


//approach: on the evry dice will be case equal to the number of faces
//Now There is two option

//if we start sum from the zero then we hace to use base case when current sum is >target then return 0
//but if we reduces the target in the every case then if target<0 return 0


//********************************* DP=>TABULATION &  SPACE OPTIMIZATION ***************

//if you see tabulation solution then our answer is depanding only on the previous row and we are storing the data in the current row so we can use only two row instead of the complete dp



class Solution {
    private:
        long long solve(int d , int f , int t){

            vector<long long> dpp(t+1, 0);
            vector<long long> dpc(t+1, 0);

            dpp[0]=1;



            for(int dice=1; dice<=d; dice++ ){
                for(int target=1; target<=t; target++){
                    long long ans=0;
                    for(int i=1;i<=f;i++ ){
                        if(target-i>=0)
                        ans=ans + dpp[target-i];
                    }

                    dpc[target]=ans;
                }
                dpp=dpc;
            }

            return dpc[t];
        }

    public:
        long long noOfWays(int M , int N , int X) {
            // code here

            return solve(N, M, X);
        }
};





//********************************* DP=>TABULATION **************************



class Solution {
    private:
        long long solve(int d , int f , int t){

            vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0));

            dp[0][0]=1;



            for(int dice=1; dice<=d; dice++ ){
                for(int target=1; target<=t; target++){
                    long long ans=0;
                    for(int i=1;i<=f;i++ ){
                        if(target-i>=0)
                        ans=ans + dp[dice-1][target-i];
                    }

                    dp[dice][target]=ans;
                }
            }

            return dp[d][t];
        }

    public:
        long long noOfWays(int M , int N , int X) {
            // code here

            return solve(N, M, X);
        }
};


//********************************* DP=>TOP TO DOWN APPROACH ****************



class Solution {
    private:
        long long solve(int dice , int faces , int target, vector<vector<long long>> &dp){

            //base case
            if(target<0)
                return 0;
            if(dice==0 && target!=0)
                return 0;
            if(target==0 && dice!=0)
                return 0;
            if(dice==0 && target==0)
                return 1;
            if(dp[dice][target]!=-1)
                return dp[dice][target];
            long long ans=0;
            for(int i=1;i<=faces;i++ ){
                ans=ans + solve(dice-1, faces, target-i, dp);
            }

            return dp[dice][target] = ans;
        }

    public:
        long long noOfWays(int M , int N , int X) {
            // code here
            vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
            return solve(N, M, X, dp);
        }
};


//BY ME


class Solution {
private:
    long long solve(int M, int N, int X, vector<vector<long long>>& dp) {
        if(X<0)
            return 0;
        if (N == 0) {
            if(X==0){
                return 1;
            }
            else
                return 0;
        }
        if (dp[N][X] != -1) {
            return dp[N][X];
        }
        long long ans = 0;
        for (int i = 1; i <= M; i++) {
            ans = ans + solve(M, N - 1, X - i, dp);
        }

        return dp[N][X] = ans;
    }

public:
    long long noOfWays(int M, int N, int X) {
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        return solve(M, N, X, dp);
    }
};


//BY ME



class Solution {
    public:
    long long solve(int M, int N, int X, int cur, int sum, vector<vector<long long>>& dp) {
        if (cur == N) {//if you see then we started from 0 index so here we are using cur==N but if we start from the 1 index then u have to use cur>N
            return sum == X ? 1 : 0;
        }
        if (sum >= 51) {
            return 0;
        }
        if (dp[cur][sum] != -1) {
            return dp[cur][sum];
        }
        long long ans = 0;
        for (int i = 1; i <= M; i++) {
            ans += solve(M, N, X, cur + 1, sum + i, dp);
        }

        return dp[cur][sum] = ans;
    }

    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N, vector<long long>(51, -1));
        return solve(M, N, X, 0, 0, dp);
    }
};


//******************************** TLE ***************************************


class Solution {
    private:
        long long solve(int dice , int faces , int target){

            //base case
            if(target<0)
                return 0;
            if(dice==0 && target!=0)
                return 0;
            if(target==0 && dice!=0)
                return 0;
            if(dice==0 && target==0)
                return 1;
            int ans=0;
            for(int i=1;i<=faces;i++ ){
                ans+=solve(dice-1, faces, target-i);
            }

            return ans;
        }

    public:
        long long noOfWays(int M , int N , int X) {
            // code here

            return solve(N, M, X);
        }
};