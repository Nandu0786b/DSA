// Day 17 : Count Leaf Nodes
// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?leftPanelTab=0
// TC=o(n) becasue we extract all node one time , SC=o(1)

//************************* By me *********************************************
int count(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
   if(root->left==NULL && root->right==NULL){
       return 1;
   }

   return count(root->left)+count(root->right);



}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    return count(root);
}





//**************************** By love ***************************************
void count(BinaryTreeNode<int> *root,int &i){
    if(root==NULL){
        return;
    }
   if((root->left==NULL && root->right==NULL)){
       i++;
   }
    count(root->left,i);
    count(root->right,i);



}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int i=0;
    count(root,i);
    return i;
}