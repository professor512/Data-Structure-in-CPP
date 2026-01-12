// https://www.naukri.com/code360/problems/superior-elements_6783446?leftPanelTabValue=PROBLEM

vector<int> superiorElements(vector<int>&a) {
    
    int n = a.size();
    int maxi = INT_MIN;
    vector<int>ans;
    for(int i = n-1; i >= 0; i--){
        
        if(a[i] > maxi){
            ans.push_back(a[i]);
        }
        
        maxi = max(maxi, a[i]);


    }
    return ans;
}

// {N, N}