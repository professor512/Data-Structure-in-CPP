#include<bits/stdc++.h>
using namespace std;

int main(){

    // UNIQUE SORTED
    set<int> st;
    st.insert(3);
    st.emplace(7);
    st.insert(7);
    st.insert(23);
    st.insert(4);
    st.insert(1);
    st.insert(2);
    st.insert(5);

    // Functionality of insert in vector can also be used, 
    // that only increases efficiency

    // begin, end, rend, rbegin, size, empty, swap same as those above

    auto it = st.find(3);

    auto it2 = st.find(11); // will return st.end() as 11 not exists

    st.erase(4);

    int cnt = st.count(7);
    cout<<cnt<<endl;

    auto it3 = st.find(3);
    st.erase(it);

    auto it4 = st.find(2);
    auto it5 = st.find(5);
    st.erase(it4, it5);

    auto it6 = st.lower_bound(2);
    auto it7 = st.upper_bound(4);

}
