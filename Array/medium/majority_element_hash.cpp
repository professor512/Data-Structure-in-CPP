// https://www.naukri.com/code360/problems/majority-element_893051?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
int majorityElement(vector<int> &nums)
{
    map<int, int>mpp;

    for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]]++;
    }

    for(auto it : mpp){
        if(it.second > (nums.size() / 2)){
            return it.first;
        }
    }
    return -1;
}



// {NlogN + n, N}
