// Merge K Sorted Arrays

// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379


//approach: mean heap bana ka usma har array ka first element ko push kar do 
//Now heap ma sa front element nikal lo and jis array ka tha usma agar or element hain tho uska aga wala element push kar do

#include <bits/stdc++.h> 
class node{
    public:
        int data;
        int i;  //row
        int j;  //column
        node(int data,int row,int column){
            this->data=data;
            this->i=row;
            this->j=column;
        }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{   
    priority_queue<node*,vector<node*>,compare>mini;//agar custom data types banya hain tho compare class likhani hogi, 
    //we can not use greater
    //sc for heap sc=o(k),because ek time pa apan maximum k element hi dal raha hain
    //step:1 first element of the all array
    for(int i=0;i<k;i++){//TC=o(k*log(k))
        node* temp=new node(arr[i][0],i,0);
        mini.push(temp);
    }
    vector<int>ans;//sc=o(n*k)
    while(mini.size()>0){//Tc=o(n*k *log(k))
        node *temp=mini.top();
        ans.push_back(temp->data);
        mini.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<arr[i].size()){//means who ith array ka number of column sa kam hain
            node* next=new node(arr[i][j+1],i,j+1);
            mini.push(next);
        }
    }
    return ans;
}



//approach: sara ka sara element nikal lo and ek answer array ma store kar lo, TC=o(n*k)
//now sort arrays in the and return, TC=o(n*k log(n*k))