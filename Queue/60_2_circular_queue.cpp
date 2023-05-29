// Circular Queue
// https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0

#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int front;
    int size;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        this->size=n;
        arr=new int[n];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front==0 && rear==size-1)||(rear+1==front)){ //overflow condition
            return false;
        }
        if(front==-1 ){//empty list
            front=0;
            rear=0;
            arr[rear]=value;
            return 1;
        }
        if(front!=0 && rear==size-1){//when rear is at end

            rear=0;
            arr[rear]=value;
            return 1;

        }
        rear++;
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){

        // Write your code here.
        if(front==-1){//To check circular queue is empty
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){ //single lement present in the queue
            front=rear=-1;
        }
        else if(front==size-1){//front is on the last element
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};