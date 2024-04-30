#include <iostream>
using namespace std;

// void rev(int arr[] , int n){
//     int temp[n];
//     for(int i=0; i<n; i++){
//         temp[n-1-i]=arr[i];
//     }
//     for(int i=0; i<n; i++){
//         arr[i]=temp[i];
//     }
// }

void rev(int arr[] , int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void print(int arr[] , int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

int main(){
    int arr[5]={1,6,4,3,9};

    rev(arr, 5);
    print(arr, 5);

    return 0;
}