// ZigZag Tree Traversal
// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// basically is question ma phale ek level ka sara Node ko traversal kiya hain and same time pa unka child ko Queue ma bhi store kar liya hain
// and every time uthni hi queue ko process kiya hain jithana ma ki ek level ks sara aa jaya.

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans; // this to store traversal in order
    	if(root==NULL){
    	    return ans;
    	}
    	queue<Node*>q; //To track order of Traversal
    	q.push(root);
    	bool ltr=true; //Will tell left to right or right to left
    	while(!q.empty()){
    	    int size=q.size(); 
    	    vector<int>temp(size); //To store r to l or l to r order in a level
    	    for(int i=0;i<size;i++){
    	        Node* frontNode=q.front();
    	        q.pop();
    	        int index=ltr? i:size-i-1; //will tell that where from the traversal start from last or start in the level
    	        temp[index]=frontNode->data;
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    ltr=!ltr;
    	 
    	 for(auto i:temp){ //once one level is visited then just push data of these Nodes in the ans vector
    	     ans.push_back(i);
    	 }   
    	}
    	return ans;
    	
    }
};