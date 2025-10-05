#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    int k; 
    cin>>k;

    int arr[n];

    for(int i = 0;i<n;i++){ 
        cin>>arr[i];
    }

    //approach1 ; using four loops ; TC ---> O(n^4 * log(no of quadrupls))  ; SC ---> O(no of quadruples)

    //approach2 ;using hashmaps ; we will add three and search for the fourth ele ; TC ---> O(n^3 * log(no of quadruples)) ; SC ---> O(no of quadruples)

    set<vector<int>> st;

    for(int i = 0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            //to avoid overflow we are using long long 
            //we can use convert in the exp itself e.g. by multiplying with 1LL or we can add integers one by one to the long long
            map<long long,int> mp;              
            for(int l = j+1;l < n;l++){
                long long sum = 1LL*arr[i] + arr[j] + arr[l];
                //long long rem = 1LL*k - sum;          or I do operation one by one
                long long rem = k;
                rem-=sum;
                if(mp.find(rem)!=mp.end()){
                    vector<int> temp = {arr[i], arr[j], arr[l] , (int)rem};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp[arr[l]]++;
            }
            mp.clear();
        }
    }

    vector<vector<int>> res(st.begin(),st.end());

    for(auto it : res){
        for(int i =0;i<4;i++){
            cout<<it[i]<<" ";
        }
        cout<<endl;
    }


    //approach3 ;               TC ---> O(n^3) + O(nlogn)   ; SC ---> O(1)
    //extension of two_sum and three_sum problem 

    vector<vector<int>> ans;
    sort(arr,arr+n);


    for(int i = 0 ;i<n-3;i++){

        if(i!=0 && arr[i]==arr[i-1]){
            continue;
        }

        for(int j = i + 1;j<n-2;j++){

            vector<int>temp(4,0);

            temp[0] = arr[i];
            temp[1] = arr[j];
            long long x = 1LL*arr[i] + arr[j];

            long long rem = 1LL*k  - x;

            int start = j + 1;
            int end = n-1;

            while(start < end){
                long long curr = 1LL*arr[start] + arr[end];
                if(curr==rem){
                    temp[2] = arr[start];
                    temp[3] = arr[end];
                    ans.push_back(temp);
                    while(start < end && arr[start]==arr[start +1]){
                        start++;
                    }
                    start++;
                }
                else if(curr < rem){
                    start++;
                }
                else{
                    end--;
                }
            }

            while(j< n-2 && arr[j]==arr[j+1]){
                j++;
            }

        }
    }

    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}