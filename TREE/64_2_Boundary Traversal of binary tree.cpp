// Boundary Traversal of binary tree
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// approach : print all left of ----left exclusive leaf Node + Print all Leaf node + Print all right 
// of right of right ---- till root (Means Rifgt part will be in the reverse order) Exclusive leaf Node
// Medium



class Solution {
    void left(Node* root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
         left(root->left,ans);   
        }
        else{
            left(root->right,ans); //kisi teat case ma esa bhi hoga ki uska left part tho null hain but uska
            //right part ka tree ma jana ka bad left tree fir sa start ho raha hain or may be waha sa 3 right continue
            //ho and uska bad leaf node aya and unka koi bhi left node na ho un right walo ka so who leaf node ma bhi 
            //count nahi honga but who boundary node hain so unko yahi pa cover kiya hain
        }
    }
    void right(Node* root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
         right(root->right,ans);   
        }
        else{
            right(root->left,ans); 
        }
        ans.push_back(root->data);
    }
    void leaf(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
        //only leaf ko hi store karna hain jo ki hum already store kar chuka hain jub hamna is function ko return kiya hain
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data); //ya wala alreay root node ka data add kar chuka hain so in the below we not require to send root again we will send child of the root 
        left(root->left,ans);
        leaf(root->left,ans); //yaha pa leaf Node ki counting root ka left and right ka liya alag alag ki hain 
        leaf(root->right,ans);//because agar root node ka left and right null hua tho who do bar push ho jayaenga
        //ek bar is function ma and ek bar leaf wala ma 
        right(root->right,ans);
        return ans;
        
    }
};


// only single time leaf function call

class Solution {
    void left(Node* root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
         left(root->left,ans);   
        }
        else{
            left(root->right,ans); //kisi teat case ma esa bhi hoga ki uska left part tho null hain but uska
            //right part ka tree ma jana ka bad left tree fir sa start ho raha hain or may be waha sa 3 right continue
            //ho and uska bad leaf node aya and unka koi bhi left node na ho un right walo ka so who leaf node ma bhi 
            //count nahi honga but who boundary node hain so unko yahi pa cover kiya hain
        }
    }
    void right(Node* root,vector<int>&ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
         right(root->right,ans);   
        }
        else{
            right(root->left,ans); 
        }
        ans.push_back(root->data);
    }
    void leaf(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
        //only leaf ko hi store karna hain jo ki hum already store kar chuka hain jub hamna is function ko return kiya hain
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        ans.push_back(root->data);
        if(root==NULL || (root->left==NULL && root->right==NULL)){// case when root is null or single node in a tree
            return ans;
        }
        left(root->left,ans);
        leaf(root,ans); 
        right(root->right,ans);
        return ans;
        
    }
};