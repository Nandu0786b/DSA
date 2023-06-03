// Burning Tree
// https://practice.geeksforgeeks.org/problems/burning-tree/1

// https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
//same approach we have to apply but some thing is different

class Solution {
  public:
    Node* ctop(Node* root,map<Node*,Node*>&cp,int target){
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        cp[root]=NULL;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->data==target){
                res=front;
            }
            if(front->left){
                cp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                cp[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
        
    }
    int burnTree(Node* root,map<Node*,Node*>&cp){
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        int ans=0;
         
        while(!q.empty()){
            bool flag=0; // to check if New Node added in the queue to burn or first time visited
            int size=q.size();
            for(int i=0;i<size;i++){
                //process child and parent
                Node* front=q.front();
                q.pop();
                //now to burn there is  three Node left,right,parent
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;
                }
                if(cp[front] && !visited[cp[front]]){
                    q.push(cp[front]);
                    visited[cp[front]]=true;
                    flag=1;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        //Your code goes here
        //create child to parent mapping, and it also find target Node in the same function call during the map
        map<Node*,Node*>cp;
        Node* TargetNode=ctop(root,cp,target);
        //Find minimum Time To Burn Complete Tree
        //For the last step we will use map to track visited Node and queue to which we have to visit Next
        int ans=burnTree(TargetNode,cp);
        return ans;
        
    }
};