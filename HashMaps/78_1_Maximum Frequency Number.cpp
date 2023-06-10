// Maximum Frequency Number
// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> count;
    //First store all frequency in the map and also store the maximum frequency 
    int maxAns=0;
    int maxFreq=0;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(count[arr[i]],maxFreq);
    }
    //now again start to traverse arraywhen max frequency and max frequency in the map is equal, that element
    //is also occured the first time and our anser also be same
    for(int i=0;i<arr.size();i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}