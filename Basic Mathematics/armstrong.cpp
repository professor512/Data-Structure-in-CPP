#include<bits/stdc++.h>
using namespace std;

int main(){

    int num, og, sum = 0, ld;
    cin>>num;
    og = num;
    int digits = to_string(num).size();

    while(num > 0){

        ld = num % 10;
        num = num /10;

        sum = sum + pow(ld, digits); 
    }
    if(og == sum) cout<<"It is armstrong";
    else cout<<"Not armstrong";

}
