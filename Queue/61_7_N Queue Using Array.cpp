// N Queue Using Array
// https://www.codingninjas.com/codestudio/problems/n-queue-using-array_1170053?leftPanelTab=0
// easy
// normal jasa stack ma kiya tha vasa hi kiya hain, 
// add kartha time previous element ko current sa map kara datha hain thaki pop kartha time patha chal paya ki next element konsa hain 
// and next array ma rear ka index pa value -1 hothi hain so pop ka time ya patha chal saka ki rukana kaha pa hain

#include <bits/stdc++.h> 
class NQueue{
    int* arr;
    int s;
    int n;
    int* next;
    int* front;
    int* rear;
    int freespot;

public:
    // Initialize your data structure.
    NQueue(int n, int s){//s=size,n=number of array
        // Write your code here.
        this->s=s;
        this->n=n;
        arr=new int[s];
        next=new int[s];
        front=new int[n];
        rear=new int[n];
        freespot=0;
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        for(int i=0;i<n;i++){
            front[i]=-1;
            rear[i]=-1;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here
        // check overflow condition.
        if(freespot==-1){
            return false;
        }
        // find free index
        int index=freespot;
        // update next frre index in freespot
        freespot=next[index];
        // check wether it is a free element
        if(front[m-1]==-1){
            front[m-1]=index;
        }
        else{
            // link previous element to the new element which will be helpful when we start pop operation
            next[rear[m-1]]=index;

        }
        // update next with -1 so when we start pop in any queue then it will have idea that where we have to stop
        next[index]=-1;
        // update rear that where is the rear
        rear[m-1]=index;
        // push element
        arr[index]=x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if(front[m-1]==-1){
            return -1;
        }
        // find front of the queue
        int index=front[m-1];
        // cout<<"poping value"<<arr[index]<<endl;
        // front ko aga bada do
        front[m-1]=next[index];

        // free slot ko update kar do
        next[index]=freespot;
        freespot=index;

        // return poped element
        int poped=arr[index];
        // arr[index]=-1;
        return poped;

    }
};