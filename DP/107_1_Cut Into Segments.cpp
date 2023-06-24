// Cut Into Segments

// https://www.codingninjas.com/studio/problems/cut-into-segments_1214651

//question asking that you are given a rode or sum and three integer x,y,z now your taks is to build that sum using that integer and number of used integer should be max


//************************************* DP TOP TO DOWN CONVERSION IN TO THE DP TABULATION *****************************

//first top to down ka base case ko tabulation ka starting ma dal do

//uska bad jis range ka liya recursion call ho raha hain us range ka liya for loop laga do

//and recursion ma jasa answer store kar raha tha wasa hi for loop ma bhi dp ma answer store lar lo

//and last ma answer return kar do

//agar current problem previous like define subproblem pa depend kra like one may be two or three then do not create dp just use the variable


//*********************************** DP=>TABULATION ******************************************************************

//TC=O(N)
//SC=O(N), due to recursion call and dp array

//we can not do space optimization, it's possible in the tabulation when our dp valuse depand on the fix previous one two or some number but where we are not know how much 
//value's of previous will be need

//remember only one thing in the tabulation that we first we have to find out the base case after this we will start from the bottom to top

//DP array using the initial value INT_MIN
#include<bits/stdc++.h>

int cutSegments(int n, int x, int y, int z) {


	vector<int>dp(n+1,INT_MIN);
	//we are not taking -1 because if you see then in the for loop may be possible dp[i-x] is -1 and after the
	// +1 it's become the 0 so it's will affect the range
	dp[0]=0;

	for(int i=1;i<n+1;i++){
		if(i-x>=0)
			dp[i]=max(dp[i],dp[i-x]+1);
		if(i-y>=0)
			dp[i]=max(dp[i],dp[i-y]+1);
		if(i-z>=0)
			dp[i]=max(dp[i],dp[i-z]+1);
	}
	if(dp[n]<0){
		return 0;
	}
	return dp[n];
}

//DP ARRAY USING THE INITIAL VALUE -1

#include<bits/stdc++.h>

int cutSegments(int n, int x, int y, int z) {


	vector<int>dp(n+1,-1);

	dp[0]=0;

	for(int i=1;i<n+1;i++){
		if(i-x>=0 && dp[i-x]>=0)
			dp[i]=max(dp[i],dp[i-x]+1);
		if(i-y>=0 && dp[i-y]>=0)
			dp[i]=max(dp[i],dp[i-y]+1);
		if(i-z>=0 && dp[i-z]>=0)
			dp[i]=max(dp[i],dp[i-z]+1);
	}
	if(dp[n]<0){
		return 0;
	}
	return dp[n];
}
//*********************************** DP=>TOP TO BOTTOM APPROACH ******************************************************
//TC=O(N)
//SC=O(N), due to recursion call and dp array

#include<bits/stdc++.h>
int solve(int n, int x, int y, int z,vector<int>&dp) {
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;//case when our lenght become negeative
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	//we are adding 1 because this is also a segment
	int a=1+solve(n-x,x,y,z,dp);
	int b=1+solve(n-y,x,y,z,dp);
	int c=1+solve(n-z,x,y,z,dp);
	dp[n]=max(a,max(b,c));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	//in this we take dp size of the n+1 because we need sum n and in index start from the zero to n-1 and in the sum we
	//also need n so we took size n+1

    //every index is telling the possible maximum sum for this
	//when value of the n is equal to the i
	vector<int>dp(n+1,-1);
	int ans=solve(n, x, y, z,dp);
	if(ans<0){
		return 0;
	}
	return ans;
}



//*********************************** TLE ******************************************************


//so on every case you can take any integer so there TC will be O(N^N) in case of the brute force

// TC=O(N^N)


#include<bits/stdc++.h>
int solve(int n, int x, int y, int z) {
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;//case when our lenght become negeative
	}
	//we are adding 1 because this is also a segment
	int a=1+solve(n-x,x,y,z);
	int b=1+solve(n-y,x,y,z);
	int c=1+solve(n-z,x,y,z);

	return max(a,max(b,c));
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans=solve(n, x, y, z);
	if(ans<0){
		return 0;
	}
	return ans;
}