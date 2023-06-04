// Print Right View of a Binary Tree

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
//Easy

// https://leetcode.com/problems/binary-tree-right-side-view/
//medium

// https://www.codingninjas.com/codestudio/problems/right-view_764605
//medium


//approach : same as th left view bus right wali call left sa phale kar di hain jis sa phale right side ka element push ho gaya hain ans vector ma


// **************** GFG *******************************************
class Solution
{   private:
    void solve(Node* root,vector<int>&ans,int level){
        if(root==NULL){
            return ;
        }
        
        //if below is true means we enterd in a new level and this is the first element
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
}
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       solve(root,ans,0);
       return ans;
    }
};

//************************** Leetcode **************************************************

class Solution {
private:
    void solve(TreeNode* root,vector<int>&ans,int level){
        if(root==NULL){
            return ;
        }
        
        //if below is true means we enterd in a new level and this is the first element
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
       // Your Code here
       vector<int>ans;
       solve(root,ans,0);
       return ans;
    }
};

// ************************* coding Ninjas **************************************************

void solve(BinaryTreeNode<int>* root,vector<int>&ans,int level){
        if(root==NULL){
            return ;
        }
        
        //if below is true means we enterd in a new level and this is the first element
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
       vector<int>ans;
       solve(root,ans,0);
       return ans;
}

