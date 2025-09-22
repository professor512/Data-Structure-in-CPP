#include<bits/stdc++.h>
using namespace std;

int main(){

    // NOT UNIQUE BUT SORTED
    
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);

    ms.erase(1);            //erases all 1's

    int cnt = ms.count(2);
    cout<<cnt<<endl;

    ms.erase(ms.find(2));

    ms.erase(ms.find(2), next(ms.find(2))); // erase one more 2


    cout<<ms.count(2)<<endl; 

    // Rest all functions are same as set

}
