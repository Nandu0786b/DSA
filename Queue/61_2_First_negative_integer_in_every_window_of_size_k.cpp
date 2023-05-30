// First negative integer in every window of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    deque<long long int> dq;
    vector<long long> ans;
    // first hamna 1 window ko process kiya 
    for(int i=0;i<k;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    // uska bad remaining ko process kiya
    for(int i=k;i<N;i++){
        if(!dq.empty() && i-dq.front()>=k){//ya wali step window ko aga shift karna ka kam athi hain i-dq.front() ya confirm kartha hain ki dq ka front current window ma atha hain ya fir nahi
            dq.pop_front();
        }
        if(A[i]<0){
            dq.push_back(i);
        }
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
        }
    else{
        ans.push_back(0);
        }
    }      
    return ans;
 }