#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* Next;
    Node(int data){
        this->data=data;
        this->Next=NULL;
    }
};
void insertAtHead(Node* &head,int d){//here we are taking a reference value so changes will be done in the origional linked list
    // cretae a new node
    Node* temp = new Node(d);
     
    // map the address
    temp->Next=head;
    head=temp;//ya is linked list ka head ka address change kar raha hain agar hum last ma add kartha tho ya nahi karna padtha
}
void inserAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail -> Next = temp;
    tail  = temp;
    
    // this the insert at the mid point
}
void inserAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position==0){
        insertAtHead(head,d);
        return;
    };
    Node *temp=head;
    int cnt=1;
    while(cnt<position){
        temp=temp->Next;
        cnt++;
        
    }
    if(temp->Next==NULL){
        inserAtTail(tail,d);
        return;
    }
    Node * Nodetoinsert= new Node(d);
    Nodetoinsert->Next=temp->Next;
    temp->Next=Nodetoinsert;
    
    // this the insert at the mid point
}
// void deleteNode(int position, Node* & head) { by love b

//     //deleting first or start node
//     if(position == 1) {
//         Node* temp = head;
//         head = head -> next;
//         //memory free start ndoe
//         temp -> next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //deleting any middle node or last node
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         prev -> next = curr -> next;
//         curr -> next  = NULL;
//         delete curr;

//     }
// }
void deletePosition(Node* &tail,Node* &head,int position){// by me
    if(position==1){
        Node *previous=head;
        head=head->Next;
        delete previous;
        return;
    }
    Node * temp=head;
    Node *previous=temp;
    int cnt=1;
    while(cnt<position){
        previous=temp;
        temp=temp->Next;
        cnt++;
    }
    cout<<"ok"<<previous->data<<temp->data<<endl;
    previous->Next=temp->Next;
    delete temp;
}
void print(Node* &head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->Next;
    };
    cout<<endl<<endl;
}
int main(){
    Node* Node1=new Node(10);
    // cout<<Node1->data<<" data"<<endl;
    // cout<<Node1->Next<<" Next"<<endl;
    Node *head=Node1;
    Node *tail=Node1;
    cout<<head<<" "<<Node1<<endl;// ya dono ek hi cheez ko address kar raha hain 
    cout<<tail->data<<" "<<head->data<<endl;
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,5);
    print(head);
    inserAtPosition(tail,head,1,6);
    inserAtPosition(tail,head,6,11);
    inserAtPosition(tail,head,7,12);
    cout<<tail->data<<" "<<head->data<<endl;
    print(head);
    deletePosition(tail,head,1);
    print(head);
    return 0;
    
}