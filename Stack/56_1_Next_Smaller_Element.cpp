// Next Smaller Element
// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=0
// Medium

// approach : 1 By love , basically in this we in the start we add -1 element in the stack now we will start  array from the end element 
//  if we found any big number in the stack then we will remove big number because in the remmaining term when we come from the left then current element 
// will be our answer because this is smallest till now. but if we find small element then small element will be push in the array and that element will be pushed in the stack



#include<stack>
// void 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{   stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        arr[i]=s.top();
        s.push(curr);
    }
    return arr;
}





















// approach:2 TC=o(n^2) TLE for this questions
// basically first vector ka sara element stack ma dal diya reverse order ma fir stack ka top ka element nikala  and baki remaining sa check kiya agar 
// koi bhi chota element mila tho array ma who element store kar lya nahi tho -1 store kar liya recursion sa
#include<stack>
int playmain(stack<int> &s,int e)
{
    if(s.empty()){
        return -1;
    }
    else if (s.top()<e){
        return s.top();
    }
    int pop=s.top();
    s.pop();
    int value=playmain(s,e);
    s.push(pop);
    return value;
}
void recsmall(vector<int> &arr,stack<int> &s){
     while(!s.empty()){
         int e=s.top();
         s.pop();
         arr.push_back(playmain(s,e));
     }
     return;
}
vector<int> nextSmallerElement(vector<int> &arr, int n)
{  
    stack<int>s;
    int i=arr.size()-1;
    for(i;i>=0;i--){
        s.push(arr[i]);
        arr.pop_back();
    }
    recsmall(arr,s);
    return arr;
}