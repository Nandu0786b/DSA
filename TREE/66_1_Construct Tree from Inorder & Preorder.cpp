// Construct Tree from Inorder & Preorder
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1
//medium

// https://www.codingninjas.com/codestudio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539
// https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106
// https://www.codingninjas.com/codestudio/problems/construct-tree-from-preorder-inorder_699832
//medium+easy

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//medium

//*************************************** BY LOVE *********************************************
//instead of using for loop to find the index we will us map, we store values in the map and will take as per our need
//but remember this approach is will be valid when binary tree has unique nodes if duplicate is there then it will lead to the incorrect solution

//**************************************** BY ME *************************************************
//TC=O(n^2), because ham na recursion ka andar for loop chala rakha hain
class Solution{
    private:
    int findelement(int *in,int ele,int start,int end){
        for(int i=start;i<end+1;i++){
            if(ele==in[i]){
                return i;
            }
        }
        return -1;//INT_MAX; we also can return this
        
    }
    //hamna index ko pass by reference liya hain taki ek bar node ko la lana ka bad who fir sa repeat na ho
    //agar es ko pass by value langa tho left call ma bhi who same preorder wala node ko proceess karega and right ma bhi same ko hi karega
    Node* solve(int* in,int* pre,int &index,int start,int end,int s){
        //base case when we processed the complete preorder array
        if(index>=s || start>end){ //basically index>=s confirm kartha hain ki ya last node pa return ho jaya yf fir tab return ho jaya jub 
        //start end sa bada ho jaya
            return NULL;
        }
        Node* root=new Node(pre[index]);//formation of current node, predorder ka current index hi apana node hain
        
        int position = findelement(in,pre[index],start,end);
        index++;                     // index ko aga bhi badya hain
        //recursive call for the left and right
        root->left=solve(in,pre,index,start,position-1,s);
        root->right=solve(in,pre,index,position+1,end,s);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index=0;
        return solve(in,pre,index,0,n-1,n);//last 0 and 0-1 is starting and ending index of the inorder
    }
};










//*************************************************************************************************
//chat gpt
class Solution {
private:
    int findElement(int* in, int ele, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == ele) {
                return i;
            }
        }
        return -1;
    }

    Node* buildTreeHelper(int* in, int* pre, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        Node* root = new Node(pre[preIndex]);
        preIndex++;

        if (inStart == inEnd) {
            return root;
        }

        int inIndex = findElement(in, root->data, inStart, inEnd);

        root->left = buildTreeHelper(in, pre, preIndex, inStart, inIndex - 1);
        root->right = buildTreeHelper(in, pre, preIndex, inIndex + 1, inEnd);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        return buildTreeHelper(in, pre, preIndex, 0, n - 1);
    }
};


