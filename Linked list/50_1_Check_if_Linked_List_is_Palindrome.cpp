// Check if Linked List is Palindrome
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// in this approach we are doing first get the nid of linked list now reverse the linked list from the half part , now trivarse the linked list
// and if you found any unmatched then return 0 else again reverse the linked list and now return the true  by the way last step is not required where we again reverse the list
// TC=o(n),SC=o(1)

#include <vector>
class Solution{
  private:
    Node* getmid(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }  
    Node* reverse(Node* &head){
        Node* curr=head;
        Node* prev=NULL;
        Node* nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL){
            return 1; 
        }
        
        // step1 get the mid  
        
        Node * mid=getmid(head);
        
        // step 2 reverse the linked list from the middle
        
        Node *temp=mid->next;
        mid->next=reverse(temp);
        
        // step 3 compare both halfs
        
        Node* h1=head;
        Node* h2=mid->next;
        while(h2!=NULL){
            if(h1->data!=h2->data){
                return 0;
            }
            h1=h1->next;
            h2=h2->next;
        }
        //  step 4 again reverse the list to get origional linked list
        temp=mid->next;
        mid->next=reverse(temp);
        
        // return true 
        
        return true;
    }
};











//*******************************************************************************************

// add all liked list data in an array and now use two pointer approach 
// TC=o(n),SC=o(n)

// struct Node {
//   int data;
//   struct Node *next;
//   Node(int x) {
//     data = x;
//     next = NULL;
//   }
// };
#include <vector>
class Solution{
    private:


        bool arraycheck(vector<int> arr){
            int n=arr.size();
            int i=0;
            int j=n-1;
            while(i<=j){
                if (arr[i]!=arr[j]){
                    return 0;
                }
                i++;
                j--;
            }
            return 1;
        }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> arr;
        Node *temp=head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return arraycheck(arr);
    }
};

