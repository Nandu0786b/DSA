// Minimum Swaps To Make Sequences Increasing


// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

//Approach: In this also same algo as previous, on every case we can swap or we can ignore the swap
//For the swap there is one condition that if the current is less then the previous


//if we see in every case two variable are changing one is index and another one is swapped or not so here it will be 2D-DP question




//********************************* DP=>TABULATION &  SPACE OPTIMIZATION ***************




class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2){

        int n=nums1.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));


        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans=INT_MAX;
                int p1=nums1[index-1];
                int p2=nums2[index-1];
                if(swapped)
                    swap(p1, p2);
                if(nums1[index]>p1 && nums2[index]>p2)
                    ans=dp[1][0];
                if(nums1[index]>p2 && nums2[index]>p1)
                    ans=min(ans, 1+dp[1][1]);
                dp[0][swapped]=ans;
            }
            dp[1]=dp[0];
        }
        return min(dp[1][0], dp[1][1]);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1, nums2);
    }
};


//

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2){

        int n=nums1.size();
        int pswap=0;
        int pnoswap=0;
        int curswap=0;
        int curnoswap=0;


        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans=INT_MAX;
                int p1=nums1[index-1];
                int p2=nums2[index-1];
                if(swapped)
                    swap(p1, p2);
                if(nums1[index]>p1 && nums2[index]>p2)
                    ans=pnoswap;
                if(nums1[index]>p2 && nums2[index]>p1)
                    ans=min(ans, 1+pswap);
                if(swapped)
                    curswap=ans;
                else
                    curnoswap=ans;
            }
            pswap=curswap;
            pnoswap=curnoswap;
        }
        return min(pswap, pnoswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1, nums2);
    }
};

//********************************* DP=>TABULATION **************************



class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2){

        int n=nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));


        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans=INT_MAX;
                int p1=nums1[index-1];
                int p2=nums2[index-1];
                if(swapped)
                    swap(p1, p2);
                if(nums1[index]>p1 && nums2[index]>p2)
                    ans=dp[index+1][0];
                if(nums1[index]>p2 && nums2[index]>p1)
                    ans=min(ans, 1+dp[index+1][1]);
                dp[index][swapped]=ans;
            }
        }
        return min(dp[1][0], dp[1][1]);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1, nums2);
    }
};



//********************************* DP=>TOP TO DOWN APPROACH ****************



class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        //base case
        if(index==nums1.size())
            return 0;

        int ans=INT_MAX;

        int p1=nums1[index-1];
        int p2=nums2[index-1];
        if(dp[index][swapped]!=-1)
            return dp[index][swapped];
        //swap case
        if(swapped)//here we are doing swap because when we choose case of the swap on that time we are not swap in the origional array. So when we make next call on that time we are not get the swapped value we will get origional values to get swapped values we are doing this
            swap(p1, p2);

        //no swap case
        if(nums1[index]>p1 && nums2[index]>p2)
            ans=solve(nums1, nums2, index+1, 0, dp);

        //swap
        if(nums1[index]>p2 && nums2[index]>p1)
            ans=min(ans, 1+solve(nums1, nums2, index+1, 1, dp));

        return dp[index][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // here we are taking size of the second vector as 2, because there is two case if swap then min answer or if not swapped then min anser

        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
;        // means previous element is swapped or not
        bool swapped=false;
        return solve(nums1, nums2, 1, swapped, dp);
    }
};




//******************************** TLE ***************************************





class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        //base case
        if(index==nums1.size())
            return 0;

        int ans=INT_MAX;

        int p1=nums1[index-1];
        int p2=nums2[index-1];

        //swap case
        if(swapped)//here we are doing swap because when we choose case of the swap on that time we are not swap in the origional array. So when we make next call on that time we are not get the swapped value we will get origional values to get swapped values we are doing this
            swap(p1, p2);

        //no swap case
        if(nums1[index]>p1 && nums2[index]>p2)
            ans=solve(nums1, nums2, index+1, 0);

        //swap
        if(nums1[index]>p2 && nums2[index]>p1)//like if they are both big from each other previous it means there is also a swap case which we can do and this case may impact our answer
            ans=min(ans, 1+solve(nums1, nums2, index+1, 1));

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
;        // means previous element is swapped or not
        bool swapped=false;
        return solve(nums1, nums2, 1, swapped);
    }
};