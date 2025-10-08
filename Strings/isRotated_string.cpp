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

    // approach 1;   TC ---> O(n^2) ; SC ---> O(n)
    // to check the rotation we added s2 twice

    bool ans = false;

    if(s1.size()!=s2.size()){
        cout<<ans<<endl;
    }
    else{
        s2 = s2 + s2;
        for(int i =0 ;i<n;i++){
            string curr = s2.substr(i,n);
            int x = curr.compare(s1);
            if(x==0){
                ans = true;
                break;
            }
        }
    }

    cout<<ans<<endl;

return 0;
}