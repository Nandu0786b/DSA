// Maximum Height by Stacking Cuboids

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

//approach:- basically same as the previous bst approach, in this quesion they said you can take or rearrange dimension. so first we will sort and will take maximum dimension as a height
//after this two things is remaining base area(length and weidth)
//



class Solution {
public:
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){
            return true;
        }
        return false;

    }
    int solvebst(int n, vector<vector<int>>& a){
        vector<int> c(n+1, 0);
        vector<int> ne(n+1, 0);

        for(int cur=n-1; cur>=0; cur--){
            for(int pre=cur-1; pre>=-1; pre--){
                int take=0;
                if(pre == -1 || check(a[cur],a[pre]) ){
                    take=a[cur][2]+ne[cur+1];
                }

                //exclude
                int nottake= 0+ne[pre+1];

                c[pre+1]= max(take,nottake);
                    }
            ne=c;
        }

        return c[0];

    }
    int maxHeight(vector<vector<int>>& cuboids) {

        //sort all dimension for every cuboids
        for(auto &a:cuboids){
            sort(a.begin(), a.end());
            }
        //sort all cuboids based on length or weidth
        sort(cuboids.begin(), cuboids.end());

        //use bst logic
        return solvebst(cuboids.size(), cuboids);
    }
};