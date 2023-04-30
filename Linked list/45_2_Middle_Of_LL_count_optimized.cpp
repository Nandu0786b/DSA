// https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?leftPanelTab=0
// Middle Of Linked List
// basically we are doing two pointer approach where one pointer is slow and another is fast (2x of slow) so when fast cover all element then our slow pointer will be on n/2 element so returh the slow->next address;
//TC=o(n/2)


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
Node* middle(Node* &heado,Node* &headf){
    if(heado==NULL||heado->next==NULL){
        return heado;
    }
    if(headf->next==NULL||headf->next->next==NULL){
        // in this we are not tracing the headf==NULL beacuse this case is not possible
        //in this we are checking headf->next==NULL||headf->next->next==NULL beacuse this help us to ignore case where we will be on the last element or second last element headf->next==NULL(for last element), for second last element (headf->next->next==NULL)
        return heado->next;
    }
    return middle(heado->next,headf->next->next);

}

Node *findMiddle(Node *head) {
    // Write your code here
    //yha pa recursion ki jagha pa direct while loop laga ka bhi kar saktha hain like love babbar
    return middle(head,head->next);
}