
// Nth Fibonacci Number
// https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?leftPanelTab=1


//********************************** TOP TO BOTTOM APPROCH ******************************

//TC=O(N)
//SC=O(N)

//In this we simply do that find the answer of sub problem if already answer is find in any recursion call then return that answer other break this also 
//in the sub problem

#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>&dp){
        if(n<=1){
                return n;
        }
        if(dp[n]!=-1){//if already data is there then do not calculate again
                return dp[n];
        }
        dp[n]=fib(n-1,dp)+fib(n-2,dp);//memoization
        return dp[n];
}

int main()
{
        /*
        *  Write your code here.
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */

        int n;
        cin>>n;
        //step 1 create dp
        vector<int>dp(n+1,-1);
        //recursion call
        cout<<fib(n,dp)<<endl;
        return 0;

}



//********************************* BOTTOM UP APPROACH *********************

//in this first find the answer of the base case and after this calculate the answer for their parent problem's

#include<bits/stdc++.h>
using namespace std;

int main()
{


        int n;
        cin>>n;
        //step 1 create dp
        vector<int>dp(n+1,-1);

        //recursion call
        dp[0]=0;                     //base case solution
        dp[1]=1;                     //base case solution
        for(int i=2;i<n+1;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;
        return 0;

}


//****************************** Space opti in bottom approach ***************************
//TC=O(N)
//SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{


        int n;
        cin>>n;
        //we know that current element is depand on the previous two element, so why we store the all data in vector instead of this use \
        //three variable to solve this
        int dp1=0;
        int dp2=1;
        int dpo;
        if(n==0){
            return 0;
        }
        for(int i=2;i<n+1;i++){
                dpo=dp2;
                dp2=dp1+dp2;
                dp1=dpo;
        }
        cout<<dp2<<endl;
        return 0;

}