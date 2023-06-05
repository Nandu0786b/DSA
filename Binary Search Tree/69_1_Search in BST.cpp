Search in a Binary Search Tree
// Search in a Binary Search Tree
//easy

// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/963706950/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        if(val<root->val){
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);
        }
    }
};