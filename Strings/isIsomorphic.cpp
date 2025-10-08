#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){

    string s1;
    cin>>s1;

    string s2;
    cin>>s2;

    int n = s1.size();

    // considering the len are equal

    // approach 1; TC ---> O(2nlog2n) ==> O(nlog2n) ; SC ---> O(n)
    // for every char in s1 we are checking the corresponding char in s2, if it maps corrrectly or not 

    map<char,char> mp;
    map<char,bool > assign;
    bool ans = true;

    for(int i =0;i<n;i++){
        if(mp.find(s1[i]) == mp.end()){
            if(assign[s2[i]] == false){
                mp[s1[i]] = s2[i];              // O(logn)
                assign[s2[i]] = true;           // O(logn)
            }
            else{
                ans = false ;
                break;
            }
        }
        else{
            if(mp[s1[i]] != s2[i]){
                ans = false;
                break;
            }
        }
    }

    cout<<ans<<endl;

return 0;
}