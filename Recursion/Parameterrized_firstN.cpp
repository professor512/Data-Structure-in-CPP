#include<bits/stdc++.h>
using namespace std;


void firstN(int i, int sum){
    if(i < 1){
        cout << sum;
        return;
    }
    firstN(i-1, sum+i);
}

int main(){
    int n;
    cin >> n;

    firstN(n, 0);
}