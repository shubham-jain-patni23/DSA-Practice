#include<iostream>
#include<string>
#include<vector>
using namespace std;

// similar to longest common subseq
// we want to make two str equal
// so first we find the maxi len subseq common in both 
// we will keep that intact
// and for the remaining ele we will either delete them or insert in the other

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // approach 1; TC ---> O(n*m) ; SC ---> O(m)

    vector<int> curr(m+1,0);
    int prev = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j<=m;j++){
            int temp = curr[j];
            if(j==0){
                curr[j] = 0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1 +prev;
                }
                else{
                    curr[j] = max(curr[j],curr[j-1]);
                }
            }
            prev = temp;
        }
    }
    int ans = (n - curr[m]) + (m  - curr[m]);
    cout<<ans<<endl;

return 0;
}