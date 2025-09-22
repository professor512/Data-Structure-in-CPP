#include<bits/stdc++.h>
using namespace std;



bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // seconds are same
    if(p1.second == p2.second){
        if(p1.first > p2.first) return true;
    }
    return false;
}

int main(){

    //    sort(a, a + n);
    //    sort(v.begin(), v.end());
    //    sort(a+2, a+4);
    
    //    Descending order
    //    sort(a, a+n, greater<int>)

    pair<int, int> a[] = {{1,2}, {2, 1}, {4,1}};

    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending  

    sort(a, a+3, comp);
    // {{4,1}, {2, 1}, {1,2}}

    for(auto it : a) cout<<it.first<<" - "<<it.second<<endl;

    int num = 7;
    int cnt = __builtin_popcount(num);      //Returns the total 1's in binary of entered num
    cout<<cnt<<endl;
    
    long long num2 = 567865456765;
    int cnt2 = __builtin_popcountll(num2);      //Returns the total 1's in binary of entered num
    cout<<cnt2<<endl;
    
    
    string s = "231";
    sort(s.begin(), s.end());

    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));


    // int maxi = *max_element(a, a+n);
    // int mini = *min_element(a, a+n);


}
