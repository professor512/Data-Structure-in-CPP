#include<bits/stdc++.h>
using namespace std;

int main(){

   // SORTED KEYS

   map<int, int> mpp;
   map<int, pair<int, int>> mpp2;
   map<pair<int, int>,int> mpp3;

   mpp[1] = 2;      //for key 1 store value as 2

   mpp.insert({3, 6});

   mpp3[{2,3}] = 10;

   for(auto it : mpp) cout<<it.first<<" - "<<it.second<<endl;

   cout<<mpp[1]<<endl;
   cout<<mpp[5]<<endl;      //prints 0 as 5 not exists

    auto it2 = mpp.find(3);
    cout<<it2->second<<endl;

   // All the other functions works the same

}
