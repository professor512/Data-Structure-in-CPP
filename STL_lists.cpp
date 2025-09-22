#include<bits/stdc++.h>
using namespace std;

int main(){

    list<int> ls;
    ls.push_back(5);        //{5}
    ls.emplace_back(12);    //{5, 12}

    ls.push_front(3);       //{3, 5, 12}
    ls.emplace_front(7);    //{7, 3, 5, 12}

    // Rest functions are same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap

    for(auto it : ls) cout<<it<<" ";

}
