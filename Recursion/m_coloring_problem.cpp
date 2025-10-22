#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// approach 1 ; TC ---> O((m + m * v * e) ^ v)  ; SC---> O(m * v) + O(v)

// checking whether v is adj to any vertex which used color c_no;   TC ---> O(v * e)
bool are_adj(vector<vector<int>> &edges,int v, int c_no, vector<vector<int>> &color){
    for(int i = 0;i<color[c_no].size(); i++){
        int v2 = color[c_no][i];
        for(int j =0;j<edges.size();j++){
            if((edges[j][0]==v && edges[j][1]==v2) || (edges[j][0] == v2 && edges[j][1]==v)){
                return true;
            }
        }
    }
    
return false;
}

bool fun(vector<vector<int>> &edges, int v,int idx,vector<vector<int>> &color){
    // curr_vertex to paint is equal to total no. of vertices mean all vertices are already painted
    if(idx==v){
        return true;
    }

    // we are assigning a color to idx and checking if others can also be colored or not
    // if colored then returning true otherwise , try to assign some other color
    // if either there is no color which can be assigned or if there is no color after whose assignment other rem ver can be colored 
    // then returning false 

    for(int i = 0;i<color.size();i++){                  // O(m)
        if(color[i].empty()){
            color[i].push_back(idx);
            bool x =  fun(edges,v,idx + 1, color);
            if(x==true){
                return true;
            }
            color[i].pop_back();
        }

        else if(!color[i].empty() && !are_adj(edges,idx,i,color)){
            color[i].push_back(idx);
            bool x = fun(edges,v,idx + 1, color);
            if(x==true){
                return true;
            }
            color[i].pop_back();
        }
        
    }
    
return false;
}

int main(){

    int v;
    cin>>v;

    int n;
    cin>>n;

    vector<vector<int>> edges(n,vector<int>(2));
    
    for(int i = 0;i<n;i++){
        cin>>edges[i][0];
        cin>>edges[i][1];
    }

    int m;
    cin>>m;

    vector<vector<int>> color(m);

    bool ans = fun(edges,v,0,color);

    cout<<ans<<endl;

    
return 0;
}