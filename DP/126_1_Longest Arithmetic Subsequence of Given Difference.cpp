// Longest Arithmetic Subsequence of Given Difference

// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/



class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            //calculate the diff
            int temp= arr[i]-difference;
            int tempAns=0;

            //check answer exit for the temp or not
            if(dp.count(temp))
                tempAns=dp[temp];

            //current answer update
            dp[arr[i]]=1+tempAns;

            ans=max(ans, dp[arr[i]]);
        }
        return ans;
    }
};