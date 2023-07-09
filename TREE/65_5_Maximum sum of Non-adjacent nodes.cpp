// Maximum sum of Non-adjacent nodes
// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// medium
//TC=o(n), we travel all nodes once
//SC=o(n). because we are storing the values in pair so this will take space

// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-nodes-in-a-binary-tree-such-that-no-two-nodes-are-adjacent_1118112?leftPanelTab=0
//medium

// https://leetcode.com/problems/house-robber/description/
//medium -> main thing is that, in thisquestion we also apply the same approach like include and exclude for the max robbary 

//approach we are going to apply a approach, where we will have two option include or exclude, yadi haman add kiya hain tho hum previous ka solution ko add na 
// kar ka hum hum us sa phale wala ka solution add karenga but agar exclude kar raha hain tho  previous ma sa jo bhi maximum hoga usko lana hain means like left ma sa jo maximum hain
// and right ma sa jo maximum hain uka sum current ka exclude hoga

//*************************** GFG ********************************************

class Solution{
  private:
  pair<int,int> solve(Node* root){
      if(root==NULL){
          pair<int,int> p = make_pair(0,0);
          return p;
          }
    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);
    pair<int,int> res;
    res.first=root->data+left.second+right.second;   // case we are including current data
    res.second=max(left.first,left.second)+max(right.second,right.first); // case when we are not adding current data, in this case will take maximum from both side and will add this
    return res;
  }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};