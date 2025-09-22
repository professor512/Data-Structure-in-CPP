#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cin >> num;

    // for(int i = 1; i <= num; i++){
    //     if(num % i == 0) cout<<i<<" ";
    // }

    vector<int>v;

    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            v.push_back(i);
            if(num/i != i){
                v.push_back(num/i);
            } 
        }
    }

    sort(v.begin(), v.end());

    for(auto it : v) cout<<it<<" ";

}
