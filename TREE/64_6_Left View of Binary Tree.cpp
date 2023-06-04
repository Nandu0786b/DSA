// Left View of Binary Tree
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
//easy gfg

// https://www.codingninjas.com/codestudio/problems/left-view-of-a-binary-tree_920519?leftPanelTab=1
//easy coding ninjas 









// ********************************* GFG **********************
//Function to return a list containing elements of left view of the binary tree.
void solve(Node* root,vector<int>&ans,int level){
    if(root==NULL){
        return ;
    }
    
    //if below is true means we enterd in a new level and this is the first element
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   //we need left view so in every level we will enter only first left element
   vector<int>ans;
   solve(root,ans,0);
   return ans;
}


//************************ coding Ninjas ******************************************

void solve(TreeNode<int> *root,vector<int> &ans,int level){
    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>ans;
    solve(root,ans,0);
    return ans;
}