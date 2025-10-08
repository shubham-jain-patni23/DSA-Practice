#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;


int main(){

    string s;
    cin>>s;

    int n = s.size();

    int maxi, mini ; 
    long long cnt = 0 ;

    char minch; 
    char maxch;

    for(int i = 0;i<n;i++){

        vector<int> freq(26,0);

        for(int j = i;j<n;j++){

            maxi = -1, mini = 501;

            freq[s[j]-'a']++;

            for(int k =0 ;k<26;k++){
                maxi = max(maxi , freq[k]);
                if(freq[k]!=0){
                    mini = min(mini, freq[k]);
                }
            }
            
            cnt+= (maxi - mini);
        }
    }

    cout<<cnt<<endl;

return 0;
}