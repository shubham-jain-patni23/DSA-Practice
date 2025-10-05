#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int x = n/3;

    //approach 1, making cnt ; TC---> O(n^2)    ;SC ---> O(1)

    vector<int> ans;

    for(int i =0 ;i<n;i++){
        if(ans.size()==2){      //there can be at max two possible ele with > n/3 cnt
            break;
        }
        if(ans.size()==0 || ans[0]!=arr[i]){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(arr[j]==arr[i]){
                    cnt++;
                }
            }
            if(cnt > (n/3)){
                ans.push_back(arr[i]);
            }
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

    //approach2 , using maps   ; TC ---> O(nlogn) + O(n)   ; SC ---> O(n)

    map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
        if(it.second > x){
            cout<<it.first<<" ";
        }
    }
    cout<<endl;

    //approach3, using maps but iterating only once   --->O(nlogn)   ; SC ---> O(n)
    ans.clear();


    map<int,int> mp2;
    for(int i = 0 ;i<n;i++){
        mp2[arr[i]]++;
        if(mp2[arr[i]]==((n/3) + 1)){
            ans.push_back(arr[i]);
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;


    //approach4 ;           TC ---> O(n) + O(n) = O(2n) ==> O(n)       ; SC ---> O(1)
    //using the idea of fighting the two major ele with the other and in the end two with the freq > n/3 will be remained
    ans.clear();

    // vector<int> ans;

    // if(n==1){
    //     return {arr[0]};
    // }

    int cnt1  = 0, cnt2 =0;
    int ele1 = arr[0]; int ele2=arr[1]; 

    for(int i = 0;i<n;i++){
        if(cnt1==0){
            //I am writing it in case if I am not able to initialize ele1 and ele2 with 
            //the array ele as in that case i won't be able to do (ele2 != arr[i]) as e.g 
            //if I initialize ele2 with INT_MIN and the first ele is also INT_MIN then in that case I can't assign arr[i] to ele1
            if(cnt2!=0){
                ele1 = ele2;
                cnt1 = cnt2;
                cnt2 = 0;
                if(arr[i]==ele1){
                    cnt1++;
                }
                else{
                    cnt2 = 1;
                    ele2 = arr[i];
                }
            }
            else{
                ele1 = arr[i];
                cnt1 = 1;
            }
        }
        else if(arr[i]==ele1){
            cnt1++;
        }
        else if(cnt2==0){
            ele2 = arr[i];
            cnt2 = 1;
        }
        else if(arr[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0 ;

    for(int i = 0;i<n;i++){
        if(arr[i]==ele1){
            cnt1++;
        }
        else if(arr[i]==ele2){
            cnt2++;
        }
    }

    if(cnt1 > n/3){
        ans.push_back(ele1);
    }
    if(cnt2 > n/3){
        ans.push_back(ele2);
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

return 0;
}