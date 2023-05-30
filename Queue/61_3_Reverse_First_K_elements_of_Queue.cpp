// Reverse First K elements of Queue
// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// phale puri queue ko reverse kar lo stack ki help sa and fir wapis first q.size()-k element ko reverse kar lo
//another is also


queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
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
    int i=0;
    int n=q.size();
    while(!q.empty() && i<n-k){
        i++;
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
    
}