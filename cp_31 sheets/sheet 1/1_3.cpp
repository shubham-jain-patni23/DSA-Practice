#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string s;
        cin>>s;

        int ans = 0;
        int last = -1;

        for(int i =0;i<n;i++){
            if(s[i]=='.'){
                if(last==-1){
                    last = i;
                }
            }
            else{
                if(last!=-1){
                    if((i - last)==1){
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                    last = -1;
                }
            }
        }

        if(last!=-1){
            if((n - last)==1){
                ans++;
            }
            else{
                ans+=2;
            }
        }

        cout<<ans<<endl;
        
    }

return 0;
}