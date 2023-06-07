// Find K-th smallest Element in BST
// https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

//approach: basically inorder traversal kiya hain, inorder traversal sorted form ma hi hotha hain and jab bhi Node ko traversal karenga tho i
//ki value ko bada denga and jab i ki value k ka brabar ho jayegi tho who hi apana answer hoga
//if he ask k largest then we can do same thing but new_k=total_size-k+1 element will be our answer


//approach2: in this we can do one thing that just store inorder traversal in array and return (k-1)th element for the space complixity of o(1) we can use morris traversal and for
//the largest kth element we can start from the end or may be k=size-k-1 if we do from start

//***************************** GFG ***************************************
int solve(BinaryTreeNode<int>* root,int k,int &i){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,k,i);
    if(left !=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,k,i);
    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    return solve(root,k,i);
}

//***************************** LEET CODE *****************************

class Solution {
private:
    int inorder(TreeNode* root,int k,int &i){
        if(root==NULL){
            return -1;
        }
        int left=inorder(root->left,k,i);
        if(left!=-1){
            return left;
        }
        i++;
        if(i==k){
            return root->val;
        }
        return inorder(root->right,k,i);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return inorder(root,k,i);
    }
};

