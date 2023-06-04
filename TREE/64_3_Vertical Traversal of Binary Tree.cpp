// Vertical Traversal of Binary Tree
// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533
// Medium on gfg, Hard on leetcode
class Solution//gfg
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,map<int,vector<int> > >m; //first int showing horizontal mapping,second map int showing levels or vertical mapping
        //in the end vector showing list of the nodes
        queue<pair<Node* ,pair<int,int> > > q;//this queue is to track Node,it's level and Numbring 
        //on the horizonatl scale
        vector<int>ans;
        if(root==NULL){
            return ans;         
        }
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lev=temp.second.second;
            m[hd][lev].push_back(frontNode->data);
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lev+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lev+1)));
            }
            
            
            
        }
        for(auto i:m){
            //i will present<int,map> and map present <int,vector> and we need data of the vector
            // hd=i.first; 
            for(auto j:i.second){
                // lev=j.first;
                // vector=j.second;
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;

        

    }
};
