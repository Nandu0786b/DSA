// Convert BST to Min Heap
// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498


//first bst ka in order nikal lo jo ki already sorted hotha hain, now bst ma us array sa preorder data insert kar do
//we don't have to change any strcture because we already have all set


void inorder(BinaryTreeNode* root,vector<int> &o){
	if(root==NULL){
		return ;
	}
	inorder(root->left,o);
	o.push_back(root->data);
	inorder(root->right,o);
}
void fp(BinaryTreeNode* root,vector<int> &o,int i){
	if(root==NULL){
		return;
	}
	if(i<o.size()){
		cout<<"going to add "<<o[i]<<" at "<<i<<endl;
		root->data=o[i];
	fp(root->left,o,2*i+1);
	fp(root->right,o,2*i+2);
	}
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> o;
	inorder(root,o);
	fp(root,o,0);

	return root;
}