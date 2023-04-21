// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087
// Subsequences of String
// solution will be 2^n because 
#include <bits/stdc++.h> 
void solve(string str,string output,int i, vector<string>& ans){
	if (i>=str.length()){
		if(output.length()>0){
		ans.push_back(output);
		
		}
		return ;
	}
	solve(str,output,i+1,ans);
	output.push_back(str[i]);
	solve(str,output,i+1,ans);
}
vector<string> subsequences(string str){
	
	// Write your code here
	string output="";
	vector<string> ans;
	solve(str,output,0,ans);
	return ans;
	
}