#include<iostream> 
#include<vector>
#include<set>
using namespace std;

int main(){

    int n1, n2;
    cin>>n1>>n2;

    int a[n1] , b[n2];
    
    for(int i = 0;i<n1;i++){
        cin>>a[i];
    }

    for(int i = 0;i<n2;i++){
        cin>>b[i];
    }

    vector<int> ans;

    int i = 0, j = 0;

    while(i<n1 && j<n2){               //Time complexity : O(n1 + n2)    , Space complexit : O(n1 + n2)    
        if(a[i] < b[j]){

            //instead of comparing in the arr we can also check in the temp for the duplicates 
            //if(temp.size() == 0 || a[i]!=temp.back())

            if(i==0 || a[i]!=a[i-1]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else if(a[i] > b[j]){
            if(j==0 || b[j]!=b[j-1]){
                ans.push_back(b[j]);
            }
            j++;
        }
        else{
            i++;
        }
    }

    while(i< n1){
        if(i==0 || a[i]!=a[i-1]){
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j < n2){
        if(j==0 || b[j]!=b[j-1]){
            ans.push_back(b[j]);
        }
        j++;
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

    //approach2   
    set<int> s;

    for(int i = 0;i<n1;i++){        //time complexity : O(n1log2n + n2log2n)
        s.insert(a[i]);
    }

    for(int i = 0;i<n2;i++){
        s.insert(b[i]);
    }

    for(auto it  : s){
        cout<<it<<" ";
    }cout<<endl;
    
return 0;
}