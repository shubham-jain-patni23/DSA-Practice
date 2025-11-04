#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;  

bool addedge(string f,string s,vector<vector<int>>&adj){
        
    int n = f.size();
    int m = s.size();
    
    int i = 0, j=0;
    bool flag = false;
    
    while(i<n && j<m){
        if(f[i]==s[j]){
            i++;
            j++;
        }
        else{
            adj[f[i]-'a'][s[j]-'a'] = 1;
            flag = true;
            break;
        }
    }

    if(i<n && j==m){
        return false;
    }

return true;
}
  

int main(){

    int n;
    cin>>n;

    vector<string> arr(n);

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // approach 1; 
    // we need the topological sort of the alphated
    // step 1; first find all the nodes
    // step 2; add all the edges   
    // step 3; find the indgree of all the nodes
    // step 4; using multisrc bfs(staring from 0 ind nodes) find the order
    // step 5; check if any cycle was present
 
    // step 1; finding all the nodes
    map<char,int> mp;
        
    for(int i = 0;i<n;i++){
        for(auto it : arr[i]){
            mp[it]++;
        }
    }
    // total no. of nodes
    int v = mp.size();
    
    // idx 0 means 'a' ;
    // adj[i][j] == 1; means to char i ; char j is connected
    vector<vector<int>> adj(26,vector<int>(26,0));
    
    
    // step2 ; adding the edges
    // traversing the arr to find the edges 
    // the words are arranged using some char or either len
    // if using some char then an edge can be added
    // also if the words are not in order then we addedge will return false
    
    bool inval = false;

    // for(int i =0;i<n;i++){
    //     for(int j = i+1;j<n;j++){
    //         string f = arr[i];
    //         string s = arr[j];
    //         bool x = addedge(f,s,adj);
    //         if(x==false){
    //             inval = true;
    //             break;
    //         }
    //     }
    // }

    for(int i =1;i<n;i++){
        string f = arr[i-1];
        string s = arr[i];
        bool x = addedge(f,s,adj);
        if(x==false){
            inval = true;
            break;
        }
    }

    string ans = "";

    if(!inval){
        // step 3; finding indegree of all nodes 
    
        vector<int> ind(26,0);
        
        for(int i= 0;i<26;i++){
            for(int j = 0;j<26;j++){
                if(adj[i][j]==1){
                    ind[j]++;
                }
            }
        }
        
        
        // step 4; pushing nodes with zero ind and applying bfs
        queue<char> q;
        
        for(int i = 0;i<26;i++){
            if((mp[i+'a'] > 0) &&  (ind[i]==0)){
                q.push(i+'a');
            }
        }
    

        while(!q.empty()){

            char idx = q.front();
            ans = ans + idx;
            q.pop();
            
            for(int it = 0;it < 26;it++){
                if(adj[idx-'a'][it]==1){
                    ind[it]--;
                    if(ind[it]==0){
                        q.push(it + 'a');
                    }
                }
            }
        }
        
        // step 6; check for cycle
        if(ans.size()!=v){
            ans = "";
        }
    }
    
    
    cout<<ans<<endl;

return 0;
}