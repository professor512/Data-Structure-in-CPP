#include<bits/stdc++.h>
using namespace std;


int firstN(int i){
    if(i == 0){
        return 0;
    }
    return i + firstN(i-1);
}

int main(){
    int n;
    cin >> n;

    cout << firstN(n);
}