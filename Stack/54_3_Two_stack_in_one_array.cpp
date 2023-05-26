// here we are starting first stack from start and second stack from the end, so we are using the best space utilisation 
// second approach we can do using devide space in n/2 part for the both stack

#include <bits/stdc++.h> 
class TwoStack {

public:

    // Initialize TwoStack.
    int *arr;
    int top1;
    int top2;
    int size;
    TwoStack(int s) {
        // Write your code here.
        this->size=s;
        top1=-1;
        top2=s;
        arr= new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2-top1>1){//this condition show that we are having atleast one empty space
            top1++;
            arr[top1]=num;
            
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-top1>1){//this condition show that we are having atleast one empty space
            top2--;
            arr[top2]=num;
            
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>-1){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        return -1;
        
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        return -1;
    }
};
