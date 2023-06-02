// Diameter of a Binary Tree
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// basically yaha pa do node ka beech ki distance return karni hain jo ki maximum ho
// so uska three option hain first left node sa ho, second option jisma only right side ma ho root ka, third jis ma 
// left+root+right ho 
// is approach ma TC=O(n) hain because we did all thing in the single traversal, and we return height and diameter in single call using the
// pair
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int>diameterfast(Node* root){
         if(root==NULL){
             pair<int,int> p=make_pair(0,0);//first block shows the diameter and scond block shows the height
            return p;
        }
        pair<int,int>left=diameterfast(root->left);
        pair<int,int>right=diameterfast(root->right);
        int op1=left.first;
        int op2=right.first;;
        int op3=left.second+right.second+1;
        pair<int,int> ans;
        ans.first= max(op1,max(op2,op3));//maximum diameter return kar raha hain
        ans.second=max(left.second,right.second)+1;//maximum height return kar raha hain
        return ans;
}
    int diameter(Node* root) {
       return diameterfast(root).first;
    }
};




// but in this approach TC is o(n^2) because hum diameter ka andar height ko call kar raha hain like a nested loop also for the SC

class Solution {
  private:
    int height(struct Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root==NULL){
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+1;
        return max(op1,max(op2,op3));
    }
};