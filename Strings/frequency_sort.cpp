#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<functional>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    string s;
    cin>>s;

    int n = s.size();

    //approach 1; using the freq arr to store cnt and sort w.r.t cnt ; O(n) + O(2^11) + O(n)  ==> O(nlogn) ; SC ---> O(n)

    vector<int> freq(256);

    for(int i =0;i<n;i++){          //O(n)
        freq[(int)s[i]]++;
    }

    vector<pair<int,int>> v;

    for(int i =0;i<256;i++){        //O(256)
        if(freq[i] > 0){
            v.push_back({freq[i],i});
        }
    }

    sort(v.begin(),v.end(),greater<pair<int,int>>());           //O(256log256) = O(256 * 8) = O(2^11)

    string ans = "";

    for(auto i : v){
        char ch = (char)i.second;
        string curr(i.first, ch);
        ans+= curr;
    }

    cout<<ans<<endl;

return 0;
}