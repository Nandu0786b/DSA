// Delete middle element from stack
// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

// very simple approach first pop , when count==size/2  now stop and using the backtracking again add poped element in the stack

#include <bits/stdc++.h> 
void solve(stack<int>&inputStack,int count , int size){
   if(count==size/2){
      inputStack.pop();
      return;
   }
   int pop=inputStack.top();
   inputStack.pop();
   solve(inputStack,count+1,size);
   inputStack.push(pop);

}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,count,N);
   
}
