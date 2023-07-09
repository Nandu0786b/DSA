// Kth Ancestor in a Tree
// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

// https://www.codingninjas.com/codestudio/problems/kth-ancestor-of-a-node-in-binary-tree_842561

//H.W : same question vector ki help sa karna hain iterative (with the help of loop), like store the value of Node in the vector and if you find vector then just iterate vector
// from end and return value of the Ancestor 

//approach : node ko visit karna start karo jaisa hi who node mil jaya reverse ho javo and k ko decrement karna suru kar do and jaha pa k zero ho jaya who hi 
// apana answer hoga, do case ka dayan rakhana hain root node ka ansector na puch la and and kth ki value uska number of parents sa jayda na ho 
// for an example uper node 4 hain and usna puch ki 5th or 6th Ancestor do us case ma bhi - return karna hain

//************************************* GFG ***************************************************
//easy
//1st solution

Node* solve(Node* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left=solve(root->left,k,node);
    Node* right=solve(root->right,k,node);
    if(left){
        if(k){
            k--;
            if(k==0){
                return root;
            }
        }
        return left;
    }
    else if(right){
        if(k){
            k--;
            if(k==0){
                return root;
            }
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(root->data==node){//case jisma root node ka liya pucha ho us case ma root node ka koi parent nahi hotha hain so -1 return karna hain
        return -1;
    }
    Node* kth=solve(root,k,node);
    if(kth && kth->data!=node){// kth->data!=node ya us case ma handle karna ka liya jaha pa number of parent k sa chota hain
        return kth->data;
    }
    return -1;
}

//2nd solution 
Node* solve(Node* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left=solve(root->left,k,node);
    Node* right=solve(root->right,k,node);
    if(left){
        if(k){
            k--;
            if(k==0){
                return root;
            }
        }
        return left;
    }
    else if(right){
        if(k){
            k--;
            if(k==0){
                return root;
            }
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{

    Node* kth=solve(root,k,node);
    if(kth && kth->data!=node){// kth->data!=node ya us case ma handle karna ka liya jaha pa number of parent k sa chota hain(is ma root case nhi handle because
    // root ka hi pucha tho kth ka data and node same honga)
        return kth->data;
    }
    return -1;
}

//soluion 3:
Node* solve(Node* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left=solve(root->left,k,node);
    Node* right=solve(root->right,k,node);
    if(left){
        if(left->data==node){
            k--;
            if(k==0){
                return root;
            }
        }
        return left;
    }
    else if(right){
        if(right->data==node){//basically is node ka data give node ka brabar nahi it means apana koAncestor mil gaya hain else k ko -- karo agar same hain tho
            k--;
            if(k==0){
                return root;
            }
        }
        return right;//suru ma tho us node ka address hoga jisko find karna ka liya bola hain but ek bar Ancestor mil jana ka bad uska address hoga
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{

    Node* kth=solve(root,k,node);
    if(kth && kth->data!=node){// kth->data!=node ya us case ma handle karna ka liya jaha pa number of parent k sa chota hain
        return kth->data;
    }
    return -1;
}


//*************************** CODING NINJAS **********************************/
BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    BinaryTreeNode<int>* left=solve(root->left,k,node);
    BinaryTreeNode<int>* right=solve(root->right,k,node);
    if(left){
        if(left->data==node){
            k--;
            if(k==0){
                return root;
            }
        }
        return left;
    }
    else if(right){
        if(right->data==node){//basically is node ka data give node ka brabar nahi it means apana koAncestor mil gaya hain else k ko -- karo agar same hain tho
            k--;
            if(k==0){
                return root;
            }
        }
        return right;//suru ma tho us node ka address hoga jisko find karna ka liya bola hain but ek bar Ancestor mil jana ka bad uska address hoga
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here.
    BinaryTreeNode<int> *kth=solve(root,k,node);
    if(kth && kth->data!=node){// kth->data!=node ya us case ma handle karna ka liya jaha pa number of parent k sa chota hain
        return kth->data;
    }
    return -1;
}

//**************************** LEET CODE ***************************************************************
// For the revision time of tree
