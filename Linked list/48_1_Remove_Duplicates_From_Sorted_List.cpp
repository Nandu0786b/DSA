// Remove_Duplicates_From_Sorted_List
// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=1

// TC=o(n),SC=o(1)
/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    if (head==NULL){
        return NULL;
    }
    Node* current =head;
    while(current!=NULL){
        if((current->next!=NULL) && (current->data==current->next->data)){
            Node* duplicate=current->next;
            current->next=current->next->next;
            delete(duplicate);
        }
        else{
            current=current->next;
        }
    }
    return head;
}