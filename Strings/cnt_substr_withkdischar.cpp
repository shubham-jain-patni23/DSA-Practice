#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;


int main(){

    string s;
    cin>>s;

    int k;
    cin>>k;

    int n = s.size();

    // approach 1; checking every subarry ; TC ---> O(n^2) ;

    int cnt = 0;
    int curr = 0;

    for(int i = 0;i<n;i++){
        int curr =  1; 
        vector<bool> flag(256,0);
        flag[s[i]] = 1;
        if(curr==k){
            cnt++;
        }

        for(int j = i + 1;j < n;j++){
            if(flag[s[j]]==0){
                flag[s[j]] = 1;
                curr++;
            }
            if(curr==k){
                cnt++;
            }
            else if(curr > k){
                break;
            }
        }
    }

    cout<<cnt<<endl;

    // approach 2;   TC ---> O(n) + O(n) + O(n)= O(3n)    ; SC ---> O(n) + O(n) = O(2n)
    // cnt the total no. of subarr starting from every idx, by first finding end_point and extend which are first idx where subarr formed
    // and the last idx till the idx is valid.

    vector<int> ep(n,-1);
    vector<int> extend(n,n-1);
    vector<int> freq(256,0);

    cnt  = 0;
    curr = 0;  
    int idx = 0 ;

    for(int i = 0;i<n;i++){    //O(n)
        freq[s[i]]++;
        if(freq[s[i]]==1){
            curr++;
        }
        if(curr==k){
            while(true){
                ep[idx] = i;

                freq[s[idx]]--;
                if(freq[s[idx]]==0){
                    curr--;
                    idx++;
                    break;
                }
                idx++;
            }
        }
    }


    vector<int> freq1(256,0);

    idx = 0 ;
    curr = 0 ;

    for(int i =0;i<n;i++){      //O(n)
        freq1[s[i]]++;
        if(freq1[s[i]]==1){
            curr++;
        }
        if(curr > k){   
            while(true){
                extend[idx] = i - 1;
                freq1[s[idx]]--;
                if(freq1[s[idx]]==0){
                    curr--;
                    idx++;
                    break;
                }
                idx++;
            }
        }
    }


    for(int i= 0;i<n;i++){          //O(n)
        if(ep[i]!=-1){
            cnt+= ((extend[i] - ep[i]) + 1);
        }
    }

    cout<<cnt<<endl;

return 0;
}