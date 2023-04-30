// https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?leftPanelTab=0
// Middle Of Linked List
// basically in this first with the help of recursion i count the total element after returned th n/2+1 element but this did in two recursion
//TC=o(n)+o(n/2)=o(n)

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
Node* middlen(Node* &head,int n,int cnt){
    if(cnt==((n/2)+1)){
        return head;
    }
    middlen(head->next,n,cnt+1);
}
int middle(Node* head,int cnt){
    if(head==NULL || head->next==NULL){
        return cnt;//yaha pa cnt+1 nahi karna other wise ya last case ma already function call kartha time cnt ko ek sa bada diya tha nad ya length ko 1 sa or bada dega
    }
    middle(head->next,cnt+1);

}

Node *findMiddle(Node *head) {
    // Write your code here
    int n=middle(head,1);
    // Now yaha pa direct while loop laga ka bhi kar saktha hain or ek new recursive call kar ka bhi kar saktha hain
    return middlen(head,n,1);
}