#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);          // similar to push_back but generally faster than push_back

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(3,5);          //here no need to have curly braces

    vector<int> v1(5,100);          // vector of size 5 all initialized with 100;

    vector<int> v3(5);          //vector of size 5 is declared
    cout<<v.size()<<endl;
    vector<int> v4(v3);         //v4 is the copy of vector v3


    // accessing a vector

    cout<<v1[0]<<endl;

    vector<int>::iterator it = v1.begin();
    it++;
    cout<<*it<<endl;

    it = it + 2;
    cout<<*it<<endl;

    vector<int>::iterator it1 = v1.end();
    it1--;
    vector<int>::iterator it2 = v1.rend();          //rev iterator
    vector<int>::iterator it3 = v1.rbegin();

    cout<<v4.back()<<endl;

    auto a = 5;
    auto b = "shubham";

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    for(auto it : v){
        cout<<it<<" ";
    }

    v1.erase(v.begin() + 1);
    //deleting in a range 
    v1.erase(v.begin() + 2 , v.begin() + 3);  //v.erase(start,end)          erase from start and right before end [start,end)

    v1.insert(v.begin(),300);
    v1.insert(v.begin()+2 , 3, 100)//    three 100 after third element onwards

    //inserting a vec inside a vec

    v1.insert(v.begin() + 1,v.begin() , v.end());

    v.pop_back();

    v.swap(v1);

    v.clear();
    cout<<v.empty();


return 0;
}