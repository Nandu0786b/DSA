// Add First and Second Reversed Half
// https://www.codingninjas.com/codestudio/problems/add-first-and-second-reversed-half_759344

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
Node* add(Node* h1,Node* h2){
    int ca=0;
    int sum=0;
    int rem=0;
    Node* h3=NULL;
    Node* tail=NULL;
    while(h1 || h2 || ca){
        if(h1){
            sum+=h1->data;
            h1=h1->next;
        }
        if(h2){
            sum+=h2->data;
            h2=h2->next;
        }
        if(ca){
            sum+=ca;
        }
        int rem=sum%10;
        if(!h3){
            h3=new Node(rem);
            tail=h3;
        }
        else{
            tail->next=new Node(rem);
            tail=tail->next;
        }
        ca=sum/10;
        sum=0;
    }
    return h3;
}
Node* addFirstAndReversedSecondHalf(Node* head)
{
    //  Write your code here.
    if(!head){
        return head;
    }
    Node* temp=head;
    int n=0;
    while(temp!=NULL){
        temp=temp->next;
        n++;
    }
    Node* h1=head;
    int N= n%2==0 ? n/2:n/2+1;
    temp=head;
    for(int i=0;i<N;i++){
        temp=temp->next;
    }
    Node* h2=temp;
    Node* pr=NULL;
    Node* ne=NULL;
    //Remove extra zero from first part
    while(h1->next!=h2 && h1->data==0){
        h1=h1->next;
    }
    temp=h1;
    while(temp && temp!=h2){
        ne=temp->next;
        temp->next=pr;
        pr=temp;
        temp=ne;
    }
    h1=pr;
    pr=NULL;
    
    //Now add both half part in reverse manner
    Node* h3=add(h1,h2);

    pr=NULL;
    ne=NULL;
    temp=h3;
    while(temp){
        ne=temp->next;
        temp->next=pr;
        pr=temp;
        temp=ne;
    }
    
    
    
    h3=pr;
    //remove extra zero from sum
    while(h3 && h3->data==0){
        h3=h3->next;
    }
    if(!h3){
        return new Node(0);
    }
    return h3;
}
