#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<string> v(n);

    for(int i =0 ;i<n;i++){
        cin>>v[i];
    }

    // approach 1 ; TC ---> O(maxi str) * O(n)   ; SC ---> O(1)
    // we are checking each char for all the arr starting from the first char

    int idx = 0 ;
    string ans = "";
    
    while(true){
        int cnt;
        char ch;
        if(v[0].size() <= idx){
            break;
        }
        else{
            cnt = 1;
            ch = v[0][idx];
        }

        for(int i = 1;i<n;i++){
            if(v[i].size() > idx && v[i][idx]==ch){
                cnt++;
            }
            else{
                break;
            }
        }

        if(cnt < n){
            break;
        }
        else{
            ans+= ch;
        }
        idx++;
    }

    cout<<ans<<endl;

return 0;
}