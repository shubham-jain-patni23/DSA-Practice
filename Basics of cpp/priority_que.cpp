#include<bits/stdc++.h>
using namespace std;

int main(){

    //max heap

    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);

    pq.push(3);

    pq.top();               //inside it tree is maintained 

    cout<<pq.top()<<endl;

    //min heap

    priority_queue<int, vector<int>, greater<int>> pq1;

    pq1.push(1);
    pq1.push(2);

    pq1.push(3);

    pq1.top();               //inside it tree is maintained 

    cout<<pq1.top()<<endl;

    //time complexity of push = O(log(n)) and pop in O(log(n)) and top in O(1)

return 0;
}