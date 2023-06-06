//H>W

// Binary Tree to DLL
// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

// Convert A Given Binary Tree To Doubly Linked List
// https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106

// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/


//************************ BY LOVE *******************************************************
//if start from the first Node
Node* prev = NULL;
    Node* head = NULL;
    void converter(Node *root)
    {
        if(root==NULL){
            return;
        } 
        converter(root->left);
        if(prev == NULL) {
            head=root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        converter(root->right);
    }
    Node * bToDLL(Node *root){
        converter(root);
        return head;
    }

//if start from the last Node
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* convertIntoDLL(Node* root, Node* &head)
    {
        if(root==NULL)
        return NULL;
        
        convertIntoDLL(root->right, head);
        
        root-> right= head;
        if(head!=NULL)
        {
            head->left=root;
        }
        head=root;
        
        convertIntoDLL(root->left,  head);
        return head;
    }
    Node * bToDLL(Node *root)
    {
        Node* head= NULL;
        head=convertIntoDLL(root, head);
        return head;
    }
};
//********************* BY ME ************************************************************
class Solution
{   private:
    void solve(Node* root,vector<Node*>&v){
        if(root==NULL){
            return ;
        }
        solve(root->left,v);
        v.push_back(root);
        solve(root->right,v);
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {   
        if(root==NULL){
            return NULL;
        }
        // your code here
        vector<Node*>v;
        solve(root,v);
        int s=v.size();
        v[0]->left=NULL;
        if(s>1){
          v[0]->right=v[1];  
        }
        else{
            v[0]->right=NULL;
        }
        
        for(int i=1;i<s-1;i++){
            v[i]->right=v[i+1];
            v[i]->left=v[i-1];
        }
        if(s>1){
            v[s-1]->left=v[s-2];
            v[s-1]->right=NULL;
        }
        
        
        return v[0];
    }
};

