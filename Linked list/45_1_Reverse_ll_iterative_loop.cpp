// https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=1

// Reverse Linked List
// TC=o(n),SC=o(1)

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

Node* reverseLinkedList(Node *head)
{
	if(head->next==NULL || head==NULL){
		return head;
	}
    Node* prev=NULL;
	Node* curr=head;
	Node* forw=NULL;
	while(curr!=NULL){
		forw=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forw;
	}
	return prev;

}