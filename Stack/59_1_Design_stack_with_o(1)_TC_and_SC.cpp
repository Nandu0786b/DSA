// Design a stack that supports getMin() in O(1) time and O(1) extra space/
// https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?leftPanelTab=0



// Approach : main thing is that when we push data in it, that time we will check if data is less then mini, then
// we will update push curr in stack as 2*data-mini and this data now will be minimum
// when we remove(pop) data and find curr<mini then we return mini as current element and mini will be 2*mini-curr

// suppose we are having last data x and mini and this data is less then mini then push element will be = 2*data-previous_mini
//  and mini will be data 
// if i remove again and curr<data then 
// mini = 2*mini-curr_data (curr_data=2*data-mini and current mini is the last data)
// so mini =2*data-(2*data-previous_mini)
// so hence mini=previous_data so we get the previous data




#include<stack>
class SpecialStack {
    // Define the data members.
    stack<int>s;
    int mini;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
            if(mini<data){
                s.push(data);
            }
            else{
                s.push(2*data-mini);
                mini=data;
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()){
            return false;
        }
        else{
            int curr=s.top();
            s.pop();
            if(curr<mini){
                int prevmin=mini;
                mini=2*mini-curr;
                return prevmin;
            }
            return curr;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr=s.top();
        if(curr<mini){
            return mini;

        }
        return curr;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};