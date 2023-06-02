// Check for Balanced Tree
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// question katha hain ki sara parent node ka left and child node ki height ka diff less then or equal to 1 hain tho balanced hain else nahi
//TC=o(n), because hamna same hi call ma sub kuch kar liya hain

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    pair<bool,int> Balancedfast(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=Balancedfast(root->left);
        pair<bool,int> right=Balancedfast(root->right);
        bool dif=abs (left.second-right.second)<=1;
        
        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;
        
        if(left.first && right.first && dif){
            ans.first=true;
        }
        else{
            return ans;
        };
        return ans;
    }
    bool isBalanced(Node *root)
    {
       return Balancedfast(root).first;
    }
};

// is approach ma TC=o(n^2) hain due to the two call one for isbalanced and another for the height
class Solution{
    private:
        int height(Node* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool dif=abs (height(root->left)-height(root->right))<=1;
        if(left && right && dif){
            return 1;
        }
        else{
            return 0;
        };
    }
};