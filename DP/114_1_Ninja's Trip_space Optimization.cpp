// Ninja's Trip

// https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0

//Approach:- we are using same previous approach for this question but in this we are going to do space optimization
//here we are using normal queue to trak the previous dayand we will remove element if element is exprire


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans=0;


    queue<pair<int,int>> month;
    queue<pair<int,int>>week;

    for(int day:days){

        //remove expire days
        while(!month.empty() && month.front().first+30<=day)
            month.pop();

        while(!week.empty() && week.front().first+7<=day)
            week.pop();

        //add cost for the current day

        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        ans=min(ans+cost[0],min(week.front().second,month.front().second));

    }

    return ans;

}