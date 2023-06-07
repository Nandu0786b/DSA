// Normal BST To Balanced BST
// https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472

// 1382. Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree/

// Normal BST to Balanced BST
// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

//approach: first store bst in the vector inorder(sorted)
//Now start from the mid of vector first half part will be left tree and another part will be right tree, use recursion

//****************************************************************
//SC=o(n),TC=O(n)
void inorder(TreeNode<int>* root,vector<int> &v){
    if(root==NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
TreeNode<int>* balanced(int s,int e,vector<int> &v){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left=balanced(s,mid-1,v);
    root->right=balanced(mid+1,e,v);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inorder(root,v);
    int s=v.size();
    root=balanced(0,s-1,v);
    return root;
}