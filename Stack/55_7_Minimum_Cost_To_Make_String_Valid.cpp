// Minimum Cost To Make String Valid
// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

// basically if string is odd then we can return directly because in odd in the end one bracked will not be able to complete
// but in the even there is three case all is in the single side like {{{{{{{{ or may be }}}}}}}}}}}} 
// or may be a=}}}}}} ,b={{{{{{ a+b , now and a and b both may be even or odd in the both case possible answer will 
// be (a+1)/2+(b+1)/2

#include <bits/stdc++.h> 
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2!=0){
    return -1;
  }
  stack<char> s;
  for(int i=0;i<str.length();i++){
      char ch=str[i];

      if(ch=='{'){
        s.push(ch);
      }
      else{
        if(!s.empty() && s.top()=='{'){
          s.pop();
        }
        else{
          s.push(ch);
        }
      }
  }
  int a=0;
  int b=0;
  while(!s.empty()){
    if (s.top() == '{') {
      b++;
    } else if (s.top() == '}') {
      a++;
    }
    s.pop();
  }
  int ans=(a+1)/2+(b+1)/2;
  return ans;


}

