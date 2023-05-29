// Circularly Linked
// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?leftPanelTab=0


#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){

    // Write your code here.
    if(head==NULL){//as in question said that empty is also circular
        return true;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){

        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){// if slow==false it means there is loop in the linked list but for 
        // the circular there loop should start from the head means slow==head but there is two chance odd or even element 
        // so may be possible that slow->next ==head
            if(slow==head ||slow->next==head)
                {return true;}
            else
                {   //there is loop in the list but it's not circular
                    return false;}
        }
        
    }
    return false;

}
