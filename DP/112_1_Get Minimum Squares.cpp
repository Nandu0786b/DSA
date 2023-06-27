
// Get Minimum Squares

// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

//on every position there is we will check for the it's smaller element that
//during return we will add min+1 becasue this is also a way

//********************************* DP=>TABULATION **************************

class Solution{
    private:
    int solve(int n){

        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;


        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                if((i-j*j)>=0)
                     dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{
	    return solve(n);
	}
};

//********************************* DP=>TOP TO DOWN APPROACH ****************

class Solution{
    private:
    int solve(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1)
            return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i,dp));
        }
        dp[n]=ans;
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{   vector<int> dp(n+1,-1);
	    return solve(n,dp);
	}
};



//********************************* TLE *************************************
class Solution{
    private:
    int solve(int n){
        if(n==0){
            return 0;
        }
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }

        return ans;
    }
	public:
	int MinSquares(int n)
	{
	    return solve(n);
	}
};