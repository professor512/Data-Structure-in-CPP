#include<bits/stdc++.h>
using namespace std;

int main(){

    int num, revNum=0, ld;
    cin>>num;
    while(num > 0){
        ld = num % 10;
        num = num /10;

        revNum = (revNum * 10) + ld;

    }
    cout<<revNum;

}
