// Add two numbers represented by linked lists
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=1&sortBy=submissions&searchQuery=add%20two

// TC=o(n) we trivase a whole array as a seprate loop 
// SC=o(n) we used one extra space to create a answer array

// basically first we reverse both linked list
// after this add normal likw we add in math
// after this again reverse answer array and return it's head;


/*struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{   private:
        void insertattail(struct Node* &ansh,struct Node* &anst,int remi){
            Node* temp=new Node(remi);
            if(ansh==NULL){
                ansh=temp;
                anst=temp;
                return ;
            }
            else{
                anst->next=temp;
                anst=temp;
                return ;
            }
        }
        struct Node* add(struct Node* first,struct Node* second){
            int carr=0;
            Node* ansh=NULL;
            Node* anst=NULL;
            while(first!=NULL && second!=NULL){
              int sum=first->data+second->data+carr;
              int remi=sum%10;
              carr=sum/10;
            //   add reminder in the linked list
              insertattail(ansh,anst,remi);
              first=first->next;
              second=second->next;
          }
          while(first!=NULL){
              int sum=first->data+carr;
              int remi=sum%10;
              carr=sum/10;
            //   add reminder in the linked list
              insertattail(ansh,anst,remi);
              
              first=first->next;
              
          }
          while(second!=NULL ){
              int sum=second->data+carr;
              int remi=sum%10;
              carr=sum/10;
            //   add reminder in the linked list
              insertattail(ansh,anst,remi);
              
              second=second->next;
              
          }
          if(carr!=0){
              insertattail(ansh,anst,carr);
          }
          return ansh;
        }
        Node* reverse(Node* head){
            Node* curr=head;
            Node* prev=NULL;
            Node* next=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // 1st reverse both linked list
        first=reverse(first);
        second=reverse(second);
        
        // step-2 add both linked list
        Node* ans=add(first,second);
        
        // step3 reverse the answer
        ans=reverse(ans);
        return ans;
    }
};