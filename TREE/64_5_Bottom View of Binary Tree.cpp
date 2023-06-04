// Bottom View of Binary Tree
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//medium
// https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110
//medium

class Solution {//gfg
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            
            //ibottom view ma apana ko har bar update karna hain values ko and final ma sab sa bottom ki value 
            //ayengi and who hi apana ko chiyea thi but top ma apana ko first value chiyea thi is liya waha pa
            //new values push kartha time phale check kar raha tha
            m[hd]=frontNode->data;
            
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