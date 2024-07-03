#include <iostream>
#include <vector>
using namespace std;

// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
// {
//     int start = 0;
//     int end = n - 1;
//     int mid = start + (end - start) / 2;
//     int index, left, right;
//     while (k != arr[mid] && start <= end)
//     {
//         if (k < arr[mid])
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//         mid = start + (end - start) / 2;
//     }
//     if (k == arr[mid])
//     {
//         cout<<"hehe_mid: "<<mid<<endl;
//         index = mid;
//     }else{
//         return {-1, -1};
//     }
//     // left most index.
//     while (arr[index] == k)
//     {
//         left = index;
//         index--;
//     }
//     index = mid;
//     while (arr[index] == k)
//     {
//         right = index;
//         index++;
//     }
//     return {left, right};
// }

// optimize

// left occurance.
int firstOccurance(vector<int> &arr, int n , int k){
    cout<<endl;
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else if(k>arr[mid]){
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

// right occurance
int lastOccurance(vector<int> &arr, int n , int k){
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else if(k>arr[mid]){
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first= firstOccurance(arr, n ,k);
    p.second= lastOccurance(arr, n ,k);

    return p;

}

int main()
{
    vector<int> arr = {0 ,2 ,2 ,2 ,2, 2 ,2 ,2, 3 ,3 };
    pair<int, int> ans = firstAndLastPosition(arr, 10, 0);
    cout << "The first and last position is: " << ans.first << ", " << ans.second << endl;
    return 0;
}