// Detect and Remove Loop
// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0


// TC=o(n),sc=o(1) , we also can do one with another method like store in the map but map will store the data so SC will be o(1)
/*************************************************
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
*************************************************/
// 1st method 99.99% fast
/*************************************************
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
*************************************************/
Node* detcetloop(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if (slow==fast){
                return fast;
            };
        }
        
    }
    return NULL;
}
Node *removeLoop(Node *head)
{
    if(head==NULL){
        return head;
    }
    Node* intersection=detcetloop(head);
    if (intersection) {
    Node* slow=head;
    while(intersection!=slow){
        intersection=intersection->next;
        slow=slow->next;
    }
    Node* loops=slow;
    while(loops->next != slow){
      loops = loops->next;
    }
    loops->next = NULL;

    }
    return head;
    

}
/*************************************************/
// 2nd method only 17 % fast
Node* detcetloop(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if (slow==fast){
            return fast;
        };
    }
    return NULL;
}
Node *removeLoop(Node *head)
{
    if(head==NULL){
        return head;
    }
    Node* intersection=detcetloop(head);
    if (intersection==NULL) return head;
    Node* slow=head;
    while(intersection!=slow){
        intersection=intersection->next;
        slow=slow->next;
    }
    Node* loops=slow;
    while(true){
        if(loops->next==slow){
            loops->next=NULL;
            return head;
        }
        loops=loops->next;
    }
    return head;
    

}