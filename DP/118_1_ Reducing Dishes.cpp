//  Reducing Dishes

// https://leetcode.com/problems/reducing-dishes/

//approach: two option include or exclude


//********************************* DP=>TABULATION **************************


//Tabulation+space optimization
class Solution {
public:
    int solve(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<int> cur( n+1,0);
        vector<int> nex( n+1,0);

        for(int index=n-1; index>=0;index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1)+nex[time+1];

                int exclude = 0+nex[time];

                cur[time]= max(include, exclude);
            }
            nex=cur;
        }

        return cur[0];


    }
    int maxSatisfaction(vector<int>& satisfaction) {

        //sorting in the start
        sort(satisfaction.begin(),satisfaction.end());


        return solve(satisfaction);
    }
};

//********************************* DP=>TABULATION **************************

//Tabulation
class Solution {
public:
    int solve(vector<int>& satisfaction){
        int n=satisfaction.size();
        vector<vector<int>> dp( n+1, vector<int>(n+1,0));

        for(int index=n-1; index>=0;index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1)+dp[index+1][time+1];

                int exclude = 0+dp[index+1][time];

                dp[index][time]= max(include, exclude);
            }
        }

        return dp[0][0];


    }
    int maxSatisfaction(vector<int>& satisfaction) {

        //sorting in the start
        sort(satisfaction.begin(),satisfaction.end());


        return solve(satisfaction);
    }
};

//********************************* DP=>TOP TO DOWN APPROACH ****************

class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1)
            return dp[index][time];
        int include = satisfaction[index]*(time+1)+solve(satisfaction, index+1, time+1, dp);

        int exclude = 0+solve(satisfaction, index+1, time, dp);

        return dp[index][time]= max(include, exclude);

    }
    int maxSatisfaction(vector<int>& satisfaction) {

        //sorting in the start
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp( n+1, vector<int>(n+1,-1));

        return solve(satisfaction,0,0,dp);
    }
};


//********************************* TLE **************************************


class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time){
        //base case
        if(index==satisfaction.size()){
            return 0;
        }

        int include = satisfaction[index]*(time+1)+solve(satisfaction, index+1, time+1);

        int exclude = 0+solve(satisfaction, index+1, time);

        return max(include, exclude);

    }
    int maxSatisfaction(vector<int>& satisfaction) {

        //sorting in the start
        sort(satisfaction.begin(),satisfaction.end());

        return solve(satisfaction,0,0);
    }
};