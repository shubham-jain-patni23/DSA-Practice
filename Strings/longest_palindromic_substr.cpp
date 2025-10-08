#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;


int main(){

    string s;
    cin>>s;

    int n = s.size();


    // approach 1 ; checking all the substr ; TC ---> O(n^3)  ; SC ---> O(1)

    int ans = 1;
    string anscurr = "";
    anscurr+= s[0];

    for(int i =0;i<n;i++){
        string curr = "";
        for(int j = i;j<n;j++){
            curr+=s[j];
            if(s[j]==s[i]){
                string temp = curr;
                reverse(temp.begin(),temp.end());       //O(n)
                int x = temp.compare(curr);             //O(n)
                if(x==0){
                    if(temp.size() > ans){
                        ans = temp.size();
                        anscurr = temp;
                    }
                }
            }
        }
    }

    cout<<anscurr<<endl;

    // approach 2;  TC ---> O(2n^2)     ; SC ---> O(1)
    // with every char inbetween we make the palindrome

    ans = 1;
    anscurr = "";
    anscurr+= s[0];

    for(int i= 0;i<n;i++){                  //O(n^2)
        int st = i-1, end = i+1;
        string curr = "" ;
        curr+=s[i];
        while((st>=0) && (end<n) && (s[st]==s[end])){
            string temp = "";
            temp+= s[st];
            curr = temp  + curr;
            curr+=s[st];
            if(curr.size() > ans){
                ans = curr.size();
                anscurr = curr;
            }
            st--;
            end++;
        }   
    }

    for(int i = 0;i<n-1;i++){           //O(n^2)
        int st = i, end = i + 1;
        string curr = "";
        while((st>=0) && (end<n) && (s[st]==s[end])){
            string temp = "";
            temp+= s[st];
            curr = temp  + curr;
            curr+=s[st];
            if(curr.size() > ans){
                ans = curr.size();
                anscurr = curr;
            }
            st--;
            end++;
        }
    }

    cout<<anscurr<<endl;


return 0;
}