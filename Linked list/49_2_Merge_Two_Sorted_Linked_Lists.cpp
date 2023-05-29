// Merge Two Sorted Linked Lists
// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332

// old approach already done in array to add two sorted array by using two pointer type approach , Thos solution is different from the love bubar

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    Node<int>* head = first->data>second->data ? second : first;
    if(head==first){
        first = first->next;
    }
    if(head==second){
        second = second->next;
    }
    Node<int>* cur=head;
    // cout<<"haji \n"<<head->data<<endl<<first->data<<endl<<second->data<<endl;
    while(first!=NULL && second!=NULL){
        if(first->data>second->data){
            cur->next=second;
            cur=cur->next;
            second=second->next;
        }
        else{
            cur->next=first;
            cur=cur->next;
            first=first->next;
            
        }
    }
    while(first==NULL && second!=NULL){
        cur->next=second;
        cur=cur->next;
        second=second->next;
    }
    while(first!=NULL && second==NULL){
        cur->next=first;
        cur=cur->next;
        first=first->next;
    }
    return head;
}


//******************************* in above we are using while loop in end which is not required ***********

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

********************************** we do not require while loop in the above code in the end **************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    Node<int>* head = first->data>second->data ? (second,second->next) : (first,first->next);
    Node<int>* cur=head;
    // cout<<"haji \n"<<head->data<<endl<<first->data<<endl<<second->data<<endl;
    while(first!=NULL && second!=NULL){
        if(first->data>second->data){
            cur->next=second;
            cur=cur->next;
            second=second->next;
        }
        else{
            cur->next=first;
            cur=cur->next;
            first=first->next;
        }
    }
    if(first==NULL && second!=NULL){
        cur->next=second;
    }
    if(first!=NULL && second==NULL){
        cur->next=first;
    }
    return head;
}
