// Height of Binary Tree
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1


class Solution{
    private:
    int recu(struct Node* node,int h){
        if(node==NULL){
            return h;
        }
        return max(recu(node->left,h+1),recu(node->right,h+1));
    }
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        return recu(node,0);
    }
};