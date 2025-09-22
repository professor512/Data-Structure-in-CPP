#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> pq;
    pq.push(3);    
    pq.push(5);    
    pq.push(2);    
    pq.emplace(10);    

    cout<<pq.top()<<endl;
    
    pq.pop();
    
    cout<<pq.top()<<endl;

    // size swap empty functions same as others

    // minimum Heap

    priority_queue<int, vector<int>, greater<int>> mh;
    mh.push(2);
    mh.push(5);
    mh.push(23);
    mh.emplace(1);\

    cout<<mh.top()<<endl;
}
