// Non Repeating Character
// https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       map<char,int>m;
       for(int i=0;i<s.length();i++){
           m[s[i]]+=1;
       }
       for(int i=0;i<s.length();i++){
           if(m.find(s[i])!= m.end() && m[s[i]]==1 ){
                return s[i];
           }
          
       }
       return '$';
       
       
    }

};