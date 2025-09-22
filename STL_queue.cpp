#include<bits/stdc++.h>
using namespace std;

int main(){

    // FIFO

    queue<int> q;

    q.push(10);
    q.push(20);
    q.emplace(30);

    q.back() += 5; 

    cout<< q.back()<<endl;

    cout<<q.front()<< endl;

    q.pop();

    cout<< q.front()<< endl;

    //  size swap  empty are same as stack
    

}
