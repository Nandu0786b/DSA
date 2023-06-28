// Ninja's Trip

// https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0

// https://leetcode.com/problems/minimum-cost-for-tickets/

//approach:- on every day we have three option to buy a one day pass, 7 day or monthly pass
//so it means it's TC going to be exponential
//Now in every recursion call we will buy all three ticket but we will increase our day by the number of ticket like if our ticket is for the one day then we will increase index by 1
//but if our ticket is for the 7 day then we will increse our index till our current day is greater then day[index]+7
//we will do same for the monthly
//in the end we return min of the all three solution in the evry test case
//our base case will be when index is out of range from the toatl number of the day's



//********************************* DP=>TABULATION **************************



//DP + Tabulation
int solve(int n, vector<int> &days, vector<int> &cost){

    vector<int> dp(n+1,INT_MAX);

    dp[n]=0;  //base case


    for(int k=n-1;k>=0;k--){
        //single day pass
        int a=cost[0]+dp[k+1];

        //7  day ticket
        int i;

        for(i=k;i<n && days[i]<days[k]+7;i++);
        int b=cost[1]+dp[i];

        //30th day ticket
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int c=cost[2]+dp[i];
        dp[k]=min(a,min(b,c));
    }




    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.

    return solve(n,days,cost);
}


//********************************* DP=>TOP TO DOWN APPROACH ****************


//TC=O(N), N is number of day's which may be between 1 to 365 so TC is O(1) for this question
//DP + RECURSION
int solve(int n, vector<int> &days, vector<int> &cost, int index,vector<int> &dp){
    if(index>=n){//base case
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    //single day ticket
    int a=cost[0]+solve(n,days,cost,index+1,dp);

    //7  day ticket
    int i;

    for(i=index;i<n && days[i]<days[index]+7;i++);
    int b=cost[1]+solve(n,days,cost,i,dp);

    //30th day ticket
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int c=cost[2]+solve(n,days,cost,i,dp);
    dp[index]=min(a,min(b,c));
    return dp[index];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,days,cost,0,dp);
}

//********************************************* RECURSION *****************************************************************


int solve(int n, vector<int> &days, vector<int> &cost, int index){
    if(index>=n){//base case
        return 0;
    }

    //single day ticket
    int a=cost[0]+solve(n,days,cost,index+1);

    //7  day ticket
    int i;

    for(i=index;i<n && days[i]<days[index]+7;i++);
    int b=cost[1]+solve(n,days,cost,i);

    //30th day ticket
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int c=cost[2]+solve(n,days,cost,i);

    return min(a,min(b,c));
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost,0);
}