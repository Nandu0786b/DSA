// here TC=o(1) because we are doing all task in single step



#include <iostream>
// #include<stack>
using namespace std;
class stack{
    public:
    int *arr;
    int top;
    int size;
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if((size-top)>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack is already empty"<<endl;
        }
    }
    void peek(){
        if(top>-1){
            cout<<arr[top]<<endl;
        }
        else{
            cout<<"stack is already empty"<<endl;
        }
    }
    bool isEmpty(){
        if(top>=0){
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