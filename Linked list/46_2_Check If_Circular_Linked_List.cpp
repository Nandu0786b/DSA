// Check If Circular Linked List
// https://practice.geeksforgeeks.org/problems/circular-linked-list/1

//TC=o(n),SC=o(1)
//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){

        cin>>n>>k;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
        if (k==1 && n >= 1)
              tail->next = head;


    printf("%d\n", isCircular(head));
    }
    return 0;
}

//2nd method => create a map Node* type where key is address and value is 1 like visited , so when you trivase complete map then in the end if address is null return false and if address is already in map return true
//2nd :- TC=o(n),SC=o(n)
// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    if(head==NULL){
        return false;
    }
   Node* temp=head;
   while(true){
       temp=temp->next;
       if(temp==NULL){
           return false;
       }
       else if(temp==head){
           return 1;
       }
   }
}






























// BasicAccuracy: 54.26%Submissions: 119K+Points: 1
// Upskill with this problem, Get placed in Job Fair 2023! Explore Opportunities Now! 

// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

// Note: The linked list does not contains any inner loop.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// (the first and last node is connected,
// i.e. 5 --> 1)
// Output: 1
// Example 2:

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 0
// Your Task:
// The task is to complete the function isCircular() which checks if the given linked list is circular or not. It should return true or false accordingly. (the driver code prints 1 if the returned values is true, otherwise 0)

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <=Number of nodes<= 100

// View Bookmarked Problems 
// Company Tags
// MicrosoftMAQ SoftwareSAP Labs