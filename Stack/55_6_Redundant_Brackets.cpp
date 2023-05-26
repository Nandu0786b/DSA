// Redundant Brackets
// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0

// very simple approach here we have to done one thing that continoue add in stack (operator and brackets), now if any closing bracket come then 
// pop elememt from the stack and if you find operator between the open and close bracket then it's ok and proceesed for the next step 
// but if you find no operator then return true that it is a redundant .

// TC=o(n),SC=o(n)


#include <bits/stdc++.h> 
#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('|| ch=='/' || ch=='+' || ch=='-' || ch=='*' ){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='/' || top=='+' || top=='-' || top=='*' ){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true){
                return true;
                
            }
            st.pop();
            }
            
            
        }
    }
    return false;
}
