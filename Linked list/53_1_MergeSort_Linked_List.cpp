// MergeSort Linked List
// https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514?leftPanelTab=1

//approach is very similar to the merge sort of an array , break , sort and merge 





/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* merge(node* left,node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    node* ans=new node(-1);
    node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data>right->data){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        else{
            temp->next=left;
            temp=left;
            left=left->next;
        }
    }
    if(left!=NULL){
        temp->next=left;
    }
    if(right!=NULL){
        temp->next=right;
    }
    return ans->next;
}
node* mergeSort(node *head) {
    //base case 
    if(head==NULL || head->next==NULL){
        return head;
    }

    //find mid and break in the two part

    node* mid=findmid(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

    //sort both left and right part

    left=mergeSort(left);
    right=mergeSort(right);

    //Now again merge

    node* result=merge(left,right);
    return result;
}
