// Validate Binary Search Tree

// https://www.codingninjas.com/codestudio/problems/validate-bst_981275
// https://practice.geeksforgeeks.org/problems/check-for-bst/1
// https://leetcode.com/problems/validate-binary-search-tree/

//Approach: Basically recursive call ma left ka liya check kraenga ki who -infinite(INT_MIN) sa la kar maximumvalue(current parent) sa chota ho and right
// ma check karenga ki who minimum (current parent) sa bada hain INT_MAX sa chota ho


//**************************** LEET CODE *********************************

//**************************** CODING NINJAS *****************************
//No duplicate Nodes
bool isBSTUtil(BinaryTreeNode<int>* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }
        
        // Check if the current node's value is within the valid range
        if (root->data > minValue && root->data < maxValue) {
            bool left=isBSTUtil(root->left, minValue, root->data);
            bool right=isBSTUtil(root->right, root->data , maxValue);
            return left && right;
        }
        else{
            return false;
        }
        // Recursively check the left and right subtrees with updated range
        
    }
bool validateBST(BinaryTreeNode<int>* root) {
        // Start with a wide range for the root node
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
//**************************** GFG ***************************************
class Solution {
private:
    bool isBSTUtil(Node* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }
        
        // Check if the current node's value is within the valid range
        if (root->data > minValue && root->data < maxValue) {
            bool left=isBSTUtil(root->left, minValue, root->data);
            bool right=isBSTUtil(root->right, root->data , maxValue);
            return left && right;
        }
        else{
            return false;
        }
        // Recursively check the left and right subtrees with updated range
        
    }

public:
    bool isBST(Node* root) {
        // Start with a wide range for the root node
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};
// *************************** GFG ***************************************
//chatgpt
class Solution {
private:
    bool isBSTUtil(Node* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }
        
        // Check if the current node's value is within the valid range
        if (root->data < minValue || root->data > maxValue) {
            return false;
        }
        
        // Recursively check the left and right subtrees with updated range
        return isBSTUtil(root->left, minValue, root->data - 1) &&
               isBSTUtil(root->right, root->data + 1, maxValue);
    }

public:
    bool isBST(Node* root) {
        // Start with a wide range for the root node
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

//******************************* LEET CODE ****************************************
//[2147483647] to handle this case we have to use long long data types
class Solution {
private:
    bool isBST(TreeNode* root, long long minv, long long maxv) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val > minv && root->val < maxv) {
            return isBST(root->left, minv, root->val) && isBST(root->right, root->val, maxv);
        }
        
        return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};