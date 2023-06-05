// Deletion in a Binary Tree
// https://leetcode.com/problems/delete-node-in-a-bst/
// https://practice.geeksforgeeks.org/problems/deletion-in-a-binary-tree/1


//approach : -
//First find the Node which we have to delete if Not find return the same root
//Now if root node is find, then there is Three case 
//1:- it is a leaf node then just delete the node remaining tree will be same
//2:- it have one children may be right or left, in that case just delete that node and replace by the children
//3:- Now in the last case it may have both left and right children in that case you can do one thing delete that node 
//and replace by the left maximum Node or right minim Node 

class Solution {
private:
    TreeNode* maxvalue(TreeNode* root){
    while(root->right){
        root=root->right;
    }
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // code here
    if(root==NULL){
        return root;
    }
    if(root->val==key){
        //0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        //only left child
        if(root->left && !root->right){
            TreeNode *temp=root->left;
            delete root;
            return temp;
        }
        //only right child
        if(!root->left && root->right){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        //Both Child Are present
        else {//if(root->left && root->right)
            // yaha pa do choice hain left sa maximum value la lo and right sa maximum value la lo
            int max=maxvalue(root->left)->val;
            root->val=max;
            root->left=deleteNode(root->left,max);
            return root;
            
        }
        
    }
    else if(root->val>key){
        root->left=deleteNode(root->left,key);
        return root;
    }
    else{
       root->right=deleteNode(root->right,key);
       return root;
    }
    }
};