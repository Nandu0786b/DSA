// The Celebrity Problem
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// approach : baically sara element ko stack ma dal do element means if there is given n element then start loop and push from 0 to n-1 in stack
// Now in Run a loop till only one lement remain in the loop and every time remove two element from the loop a and b and check if a knows b if not then it 
// means a is not celebrity so remove a and again push b otherwise push a 
//  once we complete this loop then there will be one last element in the stack which is possibly solution so in that case just 
//  we will iterate for that element complete row and column , in the column one diagonal element will be 0 but other will be one and in row all will be zero
// if found some thing wrong just return -1


class Solution 

{   private:
    bool knows(int a,int b,vector<vector<int> >& M){
        if(M[a][b]==1){
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        // push all element in the stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        // Now cross check by tecking every time to celebrity
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(a,b,M)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int element=s.top();
        for (int i=0;i<n;i++){
            if(M[element][i]!=0){
                return -1;
            }
        }
        for (int i=0;i<n;i++){
            if( M[i][element]!=1){
                if(element!=i){
                return -1;}
            }
        }
        return element;
    }
};