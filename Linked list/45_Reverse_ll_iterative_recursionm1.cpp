// https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=1
// Reverse Linked List
// TC=o(n),SC=o(n)

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

void reNode(Node* &curr,Node* &prev,Node* &head){
	if(curr->next==NULL){
		curr->next=prev;
		head=curr;
		return;
	}
	reNode(curr->next,curr,head);
	curr->next=prev;
	return;

}
Node* reverseLinkedList(Node *head)
{
    Node* prev=NULL;
	Node* curr=head;
	reNode(curr,prev,head);
	return head;

}