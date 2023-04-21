// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// like pnc every place may have maximum 3 number so answer will be 3^n , here n is a length of a string
class Solution {
private:
    void combination(string digits,string output,int i,vector<string>& ans,string mapping[]){
        if(i>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[i]-'0';
        string value = mapping[number];
        for(int mi=0;mi<value.length();mi++){
            output.push_back(value[mi]);
            combination(digits,output,i+1,ans,mapping);
            output.pop_back();
            // first add and after remove this is called back tracking
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length()==0)
            return ans;  
        string output="";
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combination(digits,output,0,ans,mapping);
        return ans;
    }
};