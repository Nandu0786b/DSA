// Pizza With 3n Slices

// https://leetcode.com/problems/pizza-with-3n-slices/


//Approach :- same to same houe robber in circular house


//********************************* DP=>TABULATION &  SPACE OPTIMIZATION ***************

//basically if we see our current depand oon the index+1, index+2 and one current so it means if we are having three row then we can do this without THE DP
//every iteration ma current fir sa banega and next2 will shift to the next1 and next1 will be shift to the current

class Solution {
private:
    int solve(vector<int>& slices){
        int k=slices.size();
        vector<int>c1(k+2,0);
        vector<int>p1(k+2,0);
        vector<int>n1(k+2,0);
        vector<vector<int>>dp2(k+2, vector<int>(k, 0));
        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int take=slices[index]+n1[n-1];


                int nottake=0+c1[n];

                p1[n]=max(take, nottake);
            }
            n1=c1;
            c1=p1;
        }
        int case1=c1[k/3];
        vector<int>c2(k+2,0);
        vector<int>p2(k+2,0);
        vector<int>n2(k+2,0);
        for(int index=k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int take=slices[index]+n2[n-1];


                int nottake=0+c2[n];

                p2[n]=max(take, nottake);
            }
            n2=c2;
            c2=p2;
        }
        int case2=c2[k/3];
        return max(case1 ,case2);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};


//********************************* DP=>TABULATION **************************

//Next time

class Solution {
private:
    int solve(vector<int>& slices){
        int k=slices.size();
        vector<vector<int>>dp1(k+2, vector<int>(k, 0));
        vector<vector<int>>dp2(k+2, vector<int>(k, 0));
        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int take=slices[index]+dp1[index+2][n-1];


                int nottake=0+dp1[index+1][n];

                dp1[index][n]=max(take, nottake);
            }
        }
        int case1=dp1[0][k/3];
        for(int index=k-1; index>=1; index--){
            for(int n=1; n<=k/3; n++){
                int take=slices[index]+dp2[index+2][n-1];


                int nottake=0+dp2[index+1][n];

                dp2[index][n]=max(take, nottake);
            }
        }
        int case2=dp2[1][k/3];
        return max(case1 ,case2);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};

//********************************* DP=>TOP TO DOWN APPROACH ****************



class Solution {
private:
    int solve(int index, int endindex, vector<int>& slices, int n, vector<vector<int>> &dp){
        if(0==n || index>endindex){
            return 0;
        }
        if(dp[index][n]!=-1)
            return dp[index][n];
        int take = slices[index]+solve(index+2, endindex, slices, n-1, dp);

        int notake = 0+solve(index+1, endindex, slices, n, dp);

        return  dp[index][n]=max(take, notake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {

        int k=slices.size();
        vector<vector<int>>dp1(k, vector<int>(k, -1));
        int case1=solve(0, k-2, slices, k/3, dp1);
        vector<vector<int>>dp2(k, vector<int>(k, -1));
        int case2=solve(1, k-1, slices, k/3, dp2);
        return max(case1, case2);
    }
};

//******************************** TLE ***************************************


class Solution {
private:
    int solve(int index, int endindex, vector<int>& slices, int n){
        if(0==n || index>endindex){
            return 0;
        }
        int take = slices[index]+solve(index+2, endindex, slices, n-1);

        int notake = 0+solve(index+1, endindex, slices, n);

        return max(take, notake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        int case1=solve(0, k-2, slices, k/3);
        int case2=solve(1, k-1, slices, k/3);

        return max(case1, case2);
    }
};