// Reverse List In K Groups
// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644
// Sample Input 1:
// 2
// 1 2 3 4 5 6 -1
// 2
// 5 4 3 7 9 2 -1
// 4 
// Sample Output 1:
// 2 1 4 3 6 5
// 7 3 4 5 2 9
// Explanation Of The Sample Input1:
// For the first test case, we reverse the nodes in groups of two, so we get the modified linked list as 2 1 4 3 6 5.
// For the second test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so we reverse those two elements only. Hence the linked list becomes 7 3 4 5 2 9.
// Sample Input 2:
// 2
// 3 2 1 4 5 6 -1
// 1
// 4 3 2 8 -1
// 4 
// Sample Output 2:
// 3 2 1 4 5 6
// 4 3 2 8

//TC=o(n),SC=o(n)
//solution

#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head==NULL){
        return NULL;
    };
    Node* pre=NULL;
    Node* next=NULL;
    Node* curr=head;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next; //to not lose next remaining list
        curr->next=pre;  //reverse current node and , pointing the previous node
        pre=curr;        //one shift for the previous node
        curr=next;       //shift current node
        count++;        //increment count
    };
    if(next!=NULL){
        head->next=kReverse(next,k);  //in the reverse group now end is the last part of the list so head is point the last node and this lint will connect to the next remaing list
    };
    return pre;//last node of this group now became the head of this group

}