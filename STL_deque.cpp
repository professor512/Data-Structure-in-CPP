#include<bits/stdc++.h>
using namespace std;

int main(){

    deque<int> dq;
    dq.push_back(31);
    dq.emplace_back(10);
    dq.push_front(7);
    dq.emplace_front(19);

    dq.pop_front();
    dq.pop_back();

    cout<<dq.back()<<endl;
    cout<<dq.front()<<endl;
    
    for(auto it : dq) cout<<it<<" ";
}
