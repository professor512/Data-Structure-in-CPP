#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter No of Elements: ";
    cin >> n;

    int arr[n];
    map<int, int>mpp;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    

    for(auto it : mpp){
        cout<<it.first << "->" << it.second << endl;
    }
    

    // fetch query
    int q;
    cout << "No of elements to count: ";
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
}
