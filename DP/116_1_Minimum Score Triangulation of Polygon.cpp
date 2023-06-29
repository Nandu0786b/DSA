// Minimum Score Triangulation of Polygon

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

// https://www.codingninjas.com/studio/problems/minimum-score_1266046

// https://www.geeksforgeeks.org/minimum-cost-polygon-triangulation/


//APPROACH: basically hamna 2 point fix kar diya hain like starting and end point and phale triangle wahi sa bana raha hain and uska bad 3rd point random koi bhi la raha hain
//Base case jab first and last point just aga picha ho means unka beach ma third point aa hi nahi saktha hain


// ** In the every recursion two things change i & j it means we have to use 2d dp for this question

//********************************* DP=>TABULATION **************************

//Dp+Tabulation
class Solution {
private:
    int solve(vector<int> &v){
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=n-1; i>=0; i--){
            for(int j=i+2 ; j<n; j++){// we are taking j=i+2 so in between j and i we can make atleast one triangle
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
                }
        }

        return dp[0][n-1];

    }
public:
    int minScoreTriangulation(vector<int>& values) {

        return solve(values);
    }
};


//********************************* DP=>TOP TO DOWN APPROACH ****************

//Dp
class Solution {
private:
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp){
        if(i+1==j)//it means both are the neighbour and we are trying to make triangle from the two node
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};

//************************************** TLE ********************************************


class Solution {
private:
    int solve(vector<int> &v, int i, int j){
        if(i+1==j)//it means both are the neighbour and we are trying to make triangle from the two node
            return 0;
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
        }
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        return solve(values,0,values.size()-1);
    }
};