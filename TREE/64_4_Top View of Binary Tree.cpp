// Top View of Binary Tree
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401

class Solution//gfg
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>m;// first int is the horizontal distance and second int is the showing data
        //condition :- top view ma only ek hi node dikhagega uska nicha ka sara node hide rahenga
        queue<pair<Node*,int>>q;//here int is showing the horizontal distance
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            //if in the map m, for this horizontal distance value not present do mapping else ignore m.find(hd)==m.end() will be equal if value not in the map
            if(m.find(hd)==m.end()){
                m[hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        for(auto i:m){//map iterate esa hi hotha hain i.first keys detha hain and i.second return the values
            ans.push_back(i.second);
        }
        return ans;
    }

};