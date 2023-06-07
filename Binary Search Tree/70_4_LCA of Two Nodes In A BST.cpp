// LCA of Two Nodes In A BST
// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280

// Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//APPROACH : Binary tree ma ya confirm nahi tha ki who element kaha pa milega but BST ma ya confirm hotha hain ki ya tho 
// left ma hoga ya right ma hoga 
//Case1: agar dono node root sa chota hain it means who left ma hain and unka LCA bhi left ma hain
//case2: agar dono node root sa bada it means who right ma hain and unka LCA bhi right ma hain
//case3: but agar ek bada and ek chota hain it means root hi unka answer hoga because who hi who node hoga jo un dono ka liya common hain sab sa phala Node
//agar dono ek hi side ma hua ya fir who case bana jab ek child ho and and ek parent ho tho parent pa atha hi last wala return ho jayega

//********************* CODING NINJAS ******************************************
//solution1
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    if (root->data < p -> data && root->data < q->data) {
      return LCAinaBST(root->right, p, q);
    } 
    else if (root->data > p->data && root->data > q->data){
        return LCAinaBST(root->left,p,q);
    }
    return root;
}

//solution2

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    while(root){
        if (root->data < p -> data && root->data < q->data) {
            root=root->right;
        } 
        else if (root->data > p->data && root->data > q->data){
            root=root->left;
        }
        else{
            return root;
        }
        }
    
}

//************************** LEETCODE ***********************************
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        while(root!=NULL){
            if(root->val>p->val && root->val >q->val){
                root=root->left;
            }
            else if(root->val<p->val && root->val <q->val){
                root=root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
};