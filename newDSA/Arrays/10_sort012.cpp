#include <iostream>
using namespace std;

// void sort012(int *arr, int n)
// {
//     int j = n - 1;
//     for (int i = 0; i < n; i++)
//     {
//         // sort 0 & 1
//         while (i < j)
//         {
//             if (arr[i] == 0)
//             {
//                 i++;
//             }
//             else if (arr[j] == 2)
//             {
//                 j--;
//             }
//             else if (arr[i] != 0 && arr[j] == 0)
//             {
//                 swap(arr[i], arr[j]);
//                 i++;
//             }
//             else if(arr[i]==1){
//                 i++;
//             }
//             else if (arr[i] == 2 && arr[j] == 1)
//             {
//                 swap(arr[i], arr[j]);
//                 i++;
//                 j--;
//             }
//         }
//     }
// }

// dutch flag algorithm using low , mid and high pointers

void sort012(int *arr ,int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid] , arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2 ,2 ,2 ,1 ,1 ,1 ,0};
    print(arr, 7);
    sort012(arr, 7);
    print(arr, 7);
    return 0;
}