#include<iostream>
#include<string>
#include<stack> 
#include<vector>
#include<queue>
#include<climits>
using namespace std;



int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n,vector<int>(n,INT_MAX));

    for(int i =0;i<n;i++){
        adj[i][i] = 0 ; 
    }

    // consider every node as intermediate one time then update the k i to k and k  to j

return 0;
}