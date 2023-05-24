// head=head->next , here we are changing the head value not the node values like previously head pointer is pointing on the nodex and now on the node x+1
// head->next=xyz , this operation is directly going on the node of the linked list 


#include <iostream>
using namespace std;
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
Node* value(Node* head){
    //here the linked list pointer value is passed by the reference it means this head is created a new copied value it means 
    // it is pointing the same first node of the linked list or the same memory but it's created a new and it's address is different from the 
    // origional address.if now i changed the value of head like i assigned new address to it then my origional head value will not changed 
    // but if i perform any operation with the head->next or head->data then it will affect the origional data because still it's pointing the origional linked list node
    while(head!=NULL){
        cout<<head->data<<" "<<head->next<<endl;
        head->data=5;
        head=head->next;
    }
}
Node* refrence(Node* &head){
    // no doubt here we are pointing the same head because we received the value by reference, so all operation will be performed on the actual data
    if(head==NULL){
        cout<<"it's already NULL";
    }
    while(head!=NULL){
        cout<<head->data<<" "<<head->next<<endl;
        head=head->next;
    }
}
int main() {
    Node* h1=new Node(5);
    Node* h2=new Node(6);
    Node* h3=new Node(7);
    Node* h4=new Node(8);
    Node* head=h1;
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    value(head);
    value(head);
    refrence(head);
    refrence(head);
    

    return 0;
}