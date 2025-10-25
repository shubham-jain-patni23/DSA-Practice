#include<iostream>
#include<string>
#include<vector>
using namespace std;

// similar to longest common subseq
// we want to find the longest subseq which is palindrome
// now since it is palindrome then it will be also in the rev of str
// so we need  to find the lcs of str and its rev

int main(){

    string s1,s2;
    cin>>s1;

    s2 = s1;
    reverse(s2.begin(),s2.end());

    int n = s1.size();
    int m = n;


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

    cout<<curr[m]<<endl;

return 0;
}