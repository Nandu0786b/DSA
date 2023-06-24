// House Robber

// https://www.codingninjas.com/studio/problems/loot-houses_630510?leftPanelTab=0

//approach: same as previous where we are doing maximum sum and we can not take two houe continue

//**************************** USING TABLUAR ****************************************************

//TC=O(N)
//SC=O(1)

int loot(vector<int>&houses,int n){
	int dp1=houses[0];
	int dp2=0;
	int dpp=0;
	for(int i=1;i<n;i++){
		dpp=dp1;
		dp1=max(houses[i]+dp2,dp1);
		dp2=dpp;
	}
	return dp1;
}
int maxMoneyLooted(vector<int> &houses, int n)
{
	if(n==0){
		return 0;
	}
	return loot(houses,n);
}