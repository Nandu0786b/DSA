// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<unordered_map>
#include<map>
int main() {
    // creation
    unordered_map<string,int>m;
    
    //insertion
    //1st
    pair<string,int>p=make_pair("Nandu",5);
    m.insert(p);
    //2nd
    pair<string,int>p2("chandu",5);
    m.insert(p2);
    //3rd
    m["ha ji"]=5;
    
    m["ha ji"]=6;//Now it replace 5  by 6, first time ma creation hua tha but 
    //2nd time dalna pa updation hua tha
    
    //Search
    cout<<m["ha ji"]<<endl;
    cout<<m.at("ha ji")<<endl;
    
    // case :1
    //when key is not in the map in that case it will return error
    // cout<<m.at("Na ji ji")<<endl;
    
    //when key is not in the map in that case it will return zero
    cout<<m["Na ji ji"]<<endl;
    
    // case :2
    //when key is not in the map in that case it will return zero
    cout<<m["Na ji ji"]<<endl;//and ya waha pa es key create kar ka usko zero assign kar dega
    
    //when key is not in the map in that case it will return zero because uper wali command na waha pa zero create kar diya hain
    cout<<m.at("Na ji ji")<<endl;
    
    
    //size
    cout<<m.size()<<endl;
    
    //to check presence
    cout<<m.count("bro")<<endl;
    
    //deletion
    m.erase("ha ji");
    cout<<m.size()<<endl;
    

    return 0;

}