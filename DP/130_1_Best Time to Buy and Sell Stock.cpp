// Best Time to Buy and Sell Stock

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//Approach:- apana profit tabhi update hoga jab apana new high profit karenga




//**************************************************************************




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int dif=prices[i]-mini;
            profit=max(profit, dif);
            mini=min(mini, prices[i]);
        }
        return profit;

    }
};



//**************************************************************************


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0;
        int ma_profit=0;
        for(int i=0;i<prices.size();i++){
            low=prices[i]<prices[low]? i: low;
            ma_profit=max(ma_profit,prices[i]-prices[low]);
        }
        return ma_profit;

    }
};
