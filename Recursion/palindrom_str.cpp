#include<bits/stdc++.h>
using namespace std;

bool checkPal(int i, string &s){
    if(i >= s.size() / 2) return true;

    if(s[i] != s[s.size() - i - 1]) return false;

    return checkPal(i+1, s);
}


int main(){

    string str = "madam";

    cout << checkPal(0, str);




}