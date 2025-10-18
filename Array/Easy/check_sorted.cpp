// https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957?leftPanelTabValue=SUBMISSION

int isSorted(int n, vector<int> a) {
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i - 1]){
            continue;
        }
        else return false;
    }
    return true;
}
