#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "No of Array Elements: ";
    cin >> n;
    
    cout << "Enter Array Elements: ";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    
    
    // Precompute
    
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }
    
    
    // fetch query
    int q;
    cout << "No of elements to count: ";
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
}
