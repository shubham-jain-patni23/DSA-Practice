#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool l_search(int arr[],int n,int key){
    for(int i =0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
return false;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach1 : checking seq starting with every ele ; TC ---> near about O(n^2)  ; SC ---> O(1)

    int maxii = 1;
    
    for(int i =0;i<n;i++){
        int curr = 1 ;
        int last = arr[i];
        while(l_search(arr,n,last+1)){
            curr++;
            last++;
        }
        maxii = max(maxii , curr);
    }
    cout<<maxii<<endl;

    //approach2: sort    ;    TC ---> O(nlogn)              SC---> O(1)

    sort(arr,arr+n);

    int ans = 1;
    int curr = 1;

    for(int i = 1;i<n;i++){
        if(arr[i]==arr[i-1]){
            continue;
        }
        if((arr[i] - arr[i-1])==1){
            curr++;
            ans = max(curr,ans);
        }
        else{
            curr = 1;
        }
    }

    cout<<ans<<endl;

    

    //approach 3; making a freq array    ; TC --> O(max(n, maxi))   ; SC ---> O(maxi)

    int maxi = *max_element(arr,arr+n);

    int freq[maxi + 1] = {0};

    for(int i =0;i<n;i++){
        freq[arr[i]]++;
    }

    ans = 0;
    curr =0 ;

    for(int i =0;i<= maxi;i++){
        if(freq[i]==0){
            curr =0;
        }
        else{
            curr++;
        }
        ans =  max(curr,ans);
    }

    cout<<ans<<endl;

    //approach 4 : using unordered_set ; TC ---> avg case O(n) + O(2n) = O(3n)   ; SC ---> O(n)
    //in best and avg case insert takes O(1) and in worst case O(n) when the collisions happen

    unordered_set<int> s;
    for(int i = 0;i<n;i++){         //O(n)
        s.insert(arr[i]);
    }

    ans =1 ;

    for(auto it : s){                   //O(n) + O(n) = O(2n)
        if(s.find(it - 1)==s.end()){
            int curr = 1;
            int x = it;
            while(s.find(x + 1)!=s.end()){
                curr++;
                x++;
            }
            ans =max(ans, curr);
        }
    }

    cout<<ans<<endl;

return 0 ;
}