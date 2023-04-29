#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* previous;
    Node* Next;
    //constructor
    Node(int d){
        this->data=d;
        this->previous=NULL;
        this->Next=NULL;
    }
};
void print(Node* head){
    Node* temp=head;
    cout<<" is"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->Next;
    }
    cout<<endl;
}
int getlength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->Next;
        len++;
    }
    
    cout<<"array length is  "<<len<<endl;
}
void InsertAthead(Node* &head,int data){
        Node* temp = new Node(data);
        temp->Next=head;
        head->previous=temp;
        head=temp;
}
void InsertAttail(Node* &tails,int data){
        Node* temp = new Node(data);
        temp->previous=tails;
        tails->Next=temp;
        tails=temp;
}
void insertposition(Node* &head,Node* &tails,int position,int data){
    if (position==0 && head->previous==NULL){
        InsertAthead(head, data);
        return;
    }
    Node *temp=head;
    Node *previousa=NULL;
    Node *Nexta=NULL;
    int cnt=1;
    while(cnt<position){
        temp=temp->Next;
        cnt++;
    }
    if(temp->Next==NULL){
        InsertAttail(tails,data);
        return;
    }
    Node * elementi=new Node(data);
    elementi->Next=temp->Next;
    elementi->previous=temp;
    temp->Next=elementi;
    temp=elementi->Next;
    temp->previous=elementi;
}
int main(){
    Node* Node1=new Node(100);
    Node* head=Node1;
    Node* tails=Node1;
    cout<<tails->data<<" "<<head->data<<endl;
    print(head);
    getlength(head);
    InsertAthead(head,6);
    InsertAttail(tails,101);
    cout<<tails->data<<" "<<head->data<<endl;
    print(head);
    insertposition(head,tails,0,5);
    insertposition(head,tails,4,102);
    insertposition(head,tails,5,103);
    insertposition(head,tails,6,104);
    print(head);
    cout<<tails->data<<" "<<head->data<<endl;
    return 0;
}