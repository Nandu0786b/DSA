// Flatten BST To A Sorted List
// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459


//approach1: first we will store addres of nodes in the inorder which will be sorted manner after this from the first position to n-1 we will do
//arr[i]->right=arr[i+1]; and arr[i]->left=NULL if i<size()-1, if i=size()-1 then we will set both pointer on the NULL

//******************************** SOLUTION 1 ****************************
void inorder(TreeNode<int>* root, vector<int> &ino){
    if(root==NULL){
        return;
    }
    inorder(root->left,ino);
    ino.push_back(root->data);
    inorder(root->right,ino);
    
}
TreeNode<int> *flatten(TreeNode<int> *root) {
  // Write your code here
    vector<int> ino;

    inorder(root, ino);
    int s = ino.size();
    
    TreeNode<int> * newroot=new TreeNode<int>(ino[0]);
    TreeNode<int> * curr=newroot;
    for (int i = 1; i < s; i++){
            TreeNode<int> * temp=new TreeNode<int>(ino[i]);
            curr->left=NULL;
            curr->right=temp;
            curr=temp;
            
    }
    curr->left=NULL;
    curr->right=NULL;
    return newroot;
}


//*************************************** SOLUTION 2 ***********************************
//last test case is not working by me

void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &ino){
    if(root==NULL){
        return;
    }
    inorder(root->left,ino);
    ino.push_back(root);
    inorder(root->right,ino);
    
}
TreeNode<int> *flatten(TreeNode<int> *root) {
  // Write your code here
    vector<TreeNode<int> *> ino;

    inorder(root, ino);
    int s = ino.size();
    for (int i = 0; i < s-1; i++){
            ino[i]->right=ino[i+1];
            ino[i]->left=NULL;
            
    }
    ino[s-1]->left=NULL;
    ino[s-1]->right=NULL;
    return ino[0];
}

//approach2: in this first find the smallest element
//Now create link between the right most element to the root using the morris traversal
//Now start morris traversal from the smallest element from we start 
//if left is null then temp=temp->right
//else curr=temp->left and curr=curr->right->right jab thak ki null ya temp ka equal na ho jaya, jasa hi equal ho jaya temp->left=NULL
//and temp=temp->right and do this till that temp not become NULL
//some test case is not running, will see during revision

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* temp=root;
    TreeNode<int>* curr=root;
    TreeNode<int>* start=root;
    while(start->left){
        start=start->left;
    }
    while(temp){
        if(!temp->left){
            temp=temp->right;
        }
        else{
            curr=temp->left;
            while(curr->right && curr->right!=temp){
                curr=curr->right;
            }
            if(curr->right){
                temp=temp->right;
            }
            else{
                curr->right=temp;
                temp=temp->left;
            }
        }
    }
    temp=start;
    while(temp){
        if(!temp->left){
            temp=temp->right;
        }
        else{
            curr=temp->left;
            while(curr->right && curr->right!=temp){
                curr=curr->right;
            }
            if(curr->right){
                temp->left=NULL;
                temp=temp->right;
            }

        }
    }
    return start;
}