// Preorder traversal of a BST
// https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111

//basically apana ko bst ka preorder diya hua hain and preorder sa bst construct karna hain and uska root return karna hain

//approach3:-isma preorder ko insert kartha jayenga agar who us range ma hain tho push kar do agar chota hain tho left ma dal do and agar bada
//hain tho right ma dal do
//TC=o(3n)=o(n), hamna har node ko three times visit kiya hain

BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int maxi,int &i ){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}

//approach2:- we now that if it's a bst then it's sorted form will be it's inorder, and we alreay have preorder so we can direct build tree from 
//the preorder and the inorder using the recursion we already solved question in the binary tree
//TC=o(nlog(n))

//approach3:- normal just suppose that array is like a input and we are going to create a bst from this input in the starting we will create a 
//root node and after this on every if root is null and we have to insert data then create node and assign that node to it's parent
//in every insertion we have to find out it's right position so worst case TC will be o(n^2)=>  o(n) to insert data,o(log(n)) to find right position
