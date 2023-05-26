// Sort a Stack
// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0

// same on the previous logic , simply extract all elemet of the stack now instead of inerting at bottom , insert when stack.top() is less then the element
// TC=o(n^2),SC=o(n^2)


#include <bits/stdc++.h> 
void insertInSort(stack<int> &stack,int num){
	if(stack.empty() || num>stack.top()){
		stack.push(num);
		return;
	}
	int pop=stack.top();
	stack.pop();
	insertInSort(stack,num);
	stack.push(pop);

}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);

	insertInSort(stack,num);

}