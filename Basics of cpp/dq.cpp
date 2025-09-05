#include<bits/stdc++.h>
using namespace std;


int main(){

    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);

    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front(); 

    // I am editiing this file

    dq.back();
    dq.front();
return 0;
}
