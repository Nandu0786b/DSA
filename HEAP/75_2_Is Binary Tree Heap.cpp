// Is Binary Tree Heap
// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1



//Basically hamna kya kiya hain ki sab sa phale total node count kar liaya hain fir hamna do function run kiya hain un ma sa ek function 
//check kartha hain complete binary tree hain ya nahi and second check kartha hain ki max heap hain ya nahi


// TC=o(n),SC=o(h)

//************************************* BY LOVE *****************************
class Solution {
    private:
    int Nodec(struct Node* root,int node){
        if(root==NULL){
            return 0;
        }
        return 1+Nodec(root->right,node+1)+Nodec(root->left,node+1);
        
    }
    bool isCBT(struct Node* root,int index,int cnt){
        if(root==NULL){
            return true;
        }
        if(index>=cnt){//ya dhi who null nahi hain and index total ka bhar hain it means who wo cbt nahi hain because kuch node uska phale 
        //wala unfilled hain
            return false;
        }
        else{
            bool left=isCBT(root->left,2*index+1,cnt);//left child
            bool right=isCBT(root->right,2*index+2,cnt);//right child
            return left &&right;
        }
    }
    bool iheap(struct Node* root){
        if(root->left==NULL && root->right==NULL){//leaf node is a heap
            return true;
        }
        else if(root->left && !root->right ){//if left is there and right is not there it means this is the last node, now we have to check only left condition
            return (root->data>root->left->data);
        }
        else if(!root->left && root->right){
            return false;
        }
        else{
            return iheap(root->left) && iheap(root->right) && (root->data>root->left->data) && (root->data>root->right->data);
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int index=0;
        int totalnode=Nodec(tree,0);
        if(isCBT(tree,index,totalnode) && iheap(tree)){
            return true;
        }
        return false;
    }
};
//**************************** BY ME **************************************

//i did all task in only one function instead of multiple function

class Solution {
    private:
    int Nodec(struct Node* root,int node){
        if(root==NULL){
            return 0;
        }
        return 1+Nodec(root->right,node+1)+Nodec(root->left,node+1);
        
    }
    bool iHeap(struct Node*  root,int i,int total){
        if(i>total){//ya dhi who null nahi hain and index total ka bhar hain it means who wo cbt nahi hain because kuch node uska phale 
        //wala unfilled hain
                 return false;
            }
        else if(!root->left && !root->right){
            return true;
        }
        else if(root->left && !root->right && root->left->data<root->data){
            return !root->left->left && !root->left->right  ;
        }
        else if(!root->left && root->right ){
           return false;
        }
        else if(root->left && root->right && root->left->data<root->data && root->right->data<root->data ){
            return iHeap(root->left , 2*i+1,total) && iHeap(root->right , 2*i+2,total) ;
        }
        return false;
         
    }
  public:
    bool isHeap(struct Node* tree) {
        if(tree==NULL){
            return true;
        }
        int node=Nodec(tree,0);
        return iHeap(tree,0,node);
    }
};

//**********************************************************************

//approach:level order traversal karna suru karo and usma ek flag rakh lo, jab bhi ek bar NULL aa jaya tho us ko true kar do but agar 
//uska bad fir sa koi element aa jaya tho waha sa false return kar do, element ko push kartha time ya bhi check kar lo ki uska left and right
//agar hain tho us sa chota ho agar nahi hain tho yahi sa false return kar do
bool iscbt(Node* root){
        if(root==NULL)
            return true;
        queue<Node*>q;
        q.push(root);
        int count=0;
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                if(it->left)
                 { 
                     if(it->data<it->left->data)
                        return false;
                     if(!flag)
                        return flag;
                     q.push(it->left);}
                else flag=false;
                if(it->right)
                     {   if(it->data<it->right->data)
                            return false;
                         if(!flag)
                            return flag;
                         q.push(it->right);
                         
                     }
                else
                    flag=false;
                
            }
            count++;
        }
        
        return true;
    }
// ********************************************************