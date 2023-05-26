// Reverse Stack Using Recursion
// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0

//here we are using previous question approach where we are adding element x in the bottom of the stack so here we will do the same stuff but here we will
// add one more layer of recureion on the previous function where we are going to extract all element from the list reursively and one the all is extracted then 
//  we will start to call previous function which will add all element at the end by using the backtracking

// TC=o(n^2) because we are calling recursion in the recursion 
// SC=o(n^2) because in the both recursion call we are storing o(n) time in both



void insertAtBottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    int pop=stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(pop);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);

}