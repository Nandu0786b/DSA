// Valid Parentheses
// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=0

// string sa brackets nikalo and stack ma add kartha javo and jab bhi close bracket aya tho dakho uska phale wala same open bracket hain ya nahi
// agar open hain tho valid parentheses hain other wise return fasle. if pury string end ho gayi hain tho end ma check karo ki stack empty hain ya nahi
// agar nahi hain means sara breacket ka pair present nahi tha so return false else return true 

// TC=o(n),SC=o(n)


bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>s;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        if(ch=='(' || ch=='{'|| ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                  s.pop();
                } else{
                    return false;}
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}