#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);
    q.push(45);
    q.push(54);

    q.back()+=5;

    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;

return 0;
}