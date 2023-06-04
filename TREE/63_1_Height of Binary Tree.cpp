// Height of Binary Tree
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// TC=O(n) because we visit every node
// SC=O(h) hum function ma kuch store tho nahi kar raha hain but recursion ki wajha sa function ek call stack ban raha hain jaha pa 
// worst case ma h function ki call store karni hogi


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