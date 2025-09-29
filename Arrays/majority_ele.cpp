#include<iostream>
#include<climits>        //for INT_MIN
#include<vector>
#include<algorithm>   //for sort
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1, map      ;TC --->    O(nlogn + nlogn) = O(2nlogn) = O(nlogn);  SC ---> O(N)   

    map<int,int> mp;

    bool flag = 0 ;

    for(int i = 0;i<n;i++){         //O(nlogn)
        mp[arr[i]]++;
    }

    int maxi = -1;
    int maxans = -1;

    //this takes O(nlogn)

    for(int i = 0;i<n;i++){     
        if(mp[arr[i]] > n/2){
            maxi = mp[arr[i]];
            maxans = arr[i];
            break;
        }
    }

    //iterating over the map takes O(n);

    for(auto it : mp){
        if(it.second > n/2){
            maxi = it.second;
            maxans = it.first;
        }
    }

    cout<<maxans<<" "<<maxi<<endl;

    //approach 2, sorting        ; TC -->    O(nlogn + n) = O(nlogn)      ,  SC --> O(1)

    sort(arr, arr+n);       //O(nlogn)

    int cnt = 1 ;
    maxi = 1;
    maxans = arr[0];

    for(int i = 1;i<n;i++){                             //O(n)
        if(arr[i] == arr[i-1]){
            cnt++;
            if(cnt > n/2){
                maxi =  cnt;
                maxans = arr[i];
                break;
            }
        }
        else{
            cnt = 1;
        }
    }


    if(maxi<= n/2){
        maxi = -1;
    }

    cout<<maxans<<" "<<maxi<<endl;


    //approach 3, freq array  ; TC -->  O(N)  ; SC --> O(max ele)

    maxi = INT_MIN;

    for(int i = 0;i<n;i++){
        maxi = max(maxi ,arr[i]);
    }

    int freq[maxi + 1] = {0};

    for(int i = 0; i<n;i++){
        freq[arr[i]]++;
    }

    maxi = -1;
    maxans = -1;

    for(int i = 0;i<n;i++){
        if(freq[arr[i]] > n/2){
            maxi = freq[arr[i]];
            maxans = arr[i];
            break;
        }
    }

    cout<<maxans<<" "<<maxi<<endl;

    //approach 4, Moore's voting algorithm ; TC --> O(n + n) = O(2n) ==> O(n)           ; SC --> O(1)

    //if the ele cnt > n/2 then after fighting with all it will still have 1 or may be greater than that if some other fight in themselves
    //ele left after will always be the greatest ele only if there was definitely a greatest ele in the array 
    //otherwise it may happen than someone not indulged in the fight remained 

    cnt = 0;
    maxi = -1;

    for(int i = 0;i<n;i++){                 //O(n)
        if(cnt  > 0){
            if(arr[i]==maxi){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        else{
            maxi = arr[i];
            cnt = 1;
        }
    }

    int temp = 0 ;
    
    for(int i = 0 ;i<n;i++){                    //O(n)
        if(arr[i]==maxi){
            temp++;
        }
    }

    if(temp <= n/2){
        maxi = -1;
        cnt = 0;
    }

    cout<<maxi<<" "<<temp<<endl;
    

return 0;
}