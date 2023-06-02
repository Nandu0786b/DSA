// Sum Tree
// https://practice.geeksforgeeks.org/problems/sum-tree/1


// all is ok TC=O(n);

class Solution
{   private:
    pair<bool,int> checkfast(Node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
             return p;
        }
        if((root->left==NULL && root->right==NULL)){
            pair<bool,int>p=make_pair(true,root->data);
             return p;
         }
         pair<bool,int> left=checkfast(root->left);
         pair<bool,int>right=checkfast(root->right);
         bool check=left.second+right.second==root->data;
         pair<bool,int>ans;
         ans.second=left.second+right.second+root->data;
         if(left.first && left.first  && check){
             ans.first=true;
         }
         else{
             ans.first=false;
         }
         return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return checkfast(root).first;
    }
};