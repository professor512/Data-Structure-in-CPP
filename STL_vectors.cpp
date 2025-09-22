#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.emplace_back(80);

    vector<pair<int, int>>vec;
    vec.push_back({1,3});
    vec.emplace_back(4,5);

    vector<int>v2(5, 100);

    vector<int>v3(5);

    vector<int>v4(v2);

    // ITERATOR
    vector<int>::iterator it = v.begin();
    it++;
    cout<<*(it)<<endl;
    
    it = it + 2;
    cout<<*(it)<<endl;
    
    
    // vector<int>::iterator it = v.end();
    // vector<int>::iterator it = v.rbegin();
    // vector<int>::iterator it = v.rend();
    
    cout<<v[0]<<" "<<v.at(1)<<endl;
    cout<< v.back() <<" "<<endl;

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    // EARSE
    v.erase(v.begin()+1);
    v.erase(v.begin()+2, v.begin()+4);
    
    // INSERT
    vector<int>vec1(2,100);                                  // {100, 100}
    vec1.insert(vec1.begin(), 300);                            // {300, 100, 100}
    vec1.insert(vec1.begin()+1, 2, 50);                        // {300, 50, 50, 100, 100}

    vector<int>vec2(2, 25);                                 // {25, 25}
    vec1.insert(vec1.begin(), vec2.begin(), vec2.end());      // {25, 25, 300, 50, 50, 100, 100}

    cout<< vec1.size()<<endl;

    vec1.swap(vec2);    
    
    vec1.clear();             //erases entire vector

    cout<<vec1.empty()<<endl;

    
    


}
