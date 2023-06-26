// 0 1 Knapsack

//2D-DP

// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//approach :- on every place we are having two option kepp or leave
//base case when index become 0 then return add value if possible else return 0
//if we include the elememt then we have to add that value and reduce that weight from the maximum weight and also reduce index
//if we exclude the element then we just have to reduce the index
//return the maximum of the both

//see in the every recursion call two values are changing index and the capacity
//so it means to use dp solution we have to store both the vaulues


//DP approach :- basicslly if we see then on the every index for the weight i am including and excluding and taking the maximum
//so i create a 2d dp which row indcates the index and column refer to the weight like for the x index and y weight what value will be the maximum
//so means for the evrery index i will calculate maximum values for the all weight from 1 to maxweight like for the index if i am having x  weight then what will be the maximum value

//********************************* DP=> TABULATION WITHOUT VECTOR **********************************************************

// IF WE SEE IN THE BELOW SOLUTION THEN YOU WILL NOTICE THAT OUR ANSWER IS DEPEND only on the previous answer then why we store the value of the all cases

#include <bits/stdc++.h>
int solvetab(vector<int> &weight, vector<int> &value, int n, int capacity) {
	//step:1 create two vector
	vector<int>previous(capacity+1,0);
	vector<int>current(capacity+1,0);

	//step:2 right the base case
	for(int w=weight[0];w<=capacity;w++ ){
		if(weight[0]<=capacity)
			previous[w]=value[0];

		else
			previous[w]=0;
	}

	for(int index=1;index<n;index++){
		for(int w=0;w<=capacity;w++ ){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+previous[w-weight[index]];
			}
			int exclude =0+previous[w];
			current[w]=max(include,exclude);
		}
		previous=current;
	}
	return previous[capacity];


}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	return solvetab(weight,value,n,maxWeight);
}





//********************************* DP=> TABULATION *************************************************************************

#include <bits/stdc++.h>
int solvetab(vector<int> &weight, vector<int> &value, int n, int capacity) {
	//step:1 create a dp vector
	vector<vector<int>>dp(n,vector<int>(capacity+1,0));

	//step:2 right the base case
	for(int w=weight[0];w<=capacity;w++ ){
		if(weight[0]<=capacity)
			dp[0][w]=value[0];

		else
			dp[0][w]=0;
	}

	for(int index=1;index<n;index++){
		for(int w=0;w<=capacity;w++ ){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+dp[index-1][w-weight[index]];
			}
			int exclude =0+dp[index-1][w];
			dp[index][w]=max(include,exclude);
		}
	}
	return dp[n-1][capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	return solvetab(weight,value,n,maxWeight);
}




//********************************* DP=> TOP TO BOTTOM APPROACH *************************************************************
#include <bits/stdc++.h>
int solve(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>>&dp) {
	//if only single item in the beg
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		else
			return 0;
	}
	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}
	int include=0;
	if(weight[index]<=capacity)
		include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
	int exclude=0+solve(weight,value,index-1,capacity,dp);
	dp[index][capacity]=max(include,exclude);
	return dp[index][capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// Write your code here

	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);

}




//************************************************ TLE ********************************************

#include <bits/stdc++.h>
int solve(vector<int> &weight, vector<int> &value, int index, int capacity) {
	//if only single item in the beg
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		else
			return 0;
	}
	int include=0;
	if(weight[index]<=capacity)
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	int exclude=0+solve(weight,value,index-1,capacity);

	return max(include, exclude);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// Write your code here
	return solve(weight,value,n-1,maxWeight);

}


