#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int last = 0;
    
    for(int i = 1;i<n;i++){                     //O(N)
        if(arr[i] != arr[i-1]){
            last++;
            arr[last] = arr[i];
        }
    }

    cout<<"No. of unique elements : "<<last + 1<<endl;

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //implemented as red black tree, it is O(logn) time complexity

    set<int> s;            

    for(int i = 0;i<n;i++){                     //Time complexity: O(Nlog2N) 
        s.insert(arr[i]);                       //Space complexity: O(N)
    }

    int i = 0;
    for(auto it : s){
        arr[i] = it;
        i++;
    }

    cout<<"No. of unique elements : "<<s.size()<<endl;
    cout<<"No. of unique elements : "<<i<<endl;

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}