// k-th smallest element in BST
// Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

//Normal Morris traversal kiya hain bus 

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        Node* temp=root;
        int i=0;
        while(temp){
            if(!(temp->left)){
                i++;
                if(i==k){
                    return temp->data;
                    
                }
                temp=temp->right;
            }
            else{
                    Node* current=temp->left;
                    while(current->right && current->right!=temp){
                        current=current->right;
                    }
                    if(current->right==temp){
                        i++;
                        if(i==k){
                            return temp->data;
                            }
                        current->right=NULL;
                        temp=temp->right;
                    }
                    else{
                        current->right=temp;
                        temp=temp->left;
                            }
                
            }
    }
    return -1;
    }
};
