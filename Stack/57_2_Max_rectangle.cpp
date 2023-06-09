// Max rectangle
// https://practice.geeksforgeeks.org/problems/max-rectangle/1
// https://leetcode.com/problems/maximal-rectangle/
// https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

// very simple previous 56 wali max ractangle wali approach, baically start a loop for the every row in i=0 send only 0th row and check the maximum 
// histogram area and store the maximum area , now next time send previous row and current row with the column wise sum and if in the current row if any 
// element then that column set completely zero
// finaly return the maxarea


class Solution{
    private:
    vector<int> nextsmallerElement(int *arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1 &&  arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmallerElement(int *arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1 &&  arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(int *heights, int n) {

       vector<int> next(n);
       next=nextsmallerElement(heights,n);
       vector<int> prev(n);
       prev=prevsmallerElement(heights,n);
       int area=INT_MIN;
       for(int i=0;i<n;i++){
           int l=heights[i];
          
           if(next[i]==-1){
               next[i]=n;
           }
            int b=next[i]-prev[i]-1;
           int newArea = l*b;
           area=max(area,newArea);
       }
       return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area=largestRectangleArea(M[0], m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];}
            }
            area=max(area,largestRectangleArea(M[i], m));
        }
        return area;
    }
};