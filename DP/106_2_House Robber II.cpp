// House Robber II

// https://www.codingninjas.com/codestudio/problems/house-robber_839733

//same as the previous but here houses in the circle so we can not take last and first both because they are also neighbour of the each other


//************************************ TABULATION ************************************************************
//TC=O(N)
//SC=O(N),BECAUSE WE ARE USING THE VECTOR

#include <bits/stdc++.h>
long long int Tabulation(vector<int>& valueInHouse){
    int n=valueInHouse.size();

    long long int pr1=valueInHouse[0];
    long long int pr2=0;
    long long int prr;

    for(int i=1;i<n;i++){
        prr=pr1;
        pr1=max(valueInHouse[i]+pr2,pr1);
        pr2=prr;
    }
    return pr1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    if(valueInHouse.size()==1){
        return valueInHouse[0];
    }
    //for the case when we include first house we can not add last house
    vector<int> first(valueInHouse.begin(),valueInHouse.end()-1);

    //for the case when we include last house we can not add first house
    vector<int> last(valueInHouse.begin()+1,valueInHouse.end());
    return max(Tabulation(first),Tabulation(last));
}