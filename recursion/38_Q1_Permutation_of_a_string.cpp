// https://www.codingninjas.com/codestudio/problems/permutations-of-a-string_985254
// https://leetcode.com/problems/permutations/submissions/938331138/
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

// here we are using swap and backtracking to ignore extra memory
//  in another approach we can use one data strcture and map to store key that is already used in the answer

class Solution {
private:
    void solve(vector<int> nums,int index,vector<vector<int>>& ans){
        if (index>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for (int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,index,ans);
        return ans;
    }
};