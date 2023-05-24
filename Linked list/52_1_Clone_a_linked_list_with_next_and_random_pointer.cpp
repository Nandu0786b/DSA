// Clone a linked list with next and random pointer
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

//basically question ma ek linked list di hain jis ma ek node ma do address hain. un ma sa ek address tho normal ki tarah kam kar raha hain but 
// /second wala random node ko point kar raha hain , now we have to create a new linke list which will be same as this.

// approach 3 : instead of using below two approach , here we will try to t=reduce space complexity , here instead of storing in the map we will try to store data in the node 
// basically is ma ham origional ka 1st ko clone ka 1st sa point karenga and clone ka 1st origional ka second ko point karega so we not required and mapping
// origional : 1 2 3 4 5 6 7 
//             |/|/|/|/|/|/|
//             V V V V V V V
// clone     : 1 2 3 4 5 6 7

class Solution
{   private:
    void insertAtTail(Node* &head, Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            return ;
        }
    }

    public:
    Node* copyList(Node *head)
    {
        //Write your code here
        
        // step : 1 create a cloned list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* orig=head;
        while(orig!=NULL){
            insertAtTail(cloneHead,cloneTail,orig->data);
            orig=orig->next;
        }
        
        // step 2 : Now do the mapping
        orig=head;
        Node* clone=cloneHead;
        Node* nex=NULL;
        while(clone!=NULL){
            // 1st linked list operation
            nex=orig->next;
            orig->next=clone;
            orig=nex;
            // 2nd linked list operation
            nex=clone->next;
            clone->next=orig;
            clone=nex;
            
        }
        
        
        //  step :3 copy random node in the clone linked list
        Node* temp=head;
        while(temp!=NULL){
            temp->arb!=NULL? temp->next->arb=temp->arb->next:temp->next->arb=temp->arb;
            temp=temp->next->next;
        }
        // step : 4 again create both origional linked list *****========>>>>>>     BY ME       *****========>>>>>>
            // orig=head;
        // clone=cloneHead;
        // while(clone!=NULL && orig!=NULL ){
        //     orig->next=clone->next;
        //     orig=orig->next;
            
        //     if(clone->next!=NULL){
        //         clone->next=orig->next;
                
        //     }
        //     clone=clone->next;
            
            
        // }
        // step : 4 By the love 
        Node* original = head;
        Node* copy = cloneHead;
        
         while ( copy)
            {
                original->next =original->next->next ;
                original = original->next;
                
                copy->next = copy->next?copy->next->next: NULL;
                
                copy = copy->next;
                
            }
        return cloneHead;
    }

};











//**********************************************************
//approach 2 : simply first we will build a linked list. now we will do mapping of origioanl to copied(cloned) list
// origional : 1 2 3 4 5 6 7 
//             | | | | | | |
//             V V V V V V V
// clone     : 1 2 3 4 5 6 7

// after this our remaining task is to set random pointer. for this we use use this mapping list 
// clone->random=mapping[origional->random]
// for an example 1->random==3 then mapping[origional->random] will be mapped to the 3 of clone list 
//  so our expression will be clone->random=mapping[origional->random]

// TC=o(n),SC=o(n)
class Solution
{   private:
    void insertAtTail(Node* &head, Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            return ;
        }
    }
    public:
    Node* copyList(Node *head)
    {
        //Write your code here
        
        // step : 1 create a cloned list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* orig=head;
        while(orig!=NULL){
            insertAtTail(cloneHead,cloneTail,orig->data);
            orig=orig->next;
        }
        
        // step 2 : Now do the mapping
        
        unordered_map<Node*,Node*> oTn;
        Node* origg=head;
        Node* clone=cloneHead;
        while(origg!=NULL ){
            oTn[origg]=clone;
            origg=origg->next;
            clone=clone->next;
        }
        
        //  step :3 arrange the random node
        
        origg=head;
        clone=cloneHead;
        while(origg!=NULL ){
            clone->arb=oTn[origg->arb];
            clone=clone->next;
            origg=origg->next;
        }
        return cloneHead;
    }

};





//***********************************************************************************
//approach 1 : simply first create a linked list now run two nested for loop, and do the mapping. in this TC=o(n^2),sc=o(n) because we are building a new linked list 