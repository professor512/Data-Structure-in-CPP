#include<bits/stdc++.h>
using namespace std;

int main(){

    int og, num, rev=0, ld;
    cin>>og;
    num = og;

    while(num > 0){
        
        ld = num % 10;
        num = num / 10;

        rev = (rev * 10) + ld;

    }
    if(og == rev) cout<<"It is Palindrom";
    else cout<<"Not Palindrom";

}
