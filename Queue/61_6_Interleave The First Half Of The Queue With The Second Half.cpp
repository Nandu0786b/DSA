// Interleave The First Half Of The Queue With The Second Half
// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0


// better approach : just creat a new queue now add first half part in this, now implement below 4th step in this 
// means like our initila queue is 1,2,3,4,5,6 then our new_queue=1,2,3 and old_queue=4,5,6 and now start add in old queue new.front()
//  and also remove element now old.front() and also remove element loop will run till new queue is not become empty
// using stack not better approach
#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int n=q.size();
    stack<int>s;
    // step 1 reverse and add half part in the end
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    // step 2 add starting half part in the end
    for(int i=0;i<n/2;i++){
        q.push(q.front());
        q.pop();
    }
    // step 3 again add first half part in the stack
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    // step 4 remove one element from stack and add in the queue and now from queue also add element in the queue

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}