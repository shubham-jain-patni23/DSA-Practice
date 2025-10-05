#include<iostream>
#include<vector>
using namespace std;

//TC ---> in worst case when all the ele are duplicates then the time complexity may reach O(n) but if there are no duplicates then it is O(log2n)
//it gives the idx of the highest ele in the array , till now it works even when the ele are not distinct
int pivot(vector<int>&arr,int low, int high){
    //pivot may be in range[low , high) for a given array high is in the default case
    int ans = high;

    bool linearsearch = false;
    int nowlow , nowhigh;

    while(low < high){
        //if low is lesser than high than mid will always be lesser than high

        int mid = low + (high - low)/2;
        if(arr[mid + 1] < arr[mid]){      //pivot found
            ans = mid;
            break;
        }
        else if((arr[mid] < arr[high]) || (arr[mid] < arr[low])){          //pivot may be only in the left half
            high = mid;
        }
        else if((arr[low] < arr[mid]) || (arr[high] < arr[mid])){       //pivot may be only in the right half
            low = mid + 1;
        }
        else{                     //we encountered the condition of a[low] == a[mid] == a[high]
            linearsearch = true;
            nowlow = low ; 
            nowhigh = high;
            break;
        }
    }
    if(linearsearch){
        for(int i = nowlow ; i<nowhigh ;i++){
            if(arr[i] > arr[i+1]){
                ans =i;
                break;
            }
        }
    }

return ans;
}

//handling the edge case of a[low] == a[mid] == a[high]
int pivot2(vector<int>&arr,int low, int high){
    //pivot may be in range[low , high) for a given array high is in the default case
    int ans = high;

    while(low < high){
        //if low is lesser than high than mid will always be lesser than high

        int mid = low + (high - low)/2;
        if(arr[mid + 1] < arr[mid]){      //pivot found
            ans = mid;
            break;
        }
        else if((arr[mid] < arr[high]) || (arr[mid] < arr[low])){          //pivot may be only in the left half
            high = mid;
        }
        else if((arr[low] < arr[mid]) || (arr[high] < arr[mid])){       //pivot may be only in the right half
            low = mid + 1;
        }
        else{                     //we encountered the condition of a[low] == a[mid] == a[high]
            if(arr[low] > arr[low + 1]){
                ans = low; 
                break;
            }
            low++;
            high--;
        }
    }
return ans;
}

bool search(vector<int>& arr,int n,int target){

    int high = pivot(arr, 0, n - 1);
    int low = (high  + 1)  % n;

    if(target>=arr[low] && target <= arr[n-1]){
        low = low;
        high = n - 1;
    }
    else if(target>= arr[0] && target<=arr[high]){
        low = 0 ;
        high = high;
    }
    else{
        return false;
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
return false;
}

int main(){

    int n;
    cin>>n;

    int target;
    cin>>target;

    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    //approach 1; linear search ele ; TC ---> O(n)   ; SC---> O(1)

    //approach 2 ; we can recover the original array after writing one more array; TC ---> O(n)            SC ---> O(n)

    //approach 3 ;      TC ---> O(n) + O(log2n) = O(n)
    //we first found pivot which is the idx of the largest ele and then we divided the array into two subarrays 
    //one before the pivot and one after the pivot and searched in one of those subarrays


    int ans = search(arr, n , target);
    cout<<ans<<endl;

    //approach 4; search using binary search without using pivot ; TC---> O(log2n)  ; SC ---> O(1)
    //it works only when all the ele are distinct 
    //also here I approached from the point of view of ele eg. using conditions like if a[mid]==ele , a[mid] > ele , a[mid] < ele

    int low = 0 , high = n - 1;
    ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            ans = mid;
            break;
        }
        else if(arr[mid] > target){
            if(arr[mid] >= arr[low]){  //left half is sorted
                if(target>=arr[low]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(arr[mid] >= arr[low]){       //left half is sorted
                low = mid + 1;
            }
            else{
                if(target <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
        }
    }

    cout<<ans<<endl;

    //approach 4; search using binary search without using pivot ; TC---> O(log2n)  ; SC ---> O(1)
    //it works only when all the ele are distinct 
    //but I can also approach in the way to eleminate one of the halves as one of the half will surely will be sorted so on that half 
    //I can make a check for my ele and the remove one of the halves
    
    //approach 3 ; ---> seaching for the ele
    //approach 4 ; ---> eliminating one of the halves

    ans = -1;
    low = 0 , high = n-1;

    while(low<= high){
        int mid = low + (high - low)/2;

        if(arr[mid]==target){
            ans = mid ; 
            break;
        }
        //now I am making check which part is sorted but it is not more inituitive 
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target>=arr[mid] && target<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }

    cout<<ans<<endl;

    ans = -1;

    low = 0 , high = n-1;

    //approach 5 ; it works even when we duplicate ele ; TC --> avg case O(log2n) ; worst case ---> O(n/2) ; SC ---> O(1)

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target){
            ans= mid;
            break;
        }
        if(arr[low] < arr[mid]   || arr[high] < arr[mid]){        //left half is sorted
            if(target >= arr[low] && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(arr[mid] < arr[high] || arr[mid] < arr[low]){           //right half is sorted
            if(target>=arr[mid] && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        else{       //we encountered the condition of arr[low]==arr[mid]==arr[high]
            low = low +1;
            high = high -1;
        }
    }

    cout<<ans<<endl;

return 0;
}