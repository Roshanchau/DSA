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


int search_rotated_sorted(vector<int>& arr, int n , int k){
    int pivot=getPivot(arr, n);
    int s=0,e=n-1, mid;
    if(k>=arr[0]){
        e=pivot-1;
    }else{
        s=pivot;
    }
    mid=s+(e-s)/2;
    while(s<=e){
        if(k==arr[mid]){
            return mid;
        }
        if(k>arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> arr={12, 15, 18, 2, 4};
    int index=search_rotated_sorted(arr, 5, 2);
    cout<<"this is the index: "<<index<<endl;
    return 0;
}