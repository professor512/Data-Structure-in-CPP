#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter String: ";
    cin >> s;
    
    // Precompute
    
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }
    
    
    // fetch query
    int q;
    cout << "No of chars to count: ";
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
}
