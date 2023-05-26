// Just opposite linked list ko kam ma liya hain means is ma linked list ki current value Null ko point karna ka bajay
#include <iostream>
// #include<stack>
using namespace std;
class Node{
  public: 
  int data;
  Node* next;
};
class stack{
    public:
    Node* head;
    int top;
    int size;
    stack(int size){
        this->size=size;
        this->head=NULL;
        top=-1;
    }
    void push(int element){
        if((size-top)>1){
            Node* newNode=new Node;
            newNode->data=element;
            newNode->next=head;
            head=newNode;
            cout<<element<<" : added in the stack "<<endl;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }
    }
    void pop(){
        if(isEmpty()){
           cout<<"stack is already empty"<<endl;
        }
        else{
            
            top--;
            Node* temp=head;
            head=head->next;
            cout<<temp->data<<" : removed from the  stack "<<endl;
            delete temp;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"stack is already empty"<<endl;
            
        }
        else{

            cout<<head->data<<": is top of the stack "<<endl;
        }
    }
    bool isEmpty(){
        if(head!=NULL){
            return false;
            
        }
        else{
            return true;
        }
    }
};
int main() {
    stack st(5);
    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(9);
    st.push(1);
    st.pop();
    st.push(1);
    st.peek();

    return 0;
}