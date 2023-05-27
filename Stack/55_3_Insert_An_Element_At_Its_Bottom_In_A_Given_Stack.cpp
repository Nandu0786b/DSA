// Insert An Element At Its Bottom In A Given Stack
// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0

// very simple pop kartha javo and jab empty ho jaya tho element push kar do and fir backtracking sa sara ka sara element fir sa add kar do
// TC=o(n),SC=o(n)

#include <bits/stdc++.h> 
void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int pop=myStack.top();
    myStack.pop();
    solve( myStack,x);
    myStack.push(pop);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve( myStack,x);
    return myStack;
}

