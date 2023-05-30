// Queue Reversal
// https://practice.geeksforgeeks.org/problems/queue-reversal/1
// approach 1 : question can do with stack which we did
// approach 2 : same question we can do with recursion lik stack base condition will be when queue empty return, main thing is that once all element removed
// Now we will reverse and we will push last element first in the list
// approach 3 : Now next thing same thing we can do with array like first add all element in the array now again remove element from the array in the reverse order and add in the queue


queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        s.push(element);
        q.pop();
    }
    while(!s.empty()){
        int element=s.top();
        q.push(element);
        s.pop();
    }
    return q;
}

