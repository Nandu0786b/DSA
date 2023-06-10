// Merge k Sorted Lists

// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772
// https://leetcode.com/problems/merge-k-sorted-lists/


//approach:create a min heap,and insert first element of the all LINKED LIST
//Now create two pointer one will be head and another is tail
//if the first element then head and tail dono ko wahi pa point kar do
//else if pop front of mean heap and and push in the answer queue and and insert next element from that array if element is remaining
//in the end return head
//es ma purana wala ki traha alag sa node bana ki jarrort nahi hain because apana pass already linked list ka link hain jis ma aga wala  ki details hain
// TC=>O(n*k)*log(k) ,SC=o(k)
#include<queue>
class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data>b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    priority_queue<Node<int>*,vector<Node<int>*>,compare>mini;
    int k=listArray.size();
    if(k==0){
        return 0;
    }
    for(int i=0;i<k;i++){//TC=>o(k)
        if(listArray[i]!=NULL){
            mini.push(listArray[i]);
        }
    }
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    while(mini.size()>0){//TC=>O(n*k)*log(k),first for the while loop and remaining for the min heap queue
        Node<int>* top=mini.top();
        mini.pop();
        if(!head){
            head=tail=top;
        }
        else{
            tail->next=top;
            tail=top;
        }
        if(top->next){
            mini.push(top->next);
        }
    }
    return head;
}









//approach:sari linked list ka data(node) ko vector ma dal do, TC=> o(n*m),SC=O(n*m)
//and unko ab sort kar lo ,TC=>o(n*m * log(n*m))
//now sara node ko join kara do,TC=(n*m)
//return the head,tc=>o(1)
