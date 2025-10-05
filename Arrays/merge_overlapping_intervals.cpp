#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>               //for pair 
using namespace std;

// bool mycomp(pair<int,int> p1, pair<int,int> p2){
//     if(p1.first != p2.first){
//         return p1.first < p2.first;
//     }

//     //it should be always strictly lesser than or greater that otherwise both comp(a,b) and comp(b,a) will return true and can lead to 
//     //infinite loop which may cause runtime error
//     return p1.second < p2.second;               
// }

int main(){

    int n;
    cin>>n;

    vector<pair<int,int>> v(n);

    int x,y;

    for(int i =0;i<n;i++){
        cin>>x>>y;
        v[i].first = x;
        v[i].second = y;
    }

    //approach1 : we sorted the array and then merged the overlapped intervals ; TC ---> O(nlogn) + O(n) ===> O(nlogn) ; SC --> O(1)
    //sort(v.begin(),v.end(),mycomp);


    sort(v.begin(),v.end(),[](pair<int,int> p1,pair<int,int> p2) {      //lambda function
        if(p1.first!=p2.first){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;           //strict comparison
    });


    int maxi;
    vector<pair<int,int>> ans;

    for(int i =0;i<n;i++){
        int j = i+1;
        maxi = v[i].second;

        while((j<n) && (v[j].first <= maxi)){
            maxi = max(maxi , v[j].second);
            j++;
        }
        //if loop breaks then either j ==n or we get some disjoint interval
        pair<int,int> temp = {v[i].first , maxi};
        ans.push_back(temp);
        i = j - 1;
    }
    
    for(auto it : ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

return 0;
}