// Tree from Postorder and Inorder
// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

// https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


//same previous question ka logic bus index ending sa start karna because postorder ma root sab sa last ma hotha hain
//and is ma apan postorder ka index last sa start kar raha hain so hum ko right side ka tree phale built karna hain otherwise left side ka phlae karna pa 
// right side ka node left side ma aa jayega and answer will be wrong

// for an example :- inorder=[4 8 2 5 1 6 3 7] and postorder=[8 4 5 2 6 7 3 1]
//   in in order from from 4 to 5 is left tree and 4 to 7 is right tree now if we do recursion then our index will come on the 3 in postorder and 3 will be node
//  which we are going to build and it's for the right tree so first call right tree after you can call left tree

//*************************************** GFG ****************************************
//TC=O(n^2), SC=O(n) because ham na 
int findelement(int *in,int ele,int start,int end){
        for(int i=start;i<end+1;i++){
            if(ele==in[i]){
                return i;
            }
        }
        return -1; //INT_MIN; we also can return this 
        
    }
    //hamna index ko pass by reference liya hain taki ek bar node ko la lana ka bad who fir sa repeat na ho
    //agar es ko pass by value langa tho left call ma bhi who same preorder wala node ko proceess karega and right ma bhi same ko hi karega
    Node* solve(int* in,int* post,int &index,int start,int end,int s){
        //base case when we processed the complete preorder array
        if(index<0 || start>end){ //basically index>=s confirm kartha hain ki ya last node pa return ho jaya yf fir tab return ho jaya jub 
        //start end sa bada ho jaya
            return NULL;
        }
        Node* root=new Node(post[index]);//formation of current node, predorder ka current index hi apana node hain
        
        int position = findelement(in,post[index],start,end);
        index--;                     // index ko aga bhi badya hain
        //recursive call for the left and right
        root->right=solve(in,post,index,position+1,end,s);
        root->left=solve(in,post,index,start,position-1,s);
        
        return root;
    }
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int index=n-1;
    return solve(in,post,index,0,n-1,n);
}