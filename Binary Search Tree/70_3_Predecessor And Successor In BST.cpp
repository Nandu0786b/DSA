// Predecessor And Successor In BST
// https://www.codingninjas.com/codestudio/problems/_893049?leftPanelTab=0



pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    //find Key
    BinaryTreeNode<int>* temp=root;
    int pre=-1;
    int suc=-1;
    if(root==NULL){
      pair<int,int> ans=make_pair(pre,suc);
        return ans;  
    }
    while(temp->data!=key){
        if(temp->data>key){
            suc=temp->data; //this data is > key it means this is a possible suc
            temp=temp->left;
        }
        else{
            pre=temp->data; //this data is < key it means this is a possible pre
            temp=temp->right;
        }
    }
    BinaryTreeNode<int>* leftTree=temp->left; //predecessor always left part ma hi hoga
    while(leftTree!=NULL){
        pre=leftTree->data; //ek bar left ma ana ka bad hamesa right ma jatha jana hain jab thak ki who NULL na ho jaya
        // Just follow the LNR rule LNR LNR LNR it means if we see then in the inorder right->right....!NULL is predecessor
        leftTree=leftTree->right;
    }
    BinaryTreeNode<int>* rightTree=temp->right; //Successor always right part ma hi hoga
    while(rightTree!=NULL){
        suc=rightTree->data; //above logic
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pre,suc);
    return ans;

}
// we also can do one thing that just store inorder in the array and find key, front element of key will be the answer of predecessor and next of key 
//will succcessor 