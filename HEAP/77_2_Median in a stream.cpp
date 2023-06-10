// Median in a stream //good question
// https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268?leftPanelTab=1
//H.W:- https://leetcode.com/problems/reorganize-string/

//********************************** BY LOVE ********************************************
//approach:Basically we min and max two heap banaya hain
//Main thing is that where we have to enter this 
//like half left part will be max heap and right part is the min heap
//Now when we insert new data from the stream then two case insert in left or right
//if left and right both size are equal then we will push our data in that part element>median then push in min else push in the max and answer will be the top of heap where we are push and also update median
//Now if left>right then two case 
//and if left<right then two case
//agar dono equal hain tho jis taraf bhi push karenga ushi taraf ka top current median hoga 
//but size kam jayda hain tho less wala ki taraf insert hona pa koi problem nahi hain but max size wala ki taraf insert hona pa phale element shift karna hain and uska bad usko push karna hain

#include<bits/stdc++.h>
int signum(int a,int b){
	if(a==b)
		return 0;
	else if(a>b)
		return 1;
	else
		return -1;
}
void callMedian(int element,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &median){
	switch(signum(maxi.size(),mini.size())){
			case 0:if(element>median){
						mini.push(element);
						median=mini.top();
					}
					else{
						maxi.push(element);
						median=maxi.top();
					}
					break;
			case 1:if(element>median){//when we push element in the right then both size will become equal
						mini.push(element);
						median=(mini.top()+maxi.top())/2;
					}
					else{//alreay left is greater then right so first we will shift one element from left to right after this we will push data in the heap
						mini.push(maxi.top());
						maxi.pop();
						maxi.push(element);
						median=(mini.top()+maxi.top())/2;
					}
					break;
			case -1:if(element>median){//alreay right is greater then left so first we will shift one element from right to left after this we will push data in the heap
						maxi.push(mini.top());
						mini.pop();
						mini.push(element);
						median=(mini.top()+maxi.top())/2;
					}
					else{//when we push element in the left then both size will become equal
						maxi.push(element);
						median=(mini.top()+maxi.top())/2;
					}
					break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int,vector<int>,greater<int>>mini;
	priority_queue<int>maxi;
	int median=-1;
	for(int i=0;i<n;i++){
		callMedian(arr[i],maxi,mini,median);
		ans.push_back(median);
	}
	return ans;
}





// *********************************************
// TC=O(n * m log m)=o(n^2*log(n))
#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;//SC=O(n)
	vector<int> temp;//SC=O(n)
	for(int i=0;i<n;i++){//TC=(TC OF THE WHILE LOOP)*(TC OF THE SORTING)=o(n)*o(m*log(m))=o(n^2*log(n))
		temp.push_back(arr[i]);
		sort(temp.begin(),temp.end());//TC=o(m*log(m))
		if((i+1)%2==0){
			
			ans.push_back((temp[i/2]+temp[i/2+1])/2);
		}
		else{
			ans.push_back(temp[i/2]);
		}
	}
	return ans;
}