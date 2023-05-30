// First non-repeating character in a stream
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// basically hamna unique number ko ek queue ma store kiya hain and unka count ko map ma store kiya hain and jaisa hi 
// koi number (front of queue) ununique ho jatha hain tho hum usko queue sa nikal danga 
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char,int>m;
		    queue<char>q;
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        m[A[i]]+=1;
		        q.push(A[i]);

		        while(!q.empty() && m[q.front()]>1){
		            q.pop();
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        else{
		            ans.push_back(q.front());
		        }
		    }
		    return ans;
		    
		}

};