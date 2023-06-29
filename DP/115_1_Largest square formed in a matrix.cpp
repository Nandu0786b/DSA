// Largest square formed in a matrix

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// https://leetcode.com/problems/maximal-square/

// https://www.codingninjas.com/studio/problems/maximum-area-square_981268

//in every recursion call we are changing both column ad row so it is a 2d dp question

//********************************* DP=>TABULATION, Space Optimization ******

//if we see carefully then we require only right bottom and diagonal. bottom and diagonal are coming in the same row so it means we require only two row current and next
//TC=O(n*m)
//SC=O(m)

class Solution{
private:
    int solve(vector<vector<int>> & mat){
        int row=mat.size();
        int col=mat[0].size();
        int maxi=0;
        vector<int> cur(col+1, 0);
        vector<int> nex(col+1, 0);
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right = cur[j+1];
                int diagonal = nex[j+1];
                int bottom = nex[j];
                if(mat[i][j]==1){
                    cur[j]= 1 +min(right, min(diagonal, bottom));
                    maxi=max(maxi,cur[j]);
                }
                else{
                    cur[j]=0;
                }
                    }
            nex=cur;

        }
        return maxi;

    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        return solve(mat);

    }
};


//********************************* DP=>TABULATION **************************

//TC=O(n*m)
//SC=O(n*m)
class Solution{
private:
    int solve(vector<vector<int>> & mat){
        int row=mat.size();
        int col=mat[0].size();
        int maxi=0;
        vector<vector<int>> dp(row+1,vector<int>(col+1, 0));

        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int bottom = dp[i+1][j];
                if(mat[i][j]==1){
                    dp[i][j]= 1 +min(right, min(diagonal, bottom));
                    maxi=max(maxi,dp[i][j]);
                }
                    }
        }
        return maxi;

    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        return solve(mat);

    }
};


//********************************* DP=>TOP TO DOWN APPROACH ****************

//TC=O(n*m)
//SC=O(n*m)

class Solution{
private:
    int solve(vector<vector<int>> & mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = solve(mat,i,j+1, maxi, dp);
        int diagonal = solve(mat,i+1,j+1, maxi, dp);
        int bottom = solve(mat,i+1,j, maxi, dp);
        if(mat[i][j]==1){
            dp[i][j]= 1 +min(right, min(diagonal, bottom));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n,vector<int>(m, -1));
        int maxi=0;
        solve(mat, 0, 0, maxi, dp);
        return maxi;
    }
};

//************************************** TLE ********************************************


class Solution{
private:
    int solve(vector<vector<int>> & mat, int i, int j, int &maxi){
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        int right = solve(mat,i,j+1, maxi);
        int diagonal = solve(mat,i+1,j+1, maxi);
        int bottom = solve(mat,i+1,j, maxi);
        if(mat[i][j]==1){
            int ans= 1 +min(right, min(diagonal, bottom));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        solve(mat,0,0,maxi);
        return maxi;
    }
};