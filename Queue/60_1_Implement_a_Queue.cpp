// Implement a Queue
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int dfront;
    int rear;
    int size=1000001;
public:
    Queue() {
        // Implement the Constructor
        arr=new int[size];
        dfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(dfront==rear){
            return true;
        }
        return false;

    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            return ;
        }
        arr[rear]=data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(dfront==rear){
            return -1;
        }
        int ans=arr[dfront];
        arr[dfront]=-1;
        dfront++;
        // if(dfront==rear){ //This is not the part of queue, this is the part of the deque
        //     dfront=0;
        //     rear=0;
        // }
        return ans;
    }

    int front() {
        // Implement the dfront() function
        if(dfront==rear){
            return -1;
        }
        return arr[dfront];

    }
};