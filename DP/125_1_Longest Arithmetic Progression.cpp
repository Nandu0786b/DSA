// Longest Arithmetic Progression

// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

//Approach :-
//Brute Force :- in starting we will choose 2 Number and we will assume that they are the last two numbwr of the ap, and we will go back and will try to findout previous element of the ap
//In this if we have n number then there is N^2 combination
//In every recursion We are changing the index and the difference of the element so this is 2D-DP Question

//DP[I][Diff] => Represent the Number of element Till Ith index which have Diff defrence




//********************************* DP=>TABULATION (TLE) **************************





class Solution{
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here

        if(n<=2)
            return n;
        int ans=0;
        unordered_map<int, int> dp[n+1];
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int dif=A[i]-A[j];
                int count=1;

                //Check if the answer is already present
                if(dp[j].count(dif))
                    count=dp[j][dif];

                dp[i][dif]=1+count;
                ans=max(ans, dp[i][dif]);
            }
        }

        return ans;
    }
};






//********************************* DP=>TOP TO DOWN APPROACH (TLE) ****************




class Solution{
public:
    int solve(int index, int dif, int *A, unordered_map<int, int> dp[]){
        //backword check
        if(index<0)
            return 0;


        if(dp[index][dif]){
            return dp[index][dif];
        }
        int ans=0;

        for(int j=index-1; j>=0; j--){
            if(A[index]-A[j]==dif){
                ans=max(ans, 1+solve(j, dif, A, dp));
            }
        }

        return dp[index][dif]=ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here

        if(n<=2)
            return n;
        int ans=0;
        unordered_map<int, int> dp[n+1];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans=max(ans, 2+solve(i, A[j]-A[i], A, dp) );//We are adding 2 because we also have two Number A[j],A[i]
            }
        }

        return ans;
    }
};






//************************************** TLE ********************************************




class Solution{
public:
    int solve(int index, int dif, int *A){
        //backword check
        if(index<0)
            return 0;

        int ans=0;

        for(int j=index-1; j>=0; j--){
            if(A[index]-A[j]==dif){
                ans=max(ans, 1+solve(j, dif, A));
            }
        }

        return ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        // code here

        if(n<=2)
            return n;
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans=max(ans, 2+solve(i, A[j]-A[i], A) );//We are adding 2 because we also have two Number A[j],A[i]
            }
        }

        return ans;
    }
};