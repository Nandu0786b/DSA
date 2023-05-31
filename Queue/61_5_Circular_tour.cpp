// Circular tour
// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// medium
// approach : 3 isma humna every point pa balance check kiya and agar balance negative hain tho usko deficit ma add kar diya, and start ko 
// start+1 karna ka bajay start=i+1, because previous petrol pump ka next ko kuch na kuch contribution hotha hain and it's always +ve as a balance
// so agar start sa i thak nahi aa saktha tho fir start and i ka beech walo ki help sa bhi waha pa nahi aa saktha hain isma every element ek bar hi visit hoga
//  
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
      int deficit=0;
      int balance=0;
      int start=0;
      for(int i=0;i<n;i++){
          balance+=p[i].petrol-p[i].distance;
          if(balance<0){
              deficit+=balance;
              start=i+1;
              balance=0;
          }
      }
      if(deficit+balance>=0){
          return start;
      }
      else{
          return -1;
        //   cycle is not possible
      }
    }
};

// approach : 2 basically front and rear lana hain and front always start ma rahega and rear ko balance +ve hona pa aga bada denga and -ve hona pa rear and front both 
// ko increase karenga, rear=rear+1 and front=rear, same uper wala logic 
// if front==rear and and balance>=0 then return this otherwise if front==start then break the loop and there is no cycle so just return -1
// worst case ma every petrol ko two times visit karna hoga, approach one ma ek bar hi karna hain

// approach : 3 Normal o(n^2) har petrol pump ka liya saro ko trivarse kar lo 