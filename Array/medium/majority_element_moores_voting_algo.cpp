// https://www.naukri.com/code360/problems/majority-element_893051?leftPanelTabValue=PROBLEM
// Moore's Voting Algorithm

#include <bits/stdc++.h> 
int majorityElement(vector<int> &nums)
{
    int el, cnt = 0;

    for(int i = 0; i < nums.size(); i++){
        if(cnt == 0){
            cnt++;
            el = nums[i];
        }

        else if(nums[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    int cnt2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == el) cnt2++;
    }
    if(cnt2 > (nums.size() / 2)) return el;

    return -1;
}

// {N + N, 1}
// Other N is not required if we are sure that majority element always exists