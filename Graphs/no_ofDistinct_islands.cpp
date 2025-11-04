#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &arr,vector<vector<bool>> &visited,vector<pair<int,int>>&temp){

    int n = arr.size();
    int m = arr[0].size();

    visited[row][col] = 1;
    temp.push_back({row,col});

    // checking upwards
    if(row > 0 && arr[row-1][col]==1 && visited[row-1][col]==0){
        dfs(row-1,col,arr,visited,temp);
    }

    // checking downwards
    if(row<n-1 && arr[row+1][col]==1 && visited[row+1][col]==0){
        dfs(row +1,col,arr,visited,temp);
    } 

    // checking left
    if(col > 0 && arr[row][col-1]==1 && visited[row][col-1]==0){
        dfs(row,col-1,arr,visited,temp);
    }

    // checking right
    if(col < m-1 && arr[row][col+1]==1 && visited[row][col+1]==0){
        dfs(row,col+1,arr,visited,temp);
    }
}

void dfs2(int row,int col,vector<vector<int>> &arr,vector<vector<bool>>&vis,int r,int c, vector<pair<int,int>>&temp){

    int n = arr.size();
    int m = arr[0].size();

    vis[row][col] = 1;
    temp.push_back({row-r,col-c});

    // checking upwards
    if(row > 0 && arr[row-1][col]==1 && vis[row-1][col]==0){
        dfs2(row-1,col,arr,vis,r,c,temp);
    }

    // checking downwards
    if(row<n-1 && arr[row+1][col]==1 && vis[row+1][col]==0){
        dfs2(row +1,col,arr,vis,r,c,temp);
    } 

    // checking left
    if(col > 0 && arr[row][col-1]==1 && vis[row][col-1]==0){
        dfs2(row,col-1,arr,vis,r,c,temp);
    }

    // checking right
    if(col < m-1 && arr[row][col+1]==1 && vis[row][col+1]==0){
        dfs2(row,col+1,arr,vis,r,c,temp);
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // approach 1; TC ---> O(n*m*(4 + log2n*m + n*m + log2n*m + n*m)) SC ---> O(n*m)(visited) + O(n*m)(dfs) + O(n*m)(set)
    // to cnt only distince components
    // we store the components in a set 
    // and then the duplicate components will be removed
    // we align all the components with the first row and first col
    // so that all equal components will have equal coordinates of the nodes

    vector<vector<bool>> visited(n,vector<bool>(m,0));
    set<vector<pair<int,int>>> s;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==1 && visited[i][j]==0){

                vector<pair<int,int>> temp;
                dfs(i,j,arr,visited,temp);

                sort(temp.begin(),temp.end(),[](pair<int,int> p1,pair<int,int> p2){     // O(n*mlog2n*m)
                    return p1.first < p2.first;
                });

                int prev = temp[0].first;
                temp[0].first = 0;

                for(int idx = 1;idx<temp.size();idx++){                     // O(n*m)
                    int x = temp[idx-1].first + (temp[idx].first - prev);
                    prev = temp[idx].first;
                    temp[idx].first  = x;
                }

                sort(temp.begin(),temp.end(),[](pair<int,int> p1,pair<int,int> p2){     // O(n*m log2n*m)
                    return p1.second < p2.second;
                });

                prev = temp[0].second;
                temp[0].second = 0;

                for(int idx = 1;idx<temp.size();idx++){         // O(n*m log2n*m)
                    int x = temp[idx -1].second + (temp[idx].second - prev);
                    prev = temp[idx].second;
                    temp[idx].second = x;
                }

                s.insert(temp);
            }

        }
    }

    int ans = s.size();
    cout<<ans<<endl;

    // approach 2; TC ---> O(n*m + n*m*(4 + log2n*m)); SC ---> O(n*m) + O(n*m) + O(n*m)
    // store the components in the set to remove duplicate components

    vector<vector<bool>> vis(n,vector<bool>(m,0));
    set<vector<pair<int,int>>> st;

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]==1 && vis[i][j]==0){
                vector<pair<int,int>> temp;
                dfs2(i,j,arr,vis,i,j,temp);
                st.insert(temp);
            }
        }
    }

    ans = st.size();
    cout<<ans<<endl;

return 0;
}