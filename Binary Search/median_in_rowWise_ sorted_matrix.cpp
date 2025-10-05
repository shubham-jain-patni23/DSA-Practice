#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
#include<utility>
using namespace std;

// for minheap we are comparing the ele to be greater
// priority_queue considers that whenever the mycomp returns true then the first ele has to come after second.
// means if p1.first < p2.first is true that means p1 has to come after p2

// in sorting if comparator return true ; then a comes before b 
// in priority_queue its oppositie ; if comparator returns true; then that means a has lower priority than be ; so a comes after b; 
// whether we write a < b or a > b 


bool mycomp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first != p2.first){
        return p1.first > p2.first;
    }
return p1.second > p2.second;
}

int main(){

    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // approach 1 ; sort them ; TC ---> O(n^2log2n^2)  ==> O(2n^2log2n) ; SC ---> O(n^2)

    // approach 2 ;          TC ---> O(nlog2n) + O(n^2/2) * (log2n + log2n)  ===> O(nlog2n) + O(2n^2log2n) ; SC ---> O(n)
    // using min-heap to merge the sorted rows and meanwhile finding the min

    //priority_queue<pair<int,int>,vector<pair<int,int>> ,decltype(&mycomp)> pq(mycomp);
    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

    for(int i = 0;i<n;i++){
        pq.push({arr[i][0], i, 0});
    }

    int cnt  = 0;
    int x  = ((n*m) + 2 - 1) / 2 ;
    x--;
    int total = n * m;
    double ans  = 0;

    while(cnt < x){
        cnt++;
        if(pq.size() <= 0){
            break;
        }
        vector<int> temp = pq.top();

        pq.pop();
        int row = temp[1];
        int col = temp[2];

       

        col++;
        if(col < m){
            pq.push({arr[row][col], row, col});
        }
    }

    if(pq.size() > 0){

        vector<int> temp = pq.top();
        pq.pop();
        ans = (double)temp[0];

        if(total % 2==0){
            int row = temp[1];
            int col = temp[2];
            col++;
            if(col < m){
                pq.push({arr[row][col], row, col});
            } 
            if(pq.size() > 0){
                temp = pq.top();
                pq.pop();
                ans = ans + (double)temp[0];
                ans = ans / 2.0;
            }
        }
    }

    cout<<ans<<endl;

    // approach 2;TC ---> 2(n*m) + O(log2n*m) ===> O(n*m)  ; SC ---> O(maxi ele+1)
    // finding median means no. with certain cnt of ele before it
    // we can store the freq of the ele before any ele in a prefix arr by first storing the freq of each ele in freq arr and then summing in a 
    // prefix arr, as if we direct add the ele before any ele by += colno. then there may be issues in case of duplications as we will add
    // to cnt twice for the same no.
    // from the mini ele to maxi ele we can check whether it is median ele based in ele before it in O(n*m) for ls and in O(log2n*m) for bs

    ans = 0;
    int maxi = -1, mini = 2001;

    for(int i = 0;i<n;i++){
        maxi = max(maxi, arr[i][m-1]);
        mini = min(mini, arr[i][0]);
    }

    // saving the freq of each ele 
    vector<int> freq(maxi+1, 0);

    for(int i =0 ;i<n;i++){
        for(int j =0;j<m;j++){
            freq[arr[i][j]]++;
        }
    }

    // cnt of ele before any ele
    vector<int> pre(maxi+1, 0);

    for(int i = mini;i<=maxi;i++){
        pre[i] = pre[i-1] + freq[i-1];
    }

    int low = mini, high = maxi;

    while(low<=high){
        int mid = low + (high - low)/2;
        int y = pre[mid];
        int start = y;
        int end = y + freq[mid] -1 ;

        if(x>=start && x<=end){
            ans = mid;
            break;
        }
        else if(pre[mid] <= x){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }

    cout<<ans<<endl;

    // approach 3;    TC --->O(log2(maxi - mini +1))  * O(nlog2m)    ;SC--->O(1)

    x = ((n*m) + 2 - 1)/2;

    low = mini ,high = maxi;
    while(low <= high){
        int mid = low + (high - low)/2;
        int large = 0;
        for(int i = 0;i<n;i++){
            // upper bound is giving me the ele lesser than equal to the ele, it is also having the cnt of itself
            large= large +  (int)(upper_bound(arr[i], arr[i] + m, mid) - arr[i]);
        }
        if(large >= x){
            ans = mid ;
            high = mid -1 ;
        }
        else{
            high = mid + 1;
        }
    }

    cout<<ans<<endl;

return 0 ;
}