#include<bits/stdc++.h>
using namespace std;


int main(){

    set<int>st;
    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(3);           //here also a tree is maintained 
    st.emplace(4);          // it is sorted and stores unique elements

    auto it = st.find(3) ;          //it returns an iterator to the 3

    auto it = st.find(6);  //if an ele is not present in set st.find() will return st.end();

    st.erase(3);        // in log time

    int cnt = st.count(3);      //either will be 1 or 0

    auto it = st.find(6);
    st.erase(it);       //it can be ele or its add. any of two

    auto it1 = st.find(2);
    auto it2  = st.find(5);

    st.erase(it1,it2);

    multiset<int> ms;       //it is also sorted but also stores duplicate elements
    ms.insert(1);
    ms.insert(2);
    ms.erase(1);            //it will erase all the occurences of 1
    ms.erase(ms.find(1)) ; // it will erase only single occurence of 1
    ms.erase(ms.find(1), ms.find(1) + 2)        //it will erase two occrences of 1
    ms.insert(5);  

    int cnt = ms.count(2);


    unordered_set<int> us; //it stores unique ele but does not stores in sorted order   
    // in most of the cases time complexity is O(1) , in worst case O(n)
    // all the ope except lower_bound and upper_bound of set work here




return 0;
}