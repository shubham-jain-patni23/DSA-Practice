#include<iostream> 
#include<algorithm>
#include<climits>           //for using INT_MIN 
#include<cstring>           //for using memset
#include<vector>
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;

    int sum ;
    cin>>sum;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    //approach 1

    bool f = false;

    for(int i =0;i<n;i++){                          //O(N^2)
        for(int j = i + 1;j<n;j++){
            if(arr[i] + arr[j]==sum){
                cout<<arr[i]<<" "<<arr[j]<<endl;
                f = true;
                break;
            }
        }
    }

    if(f==0){
        cout<<"Sum does not exit"<<endl;
    }



    //approach 2
    map<int,int> mp;

    // for(int i = 0;i<n;i++){         //O(Nlog(N))
    //     mp[arr[i]]  = i;            
    // }

    int firstidx =-1 , secondidx =-1;


    for(int i = 0;i<n;i++){         //O(Nlog(N)) as find() takes O(logN) time 
        int first = arr[i];             //Time complexity : O(2NlogN) = O(NlogN)
        int second = sum - first;       //Space complexity : O(N)
        
        if(first==second){
            continue;
        }

        if(mp.find(second)!=mp.end()){

            if(first < second){
                firstidx = i;
                secondidx = mp[second];
            }
            else{
                firstidx = mp[second];
                secondidx = i;
            }
            break;
        }

        mp[arr[i]] = i;
    }

    cout<<firstidx<<" "<<secondidx<<endl;

    //approach 3 
    //instead of using map we can have a boolean array, time complexity O(n), space complexity O(maximum ele)

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i = 0;i<n;i++){                     //O(n)
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
    }

    int flag[maxi + 1] ;

    memset(flag,-1,sizeof(flag));               //O(no. of bytes filles) ===> O(n)

    for(int i =0;i<n;i++){          //space complexity of flag array : O(maxi element);
        flag[arr[i]] = i;
    }

    firstidx = -1;
    secondidx = -1;

    for(int i =0;i<n;i++){                              //O(n)
        int first = arr[i];
        int second = sum - arr[i];      

        if(second <= maxi && second>=mini){
            if(first!=second && flag[second]!=-1){
                if(first < second) { 
                    firstidx = i;
                    secondidx =flag[second];
                }
                else{
                    firstidx = flag[second];
                    secondidx = i;
                }
                break;
            }
        }

    }

    cout<<firstidx<<" "<<secondidx<<endl;


    //approach 4; Time complexity:    O(n) + O(nlogn)  ==> O(n)
    //            Space complexity : O(1) 

    vector<pair<int,int>> v(n);

    for(int i =0;i<n;i++){
        v[i] = {arr[i],i};
    }

    sort(v.begin() , v.end());    //O(nlogn)
    //after sorting idx will be changed

    int i = 0, j = n-1;

    while(i < j){    //O(n)                        
        int temp = v[i].first + v[j].first;
       
        if(temp==sum){
            cout<<v[i].second<<" "<<v[j].second<<endl;
            break;
        }
        else if(temp > sum){
            j--;
        }
        else{
            i++;
        }
    }

    if(i >= j){
        cout<<"sum does not exit"<<endl;
    }

return 0;
}