// Sort linked list of 0s 1s 2s
// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937

//*********************************** 1st solution => if data replacement is not allowed **********************************************
// TC=o(n),SC=o(1)
// create three linked list of 0,1,2 and now merge all 3 linked list first 0's after this 1st and after this merge 2nd linked list 
/********************************
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

********************************/
Node* insertAtTail(Node* &tail,Node* &current){
    tail->next=current;
    tail=current;
}
Node* sortList(Node *head)
{
    // 6 node to track start and end of all three list
    Node* zero = new Node(-1);
    Node*  zerotail = zero;
    Node* one = new Node(-1);
    Node*  onetail = one;
    Node* two = new Node(-1);
    Node*  twotail = two;
    Node* current=head;
    while(current!=NULL){
        if (current->data==0) {
            insertAtTail(zerotail, current);
            }
        else if (current->data==1) {
            insertAtTail(onetail, current);
            }
        else if (current->data==2) {
            insertAtTail(twotail, current);
            }
        current=current->next;
    }
    // 1st list is not empty
    if(one->next!=NULL){
        zerotail->next=one->next;
        if(two->next!=NULL){
            onetail->next=two->next;
            twotail->next=NULL;
        }
        else{
            onetail->next=NULL;
        }
    }
    else{
    // 1st list is empty
        if(two->next!=NULL){
            zerotail->next=two->next;
            twotail->next=NULL;
        }
        
    }
    return zero->next;

   

}




//****************************************** 2nd solution =>if data replacement is allowed**********************************************
// TC=o(n),SC=o(1)
// in this solution we are counting the toatl number of 0,1,2 after we replacing data with 0,1,2. This will be applicable if they are allowing data replacement

/********************************
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

********************************/

Node* sortList(Node *head)
{
    int zero = 0, one = 0, two;
    Node* current=head;
    while(current!=NULL){
        if (current->data==0) {zero++;}
        else if (current->data==1) {one++;}
        else if (current->data==2) {two++;}
        current=current->next;
    }
    current=head;
    while(current!=NULL){
        if(zero!=0){
            current->data=0;
            zero--;
        }
        else if(one!=0){
            current->data=1;
            one--;
        }
        else if(two!=0){
            current->data=2;
            two--;
        }
        current=current->next;
    }
    return head;


}
