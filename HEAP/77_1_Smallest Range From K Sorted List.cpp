// Smallest Range From K Sorted List
// https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356


// Smallest range in K lists
// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1


//approach: sab sa phale ek min and ek max heap bana lo jis ma starting ka k element dal do
//Ab apana pass min and max heap sa ek range aa jayegi
//now to reduce or get minimum range we have to reduce size, we cann't reduce max value because array sorted order ma hain increasing ma 
//Now hum minimum element wala ko pop karenga and just uska next element dal denga now minimum and maximum dakhenga agar range ka diff kam 
//ho gaya hain tho update kar denga else chaltha javo, jab thak ki sub end na ho jaya
//TC=o(n*m*log(k)), SC=o(k)
//Almost same but max ka liya koi alag sa heap nahi liya hain
#include<queue>
#include<bits/stdc++.h>
class node{
    public:
        int data;
        int row;
        int column;
        node(int data, int row, int column){
            this->data=data;
            this->row=row;
            this->column=column;
        }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<node*,vector<node*>,compare>miniheap;// hamna min heap is liya liya hain taki track rakh saka ki current minimum ka bad next element konsa 
    //hain and it also track that in every row where that we processed
    int maxi=INT_MIN;
    int mini=INT_MAX;
    //step: 1 push first k element in the min queue and find the range
    for(int i=0;i<k;i++){
        miniheap.push(new node(a[i][0],i,0));
        maxi=max(a[i][0],maxi);
    }
    mini=miniheap.top()->data;//we also can do in the loop like max
    int start=mini,end=maxi;//start and end is used to track answer

    while(!miniheap.empty()){//we will do till it's not become empty
        mini=miniheap.top()->data;
        node* temp=miniheap.top();
        miniheap.pop();

        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        if(temp->column+1<n){//we want that next column < n
            maxi=max(maxi,a[temp->row][temp->column+1]);
            miniheap.push(new node(a[temp->row][temp->column+1],temp->row,temp->column+1));
        }
        else{
            break;//if any list end come we will break because after this may be range decrease but doesn't have data related to the this
        }

    }
    return end-start+1;
    
}


//approach:sara ka sara element ka liya check kar lo, TC=o(n*k*n*k)