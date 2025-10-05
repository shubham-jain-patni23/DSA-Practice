#include<iostream>
#include<algorithm>
//#include<unordered_set>
#include<set>
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

    //approach1; checking all the triplets; TC ---> O(n^3 * log(no. of triplets))   ; SC ---> O(no of triplets)

    //unordered_set<vector<int>> st;
    //there is no hash function for vector<int> in case of unordered_set

    set<vector<int>> s;

    for(int i =0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for(int k = j+1;j<n;j++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j] , arr[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> res(s.begin(),s.end());

    //approach2;    TC ---> O(n^2 *  log(n))         ; SC---> O(No. of pairs) + O(n)
    //using hashing adding two ele and checking whether the third exists in the array

    s.clear();
    res.clear();
    map<int,int> mp;

    for(int i =0 ;i<n;i++){
        for(int j = i + 1;j<n;j++){
            int x  = arr[i] + arr[j];
            if(mp.find(-x)!=mp.end()){
                vector<int> temp = {arr[i], arr[j],-x};
                s.insert(temp);
            }
        }
        mp.clear();
    }
    res(s.begin(),s.end());

    //approach3 ;           TC---> O(n*(n+1)/2) + O(nlogn) ===> O(n^2)             ; SC ---> O(1)
    //fixing one ele and on the subsequent array applying the approach similar to two_sum problem

    vector<vector<int>> ans;
    sort(arr,arr+n);


    for(int i =0;i<n-2;i++){
        if(i!=0 && arr[i]==arr[i-1]){
            continue;
        } 
        vector<int> temp(3,0);
        temp[0] = arr[i];

        int start = i + 1;
        int end = n-1;

        while(start < end){
            int x = arr[start] + arr[end];
            if(x== (-arr[i])){
                temp[1] = arr[start];
                temp[2] = arr[end];
                ans.push_back(temp);
                while(start < end && arr[start]==arr[start+1]){
                    start++;
                }
                start++;
            }
            else if(x < (-arr[i])){
                start++;
            }
            else{
                end--;
            }
        }
    }

    for(auto i: ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}