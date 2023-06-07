// Two Sum IV - Input is a BST
// https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=1
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Approach: BST ko inorder ma save ka lo and who always sorted hoga
//Now apply two pointer approach start i from the start and start j from the end
//now arr[i]+arr[j]=> Now there is three chances 
//1st=.sum is equal to the target in that case we will return true
//if some is greate then taregt in that case we will decrase j pointer because if j decrease value also going to deecrease so some also decrease
//if some is less then target in that we will increase value of i because with i arr[i] value also increase so some also going to increase
//we will run for loop till i<j
//in this i am doing inorder with Morris traversal due to this it's become long but we also can do using recursion which will be easy


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    if(root==NULL){
        return false;
    }
    vector<int>ino;
    BinaryTreeNode<int>* temp=root;
    BinaryTreeNode<int>* curr=NULL;
    while(temp){
        if(!temp->left){
            ino.push_back(temp->data);
            temp=temp->right;
        }
        else{
            curr=temp->left;
            while(curr->right && curr->right!=temp){
                curr=curr->right;
            }
            if(curr->right){
                ino.push_back(temp->data);
                temp=temp->right;
                curr->right=NULL;
            }
            else{
                curr->right=temp;
                temp=temp->left;
            }
        }
    }
    int s=ino.size();
    int j=s-1;
    int i=0;
    while(i<j){
        if(ino[i]+ino[j]==target){
            return true;
        }
        else if(ino[i]+ino[j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;

}


//approach2: store element in the map during inorder traversal and map<int,int>, first int represent an element and second represent the sum-element
//Now when we push new element then if root is null return false
//Now if (sum-element) is already present in the element then return true else store this value and go for the next element in the inorder traversal

//********************************** LEET CODE *****************************************
//using the second approach

class Solution {
private:
    bool solve(TreeNode* root,int k,unordered_map<int,int> &m){
        if(root==NULL){
            return false;
        }
        if(m.find(k-root->val)!=m.end()){
            return true;
        }
        m[root->val]=k-root->val;
        return solve(root->left,k,m) || solve(root->right,k,m);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        unordered_map<int,int>m;
        return solve(root,k,m);
    }
};




