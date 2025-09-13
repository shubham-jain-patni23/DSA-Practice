#include<iostream> 
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

    map<int,int> mp;

    for(int i = 0;i<n;i++){         //O(Nlog(N))
        mp[arr[i]]  = i;            
    }

    int firstidx , secondidx;


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
                secondidx = mp[first];
            }
            break;
        }

    }

    cout<<firstidx<<" "<<secondidx<<endl;

return 0;
}