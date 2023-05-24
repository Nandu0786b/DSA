// Flatten A Linked List
// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655?leftPanelTab=0

// majorly question solved with the help of merge sort, main time gone to write merge sort algorithm

Node* findmid(Node* head){
    Node* slow=head;
    Node* fast=head->child;
    while(fast!=NULL && fast->child!=NULL){
        fast=fast->child->child;
        slow=slow->child;
    }
    return slow;
}
Node* merge(Node* left,Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node* ans=new Node(-1);
    Node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data>right->data){
            temp->child=right;
            temp=right;
            right=right->child;
        }
        else{
            temp->child=left;
            temp=left;
            left=left->child;
        }
    }
    if(left!=NULL){
        temp->child=left;
    }
    if(right!=NULL){
        temp->child=right;
    }
    return ans->child;
}
Node* mergeSort(Node *head) {
    //base case 
    if(head==NULL || head->child==NULL){
        return head;
    }

    //find mid and break in the two part

    Node* mid=findmid(head);
    Node* left=head;
    Node* right=mid->child;
    mid->child=NULL;

    //sort both left and right part

    left=mergeSort(left);
    right=mergeSort(right);

    //Now again merge

    Node* result=merge(left,right);
    return result;
}
void convert(Node* head) {
    if (head->next == NULL) {
        return;
    }
    Node* down = head;
    while (down->child != NULL) {
        down = down->child;
    }
    down->child = head->next;
    head->next = NULL;
    convert(down->child);
}

Node* flattenLinkedList(Node* head) {
    convert(head);
	head=mergeSort(head);
    return head;
}
