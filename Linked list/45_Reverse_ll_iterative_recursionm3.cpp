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
Node* reNodev1(Node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* chotahead=reNodev1(head->next); //last wala ka address return kar raha hain 
	head->next->next=head; // isma aga wala ma current ka address dal raha hain
	head->next=NULL; // isma current ka next null kar raha hain
	return chotahead;// head ko return kar raha hain

}
Node* reverseLinkedList(Node *head)
{

	return reNodev1(head);

}