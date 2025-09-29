#include<iostream>
#include<vector>
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
            int x = arr[i] + arr[j];

            int rem = k  - x;

            int start = j + 1;
            int end = n-1;

            while(start < end){
                int curr = arr[start] + arr[end];
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