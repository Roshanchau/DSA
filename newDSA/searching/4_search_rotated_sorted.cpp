#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& arr, int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

/* my solution*/
// int search_rotated_sorted(vector<int>& arr, int n , int k){
//     int pivot=getPivot(arr, n);
//     int s=0,e=n-1, mid;
//     if(k>=arr[0]){
//         e=pivot;
//     }else{
//         s=pivot;
//     }
//     mid=s+(e-s)/2;
//     while(s<=e){
//         if(k==arr[mid]){
//             return mid;
//         }
//         if(k>arr[mid]){
//             s=mid+1;
//         }else{
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return -1;
// }



/* optiimized solution*/
int binarySearch(vector<int>& arr,int s , int e, int n, int key)
{
    int start = s;
    int end = e;
    // int mid = (start + end) / 2;
    /*optimization*/
    int mid= start+(end-start)/2;
    while (key != arr[mid] && start <= end)
    {
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid= start+(end-start)/2;
    }
    if (key == arr[mid])
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

int search_rotated_sorted(vector<int>& arr, int n , int k){
    int pivot=getPivot(arr, n);
    if(k>=arr[pivot] && k<=arr[n-1]){
        return binarySearch(arr, pivot, n-1, n , k);
    }else{
        return binarySearch(arr, 0, pivot-1 , n ,k);
    }
}


int main(){
    vector<int> arr={1};
    int index=search_rotated_sorted(arr, 1, 1);
    cout<<"this is the index: "<<index<<endl;
    return 0;
}