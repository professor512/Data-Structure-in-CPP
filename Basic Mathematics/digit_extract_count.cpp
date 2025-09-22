#include<bits/stdc++.h>
using namespace std;

int main(){
    int num, lastdigit, count = 0;
    cout<<"Enter a number: ";
    cin>>num;

    while(num > 0){
        lastdigit = num % 10;
        cout<<lastdigit<<" ";
        num = num / 10;
        count++;
    }

    cout<<endl<<"Total Digits: "<<count<<endl;
}
