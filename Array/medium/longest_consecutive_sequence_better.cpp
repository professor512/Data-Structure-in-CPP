// https://www.naukri.com/code360/problems/longest-successive-elements_6811740?leftPanelTabValue=PROBLEM
int longestSuccessiveElements(vector<int>&a) {
    
    if(a.size() == 0) return 0;

    sort(a.begin(), a.end());

    int longest = 1;
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int n = a.size();

    for(int i = 0; i < n; i++){
        if(a[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = a[i];
        }
        else if(lastSmaller != a[i]){
            cnt = 1;
            lastSmaller = a[i];

        }
        longest = max(cnt, longest);
    }

    return longest;
}
// {N + N log N, 1}