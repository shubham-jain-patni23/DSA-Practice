#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<int> g(n);  

    for(int i =0;i<n;i++){
        cin>>g[i];
    }

    vector<int> s(m);
    for(int i =0;i<m;i++){
        cin>>s[i];
    }

    // approach; using greedy; TC ---> O(nlog2n) + O(mlog2m)  + O(m) ; SC ---> O(1)
    // greedy for cookies 

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int j = 0 ;
    int cnt = 0;

    for(int i =0 ;i<m;i++){
        if(j>=n){
            break;
        }
        if(g[j] <= s[i]){
            j++;
            cnt++;
        }
    }

    cout<<cnt<<endl;

return 0;
}