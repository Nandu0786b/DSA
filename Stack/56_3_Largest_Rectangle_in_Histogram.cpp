// Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Hard

// basically first we find the next and previous smallest element using the previous method after this we simply in previous question we are 
// find nearest small and storing there number but in this we will store there index because we need width of rectangle. once this calculated 
// after this width will be next[i]-previous[i]-1 if next[i]==-1 it means in the next we are having all similar size or this is the last so in 
// this case we will put this by the N which is size of the vector  previous question are done based on the value but in this done based on the index
// while(s.top()!=-1 &&  arr[s.top()]>=curr){
            //     s.pop();
            // }   in this s.top()!=-1  condition applied so array not go out of index , because s.top() is giving the array index so for the comparison 
            // of values we did arr[s.top()]>=curr

class Solution {
    private:
    vector<int> nextsmallerElement(vector<int> arr,int n){
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
    vector<int> prevsmallerElement(vector<int> arr,int n){
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

public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();

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
};