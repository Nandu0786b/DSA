// Q1// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// The solution set must not contain duplicate subsets. Return the solution in any order.
// set of all subset and number of element 2^n

class Solution {
private:
    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
        if (index>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums,output,index+1,ans);
        int element = nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};